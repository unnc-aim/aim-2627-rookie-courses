// E01 最小节点：初始化 → 创建节点 → spin → 关闭
// 运行：ros2 run aim_ros2_examples hello_node
#include <memory>

#include "rclcpp/rclcpp.hpp"

int main(int argc, char ** argv)
{
  // 初始化 rclcpp，解析 --ros-args 等命令行参数
  rclcpp::init(argc, argv);

  // 创建一个名为 hello_node 的节点
  auto node = std::make_shared<rclcpp::Node>("hello_node");
  RCLCPP_INFO(node->get_logger(), "Hello from ROS 2 Jazzy!");

  // spin 让节点持续运行并处理回调，直到 Ctrl+C
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
