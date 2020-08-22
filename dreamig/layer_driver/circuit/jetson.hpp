#pragma once
#include "layer_controller/ros_lib/ros.hpp"
#include "layer_controller/ros_lib/std_msgs/Float32MultiArray.hpp"
#include "layer_controller/ros_lib/std_msgs/Int32MultiArray.hpp"
//tx
#define TX_NUM 3
class Jetson{
public:
	Jetson();
	void callback(const std_msgs::Float32MultiArray& rx_msg);
	void read();
	void write(float odme_x,float odme_y,float yaw);
	bool connectionFlag();
	float getX();
	float getY();
private:
	float x = 0.f,y = 0.f;
	ros::NodeHandle nh;
	ros::Publisher pub;
	std_msgs::Float32MultiArray tx_msg;
	ros::Subscriber<std_msgs::Float32MultiArray,Jetson> sub;
};
