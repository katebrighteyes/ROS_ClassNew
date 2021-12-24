#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("camera/image", 1);

  //cv::Mat image = cv::imread(argv[1], cv::IMREAD_COLOR);
  //cv::Mat image = cv::imread("/home/opencv-mds/Documents/cat_2.jpg", cv::IMREAD_COLOR);
  //sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
  
  VideoCapture cap("/home/opencv-mds/Documents/run3.mp4");
	if (!cap.isOpened())
	{
		printf("Can't open the camera");
		return -1;
	}
  ros::Rate loop_rate(1);
  cv::Mat image;
  while (nh.ok()) {
    cap >> image;
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();   
    
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}

