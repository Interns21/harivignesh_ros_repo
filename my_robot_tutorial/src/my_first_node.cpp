#include<ros/ros.h>

int main( int argc , char **argv)
{
	ros::init(argc , argv , "my_first_cpp_node");
	ros::NodeHandle nh;
	ROS_INFO("The node has been started");
	
	ros::Rate rate(10);

	while (ros::ok()) 
	{
		ROS_INFO("Hello");

		rate.sleep();
	}
}
