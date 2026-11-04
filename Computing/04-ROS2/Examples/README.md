# ROS 2 Jazzy C++ 示例

环境：Ubuntu 24.04 + ROS 2 Jazzy（`ros-jazzy-desktop` 与 `ros-dev-tools`）。

## 构建

`aim_ros2_examples` 是一个完整的 `ament_cmake` 包，链接到你的 workspace 即可构建：

```bash
git clone https://github.com/unnc-aim/aim-2627-rookie-courses.git ~/aim-2627
mkdir -p ~/ros2_ws/src
ln -s ~/aim-2627/Computing/04-ROS2/Examples/aim_ros2_examples ~/ros2_ws/src/

cd ~/ros2_ws
source /opt/ros/jazzy/setup.bash
rosdep install --from-paths src -y --ignore-src   # 第一次使用前先 sudo rosdep init && rosdep update
colcon build --symlink-install --packages-select aim_ros2_examples
source install/setup.bash
```

用软链接而不是复制，`git pull` 后重新构建就能拿到更新。想自己改着玩，就复制一份并改掉 `package.xml` 和 `CMakeLists.txt` 里的包名，避免与原包重名。

## 示例列表

| 编号 | 文件 | 可执行文件 | 内容 |
| --- | --- | --- | --- |
| E01 | [hello_node.cpp](aim_ros2_examples/src/hello_node.cpp) | `hello_node` | 最小节点：init → Node → spin → shutdown |
| E02 | [talker.cpp](aim_ros2_examples/src/talker.cpp) | `talker` | Publisher、定时器、参数 `prefix` / `period_ms` |
| E03 | [listener.cpp](aim_ros2_examples/src/listener.cpp) | `listener` | Subscriber、lambda 回调 |
| E04 | [add_two_ints_server.cpp](aim_ros2_examples/src/add_two_ints_server.cpp) | `add_two_ints_server` | Service server |
| E05 | [add_two_ints_client.cpp](aim_ros2_examples/src/add_two_ints_client.cpp) | `add_two_ints_client` | Service client，命令行传入两个整数 |
| E06 | [fibonacci_server.cpp](aim_ros2_examples/src/fibonacci_server.cpp) | `fibonacci_server` | Action server：feedback、取消 |
| E07 | [fibonacci_client.cpp](aim_ros2_examples/src/fibonacci_client.cpp) | `fibonacci_client` | Action client |
| E08 | [talker_listener.launch.py](aim_ros2_examples/launch/talker_listener.launch.py) + [talker.yaml](aim_ros2_examples/config/talker.yaml) | — | Launch 与 YAML 参数 |

构建配置见 [CMakeLists.txt](aim_ros2_examples/CMakeLists.txt) 和 [package.xml](aim_ros2_examples/package.xml)。

## 运行

每个新终端都要先 `source ~/ros2_ws/install/setup.bash`。

```bash
# E01
ros2 run aim_ros2_examples hello_node

# E02 + E03：两个终端
ros2 run aim_ros2_examples talker --ros-args -p period_ms:=200
ros2 run aim_ros2_examples listener
ros2 param set /talker prefix "RoboMaster"      # 第三个终端，运行时修改

# E04 + E05：先在一个终端启动 server，再在另一个终端发请求
ros2 run aim_ros2_examples add_two_ints_server
ros2 run aim_ros2_examples add_two_ints_client 5 6
ros2 service call /add_two_ints example_interfaces/srv/AddTwoInts "{a: 3, b: 9}"   # 也可以直接用命令行调用

# E06 + E07：同上，server 和 client 各占一个终端
ros2 run aim_ros2_examples fibonacci_server
ros2 run aim_ros2_examples fibonacci_client 10
ros2 action send_goal --feedback /fibonacci example_interfaces/action/Fibonacci "{order: 5}"   # 执行中按 Ctrl+C 会取消目标

# E08
ros2 launch aim_ros2_examples talker_listener.launch.py
```

## 说明

- `fibonacci_server` 只接受 `1 ≤ order ≤ 40`，其余目标会被拒绝。结果从 0、1 开始共 `order + 1` 个数，与官方教程一致，例如 `order = 5` 返回 `0 1 1 2 3 5`。
- 两个 client 成功时退出码为 0；参数错误、超时、目标被拒绝或失败时为 1。
- CMakeLists.txt 使用 Jazzy 官方教程的 `ament_target_dependencies`。从 Kilted 开始这个函数被弃用，改用 `target_link_libraries(talker rclcpp::rclcpp ${std_msgs_TARGETS})`；在 Jazzy 上两种写法都能用。
- 只用到 `std_msgs` 和 `example_interfaces` 里的现成接口。自定义 msg / srv 接口包留到后续课程。
