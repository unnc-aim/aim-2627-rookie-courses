// E02 Publisher：用定时器周期性地向 /chatter 发布 std_msgs/msg/String
// 运行：ros2 run aim_ros2_examples talker
// 带参数运行：ros2 run aim_ros2_examples talker --ros-args -p prefix:=Hi -p period_ms:=100
#include <chrono>
#include <cinttypes>
#include <cstdint>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Talker : public rclcpp::Node
{
public:
  Talker()
  : Node("talker")
  {
    // 声明参数并给出默认值。prefix 可以在运行时用 ros2 param set 修改
    declare_parameter<std::string>("prefix", "Hello ROS 2");
    // period_ms 只在启动时读取一次，修改后需要重启节点
    // 整数参数在 ROS 2 中统一是 64 位整数
    auto period_ms = declare_parameter<std::int64_t>("period_ms", 500);
    if (period_ms <= 0) {
      RCLCPP_WARN(get_logger(), "period_ms must be positive, using 500");
      period_ms = 500;
    }

    // 话题名 chatter，消息类型 String，QoS 历史深度 10
    publisher_ = create_publisher<std_msgs::msg::String>("chatter", 10);

    // 每 period_ms 毫秒调用一次 on_timer
    timer_ = create_wall_timer(
      std::chrono::milliseconds(period_ms),
      [this]() {on_timer();});

    RCLCPP_INFO(get_logger(), "Publishing on /chatter every %" PRId64 " ms", period_ms);
  }

private:
  void on_timer()
  {
    std_msgs::msg::String msg;
    msg.data = get_parameter("prefix").as_string() + ": " + std::to_string(count_++);
    publisher_->publish(msg);
    RCLCPP_INFO(get_logger(), "Published: '%s'", msg.data.c_str());
  }

  // publisher 和 timer 必须作为成员保存，离开作用域就会被销毁
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  std::uint64_t count_ = 0;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}
