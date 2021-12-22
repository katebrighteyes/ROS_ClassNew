cmake_minimum_required(VERSION 2.8.3)
project(test_ros_service)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  actionlib_msgs
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  WordCount.srv
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
