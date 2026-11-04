cmake_minimum_required(VERSION 3.8)
project(aim_ros2_examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. 找到依赖包（与 package.xml 中的 <depend> 一一对应）
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)

# 2. 每个 .cpp 编译成一个可执行文件，并声明它用到的 ROS 依赖
# Jazzy 官方教程使用 ament_target_dependencies；Kilted 起改用 target_link_libraries
add_executable(hello_node src/hello_node.cpp)
ament_target_dependencies(hello_node rclcpp)

add_executable(talker src/talker.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/listener.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(add_two_ints_server src/add_two_ints_server.cpp)
ament_target_dependencies(add_two_ints_server rclcpp example_interfaces)

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
ament_target_dependencies(add_two_ints_client rclcpp example_interfaces)

add_executable(fibonacci_server src/fibonacci_server.cpp)
ament_target_dependencies(fibonacci_server rclcpp rclcpp_action example_interfaces)

add_executable(fibonacci_client src/fibonacci_client.cpp)
ament_target_dependencies(fibonacci_client rclcpp rclcpp_action example_interfaces)

# 3. 安装：ros2 run 只能找到安装到 lib/<包名> 下的可执行文件
install(TARGETS
  hello_node
  talker
  listener
  add_two_ints_server
  add_two_ints_client
  fibonacci_server
  fibonacci_client
  DESTINATION lib/${PROJECT_NAME}
)

# launch 文件和参数文件安装到 share/<包名>，ros2 launch 从这里查找
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
