// E05 Service Client：等待 /add_two_ints 上线，发送一次请求，打印结果后退出
// 运行：ros2 run aim_ros2_examples add_two_ints_client 5 6
#include <chrono>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <memory>

#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"

using AddTwoInts = example_interfaces::srv::AddTwoInts;
using namespace std::chrono_literals;

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  // 去掉 --ros-args 部分，只保留用户自己的参数
  const auto args = rclcpp::remove_ros_arguments(argc, argv);
  if (args.size() != 3) {
    std::fprintf(stderr, "Usage: ros2 run aim_ros2_examples add_two_ints_client <a> <b>\n");
    rclcpp::shutdown();
    return 1;
  }

  auto node = std::make_shared<rclcpp::Node>("add_two_ints_client");
  auto client = node->create_client<AddTwoInts>("add_two_ints");

  // 1. 等待服务端上线
  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      // 按了 Ctrl+C。此时 ROS 已关闭，节点的 logger 无法再发布到 /rosout，
      // 所以改用不属于任何节点的 "rclcpp" logger
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service");
      rclcpp::shutdown();
      return 1;
    }
    RCLCPP_INFO(node->get_logger(), "Waiting for /add_two_ints ...");
  }

  // 2. 构造请求
  auto request = std::make_shared<AddTwoInts::Request>();
  request->a = std::atoll(args[1].c_str());
  request->b = std::atoll(args[2].c_str());

  // 3. 异步发送，再 spin 直到响应到达（最多等 5 秒）
  auto future = client->async_send_request(request);
  const bool ok = rclcpp::spin_until_future_complete(node, future, 5s) ==
    rclcpp::FutureReturnCode::SUCCESS;
  if (ok) {
    RCLCPP_INFO(
      node->get_logger(), "%" PRId64 " + %" PRId64 " = %" PRId64,
      request->a, request->b, future.get()->sum);
  } else {
    RCLCPP_ERROR(node->get_logger(), "Service call failed or timed out");
  }

  rclcpp::shutdown();
  return ok ? 0 : 1;
}
