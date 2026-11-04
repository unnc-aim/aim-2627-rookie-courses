# E08 Launch：一条命令同时启动 talker 和 listener，并从 YAML 加载参数
# 运行：ros2 launch aim_ros2_examples talker_listener.launch.py
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    params = os.path.join(
        get_package_share_directory('aim_ros2_examples'), 'config', 'talker.yaml')

    return LaunchDescription([
        Node(
            package='aim_ros2_examples',
            executable='talker',
            parameters=[params],
            output='screen',
        ),
        Node(
            package='aim_ros2_examples',
            executable='listener',
            output='screen',
        ),
    ])
