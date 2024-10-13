from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tangent_calc',
            namespace='tangent_publisher',
            executable='tangent_publisher',
            name='screen'
        ),
        Node(
            package='turtlesim',
            namespace='tangent_subscriber',
            executable='tangent_subscriber',
            name='screen'
        )
    ])