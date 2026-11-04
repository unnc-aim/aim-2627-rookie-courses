# ROS 2 Jazzy 入门（C++）

> **系统要求**：Ubuntu 24.04 + ROS 2 Jazzy
>
> Jazzy 只为 Ubuntu 24.04 提供 deb 包。查资料时确认文档版本是 Jazzy：网上的 Humble（22.04）教程大部分仍适用，但个别 API 和环境变量已经变化。

面向已经学完 [Linux](../02-Linux/README.md) 和 [C++](../03-Cpp/README.md) 的同学，一次 3 小时。课上先用命令行观察运行中的系统，再读示例代码中的关键几行。

## 课前准备

按 [官方安装文档（Ubuntu deb 包）](https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html) 安装，跟着步骤走到 Next steps 之前。需要的包：

```bash
sudo apt install ros-jazzy-desktop ros-dev-tools
echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
```

自检：`printenv ROS_DISTRO` 输出 `jazzy`；`ros2 run demo_nodes_cpp talker` 和 `ros2 run demo_nodes_cpp listener` 在两个终端里能互相通信。

## 延伸阅读

- [ROS 2 Jazzy 官方文档](https://docs.ros.org/en/jazzy/index.html)：Tutorials → Beginner: CLI tools / Client libraries
- [鱼香 ROS《动手学 ROS 2》Jazzy 版](https://fishros.com/d2lros2/#/)
  - [节点介绍](https://fishros.com/d2lros2/#/jazzy/chapt2/get_started/1.ROS2%E8%8A%82%E7%82%B9%E4%BB%8B%E7%BB%8D)
  - [话题入门](https://fishros.com/d2lros2/#/jazzy/chapt3/get_started/1.ROS2%E8%AF%9D%E9%A2%98%E5%85%A5%E9%97%A8)
  - [服务入门](https://fishros.com/d2lros2/#/jazzy/chapt3/get_started/4.ROS2%E6%9C%8D%E5%8A%A1%E5%85%A5%E9%97%A8)

[返回Computing方向](../README.md)
