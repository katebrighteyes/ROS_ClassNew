cmake_minimum_required(VERSION 3.0.2)
project(test_ros_action)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  actionlib_msgs
)

 add_message_files(
   FILES
   Complex.msg

)

## Generate actions in the 'action' folder
add_action_files(
  FILES
  Timer.action
  Talk.action
)

generate_messages(
  DEPENDENCIES
  actionlib_msgs
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime actionlib_msgs

)


include_directories(
  ${catkin_INCLUDE_DIRS}
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)
