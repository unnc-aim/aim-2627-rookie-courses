// E03 Subscriber：订阅 /chatter，每收到一条消息调用一次回调
// 运行：ros2 run aim_ros2_examples listener
// 重映射话题：ros2 run aim_ros2_examples listener --ros-args -r chatter:=my_chatter
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Listener : public rclcpp::Node
{
public:
  Listener()
  : Node("listener")
  {
    // 话题名和消息类型必须与发布者一致，QoS 必须兼容
    subscription_ = create_subscription<std_msgs::msg::String>(
      "chatter", 10,
      [this](const std_msgs::msg::String & msg) {
        RCLCPP_INFO(get_logger(), "Received: '%s'", msg.data.c_str());
      });
  }

private:
  // subscription 必须作为成员保存，否则构造函数结束后就停止接收
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Listener>());
  rclcpp::shutdown();
  return 0;
}
