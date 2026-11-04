// E07 Action Client：发送一个目标，打印 feedback 和最终结果后退出
// 运行：ros2 run aim_ros2_examples fibonacci_client 10
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

#include "example_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using Fibonacci = example_interfaces::action::Fibonacci;
using GoalHandle = rclcpp_action::ClientGoalHandle<Fibonacci>;
using namespace std::chrono_literals;

std::string join(const std::vector<int32_t> & sequence)
{
  std::string text;
  for (auto number : sequence) {
    text += std::to_string(number) + " ";
  }
  return text;
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  // 去掉 --ros-args 部分；不传参数时 order 默认为 10
  const auto args = rclcpp::remove_ros_arguments(argc, argv);
  const int order = args.size() > 1 ? std::atoi(args[1].c_str()) : 10;

  auto node = std::make_shared<rclcpp::Node>("fibonacci_client");
  auto client = rclcpp_action::create_client<Fibonacci>(node, "fibonacci");

  // 1. 等待 action server 上线，最多 10 秒
  if (!client->wait_for_action_server(10s)) {
    RCLCPP_ERROR(node->get_logger(), "Action server /fibonacci not available");
    rclcpp::shutdown();
    return 1;
  }

  // 2. 注册回调。三类回调分别对应：目标是否被接受、执行中的反馈、最终结果
  bool succeeded = false;
  auto options = rclcpp_action::Client<Fibonacci>::SendGoalOptions();
  options.goal_response_callback =
    [node](const GoalHandle::SharedPtr & goal_handle) {
      // goal_handle 为空表示服务端拒绝了目标，不会再有 feedback 和 result
      if (!goal_handle) {
        RCLCPP_ERROR(node->get_logger(), "Goal rejected");
        rclcpp::shutdown();
      } else {
        RCLCPP_INFO(node->get_logger(), "Goal accepted");
      }
    };
  options.feedback_callback =
    [node](GoalHandle::SharedPtr, const std::shared_ptr<const Fibonacci::Feedback> feedback) {
      RCLCPP_INFO(node->get_logger(), "Feedback: %s", join(feedback->sequence).c_str());
    };
  options.result_callback =
    [node, &succeeded](const GoalHandle::WrappedResult & result) {
      // result.code 是目标的最终状态，如 SUCCEEDED / ABORTED / CANCELED
      if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
        succeeded = true;
        RCLCPP_INFO(node->get_logger(), "Result: %s", join(result.result->sequence).c_str());
      } else {
        RCLCPP_ERROR(node->get_logger(), "Goal did not succeed");
      }
      rclcpp::shutdown();  // 让下面的 spin 返回
    };

  // 3. 异步发送目标，然后 spin 处理回调，直到某个回调调用 rclcpp::shutdown() 或按下 Ctrl+C
  Fibonacci::Goal goal;
  goal.order = order;
  RCLCPP_INFO(node->get_logger(), "Sending goal: order = %d", order);
  client->async_send_goal(goal, options);

  rclcpp::spin(node);
  return succeeded ? 0 : 1;
}
