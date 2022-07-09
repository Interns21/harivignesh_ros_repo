#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

#include <nav_msgs/Odometry.h>

void callbackfn(const nav_msgs::OdometryConstPtr& msg){
    tf2_ros::TransformBroadcaster br;
    geometry_msgs::TransformStamped transformStamped;

    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "odom";
    transformStamped.child_frame_id = "base_link";
    transformStamped.transform.translation.x = 
    msg->pose.pose.position.x;
    transformStamped.transform.translation.y = 
    msg->pose.pose.position.y;
    transformStamped.transform.translation.z = 
    msg->pose.pose.position.z;

    // tf2::Quaternion q;
    // q.setX(msg->pose.pose.orientation.x);
    // q.setY(msg->pose.pose.orientation.y);
    // q.setZ(msg->pose.pose.orientation.z);
    // q.setW(msg->pose.pose.orientation.w);
    transformStamped.transform.rotation.x = 
    msg->pose.pose.orientation.x;
    transformStamped.transform.rotation.y = 
    msg->pose.pose.orientation.y;
    transformStamped.transform.rotation.z = 
    msg->pose.pose.orientation.z;
    transformStamped.transform.rotation.w = 
    msg->pose.pose.orientation.w;

    br.sendTransform(transformStamped);
}

int main(int argc, char **argv){
    ros::init(argc,argv,"diff_drive_odom_base_link_transform");
    
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe("/odom",10,callbackfn);
    ros::spin();
    return 0;
    
}