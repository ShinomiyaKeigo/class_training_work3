#include "layer_driver/circuit/lrf.hpp"

LRF::LRF()
:pub("/stm_data",&tx_msg),sub("/jetson_data",&LRF::callback,this){//ここはros::init(argc,argv,"~~~~")の~~~をsub("~~~",&LRFdata::messageCb,this)にかく
	nh.initNode();
	nh.advertise(pub);
	nh.subscribe(sub);
	tx_msg.data_length = DATA_NUM;
	tx_msg.data=(float*)malloc(sizeof(float)*DATA_NUM);
}

void LRF::callback(const std_msgs::Float32MultiArray& rx_msg){
	x = rx_msg.data[0];//LRFの観測値
	y = rx_msg.data[1];
}

void LRF::mainSend(int coat, int route, int point){
	tx_msg.data[0] = coat;
	tx_msg.data[1] = route;
	tx_msg.data[2] = point;
	pub.publish(&tx_msg);
}

void LRF::mainRecieve(){
	nh.spinOnce();
}
