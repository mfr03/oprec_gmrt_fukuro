#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

void messageCallBack(const geometry_msgs::Twist::ConstPtr& msg) {
    ROS_INFO("Linear X Speed: %.2f", msg->linear.x);
    ROS_INFO("Angular Z Speed: %.2f", msg->angular.z);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "subscriber_node");
    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe("turtle1/cmd_vel", 10, messageCallBack);

    ros::spin();

    return 0;
}