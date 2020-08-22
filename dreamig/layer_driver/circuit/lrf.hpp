//2019/8/1 Kawasumi Ren
#pragma once

#include "layer_controller/ros_lib/ros.hpp"
#include "layer_controller/ros_lib/std_msgs/Float32MultiArray.hpp"

#define DATA_NUM 3

class LRF{
public:
	LRF();
	void callback(const std_msgs::Float32MultiArray& rx_msg);
	void mainSend(int coat, int route, int point);
	void mainRecieve();
	float getX(){return x;};
	float getY(){return y;};

private:
	float x,y;
	ros::NodeHandle nh;
	ros::Publisher pub;
	std_msgs::Float32MultiArray tx_msg;
	ros::Subscriber<std_msgs::Float32MultiArray,LRF> sub;
};
