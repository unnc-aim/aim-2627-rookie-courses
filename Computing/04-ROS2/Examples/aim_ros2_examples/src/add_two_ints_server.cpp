// E04 Service Server：提供 /add_two_ints，收到 a、b 返回 a + b
// 运行：ros2 run aim_ros2_examples add_two_ints_server
// 命令行调用：ros2 service call /add_two_ints example_interfaces/srv/AddTwoInts "{a: 3, b: 9}"
#include <cinttypes>
#include <memory>

#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"

using AddTwoInts = example_interfaces::srv::AddTwoInts;

class AddTwoIntsServer : public rclcpp::Node
{
public:
  AddTwoIntsServer()
  : Node("add_two_ints_server")
  {
    service_ = create_service<AddTwoInts>(
      "add_two_ints",
      [this](
        const std::shared_ptr<AddTwoInts::Request> request,
        std::shared_ptr<AddTwoInts::Response> response) {
        // 服务回调应当很快返回：一次请求对应一次响应
        response->sum = request->a + request->b;
        RCLCPP_INFO(
          get_logger(), "Request: %" PRId64 " + %" PRId64 " = %" PRId64,
          request->a, request->b, response->sum);
      });
    RCLCPP_INFO(get_logger(), "Service /add_two_ints is ready");
  }

private:
  rclcpp::Service<AddTwoInts>::SharedPtr service_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddTwoIntsServer>());
  rclcpp::shutdown();
  return 0;
}
