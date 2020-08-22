#include "layer_driver/circuit/jetson.hpp"
Jetson::Jetson()
:pub("/stm_data",&tx_msg),sub("/jetson_data",&Jetson::callback,this){
	nh.initNode();
	nh.advertise(pub);
	nh.subscribe(sub);
	tx_msg.data_length = TX_NUM;
	tx_msg.data=(float*)malloc(sizeof(float)*TX_NUM);
}
void Jetson::callback(const std_msgs::Float32MultiArray& rx_msg){
	x = rx_msg.data[0];
	y = rx_msg.data[1];
}
void Jetson::read(){
	nh.spinOnce();
}
void Jetson::write(float odme_x,float odme_y,float yaw){
	tx_msg.data[0] = odme_x;
	tx_msg.data[1] = odme_y;
	tx_msg.data[2] = yaw;
	pub.publish(&tx_msg);
}
bool Jetson::connectionFlag(){
	return nh.connected();
}
float Jetson::getX(){
	return x;
}
float Jetson::getY(){
	return y;
}
