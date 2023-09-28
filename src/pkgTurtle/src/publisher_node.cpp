#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <random>

double linear_x;
double angular_z;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> distribution(0.0, 1.0);

void setup_random_var();

int main(int argc, char**argv) {
    ros::init(argc, argv, "publisher_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>(
        "turtle1/cmd_vel", 1000);
    
    srand(time(0));
    ros::Rate rate(2);
    while(ros::ok()) {
        setup_random_var();
        geometry_msgs::Twist msg;
        msg.linear.x = linear_x;
        msg.angular.z = angular_z;
        pub.publish(msg);

        ros::spinOnce;
        rate.sleep();
    }

    return 0;
}

void setup_random_var() {
    linear_x = distribution(gen);
    angular_z = distribution(gen);
}