~/catkin_ws/src/

catkin_create_pkg test_topic_msg std_msgs rospy

cd ..

catkin_make

------------------------
cd ~/catkin_ws/src/test_topic_msg

mkdir msg

cd msg

gedit Complex.msg

------------------------
cd ~/catkin_ws/src/test_topic_msg

gedit CMakeLists.txt

gedit package.xml.

------------------------
cd ~/catkin_ws/src/test_topic_msg/src

gedit topic_publisher.py

gedit topic_subscriber.py


