from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gom_l6o',
            namespace='tangent_publisher',
            executable='simple_pub_node',
            name='tangent_publisher_node'
        ),
        Node(
            package='gom_l6o',
            namespace='tangent_subscriber',
            executable='simple_sub_node',
            name='tangent_subscriber_node'
        )
    ])
