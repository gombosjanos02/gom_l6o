cmake_minimum_required(VERSION 3.8)
project(gom_l6o)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)


add_executable(simple_sub_node src/tangent_subscriber.cpp)
ament_target_dependencies(simple_sub_node ${ament_dependencies})

add_executable(simple_pub_node src/tangent_publisher.cpp)
ament_target_dependencies(simple_pub_node ${ament_dependencies})


install(TARGETS
  simple_sub_node
  simple_pub_node
  DESTINATION lib/${PROJECT_NAME}
)


install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
