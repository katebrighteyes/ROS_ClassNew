cmake_minimum_required(VERSION 3.0.2)
project(test_ros_service)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  #actionlib_msgs
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  WordCount.srv
)

generate_messages(
  DEPENDENCIES
#  actionlib_msgs
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime #actionlib_msgs

)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


