// E06 Action Server：/fibonacci，每秒算出一项并发送 feedback，最后返回完整数列
// 运行：ros2 run aim_ros2_examples fibonacci_server
// 命令行发目标：ros2 action send_goal --feedback /fibonacci example_interfaces/action/Fibonacci "{order: 5}"
#include <exception>
#include <functional>
#include <memory>
#include <thread>
#include <vector>

#include "example_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using Fibonacci = example_interfaces::action::Fibonacci;
using GoalHandle = rclcpp_action::ServerGoalHandle<Fibonacci>;

class FibonacciServer : public rclcpp::Node
{
public:
  FibonacciServer()
  : Node("fibonacci_server")
  {
    using namespace std::placeholders;
    // 一个 action 需要三个回调：是否接受目标、是否允许取消、接受后怎样执行
    server_ = rclcpp_action::create_server<Fibonacci>(
      this, "fibonacci",
      std::bind(&FibonacciServer::handle_goal, this, _1, _2),
      std::bind(&FibonacciServer::handle_cancel, this, _1),
      std::bind(&FibonacciServer::handle_accepted, this, _1));
    RCLCPP_INFO(get_logger(), "Action /fibonacci is ready");
  }

  ~FibonacciServer() override
  {
    // 节点销毁前等所有执行线程结束，避免线程继续使用已经销毁的节点
    for (auto & worker : workers_) {
      worker.join();
    }
  }

private:
  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID &,
    std::shared_ptr<const Fibonacci::Goal> goal)
  {
    RCLCPP_INFO(get_logger(), "Goal request: order = %d", goal->order);
    if (goal->order < 1 || goal->order > 40) {
      return rclcpp_action::GoalResponse::REJECT;
    }
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandle>)
  {
    RCLCPP_INFO(get_logger(), "Cancel request received");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandle> goal_handle)
  {
    // 执行过程很长，放到新线程里，避免阻塞 executor
    // 线程保存在 workers_ 里，节点析构时 join
    workers_.emplace_back([this, goal_handle]() {execute(goal_handle);});
  }

  void execute(const std::shared_ptr<GoalHandle> goal_handle)
  {
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<Fibonacci::Feedback>();
    auto result = std::make_shared<Fibonacci::Result>();
    // 数列直接存在 feedback 里，每算出一项就把当前数列整个发出去
    auto & sequence = feedback->sequence;
    sequence = {0, 1};

    rclcpp::Rate rate(1);  // 1 Hz，方便观察 feedback
    // rclcpp::ok() 在 Ctrl+C 后变为 false，循环随之结束
    for (int i = 1; i < goal->order && rclcpp::ok(); ++i) {
      // 客户端请求取消，且 handle_cancel 接受后，is_canceling() 返回 true
      if (goal_handle->is_canceling()) {
        result->sequence = sequence;
        goal_handle->canceled(result);
        RCLCPP_INFO(get_logger(), "Goal canceled");
        return;
      }
      sequence.push_back(sequence[i] + sequence[i - 1]);
      goal_handle->publish_feedback(feedback);
      RCLCPP_INFO(get_logger(), "Feedback: %zu numbers", sequence.size());
      rate.sleep();
    }

    result->sequence = sequence;
    if (!rclcpp::ok()) {
      // Ctrl+C 时目标还没执行完。每个目标都必须以 succeed / abort / canceled 结束，
      // 否则 goal handle 销毁时会自动发送结果，而 Ctrl+C 后 action server 已经
      // 查不到这个目标，发送时抛出的异常没人捕获，程序直接崩溃。
      // abort() 发送结果时同样会抛异常，但目标已经进入终态，捕获后忽略即可
      try {
        goal_handle->abort(result);
      } catch (const std::exception &) {
      }
      return;
    }
    goal_handle->succeed(result);
    RCLCPP_INFO(get_logger(), "Goal succeeded");
  }

  rclcpp_action::Server<Fibonacci>::SharedPtr server_;
  std::vector<std::thread> workers_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FibonacciServer>());
  rclcpp::shutdown();
  return 0;
}
