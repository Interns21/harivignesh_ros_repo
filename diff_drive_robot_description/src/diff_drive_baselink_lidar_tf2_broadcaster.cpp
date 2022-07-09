#include <ros/ros.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>

int main(int argc, char **argv){
    ros::init(argc,argv,"baselink_lidartop_static_broadcaster");
    static tf2_ros::StaticTransformBroadcaster br;
    geometry_msgs::TransformStamped transformStamped;

    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "base_link";
    transformStamped.child_frame_id = "top";
    transformStamped.transform.translation.x = 0.467123;
    transformStamped.transform.translation.y = 0;
    transformStamped.transform.translation.z = 0.592528;

    tf2::Quaternion q;
    q.setRPY(0,0,0);
    transformStamped.transform.rotation.x = q.x();
    transformStamped.transform.rotation.y = q.y();
    transformStamped.transform.rotation.z = q.z();
    transformStamped.transform.rotation.w = q.w();

    br.sendTransform(transformStamped);
    ROS_INFO("Spinning until killed. Publishing %s to %s",
    transformStamped.header.frame_id.c_str(),transformStamped.child_frame_id.c_str());
    ros::spin();
    return 0;
}