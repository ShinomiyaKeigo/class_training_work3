#include "dreamig/layer_controller/bezier.hpp"
SecondBezier::SecondBezier(){}

int SecondBezier::setup(){return 0;}

void SecondBezier::setPoints(std::vector<std::vector<float>> xyPoints){
	this->xyPoints=xyPoints;
	//［行数］×［列数」
	a =    xyPoints[0][0]-2*xyPoints[1][0]+xyPoints[2][0];
	b = -2*xyPoints[0][0]+2*xyPoints[1][0];

	c =    xyPoints[0][1]-2*xyPoints[1][1]+xyPoints[2][1];
	d = -2*xyPoints[0][1]+2*xyPoints[1][1];
}

void SecondBezier::calculate(){
	for (int i = 0;  i <= parameter; i++){
		float t = (float)i/parameter;
		float x = a*t*t + b*t + xyPoints[0][0];
		float y = c*t*t + d*t + xyPoints[0][1];

		xt.push_back(x);
		yt.push_back(y);
	}
}
ThirdBezier::ThirdBezier(){};

int ThirdBezier::setup(){return 0;}

void ThirdBezier::setPoints(std::vector<std::vector<float>> xyPoints){
	this->xyPoints=xyPoints;
	//［行数］×［列数」
	a =   -xyPoints[0][0]+3*xyPoints[1][0]-3*xyPoints[2][0]+xyPoints[3][0];
	b =  3*xyPoints[0][0]-6*xyPoints[1][0]+3*xyPoints[2][0];
	c = -3*xyPoints[0][0]+3*xyPoints[1][0];

	d =   -xyPoints[0][1]+3*xyPoints[1][1]-3*xyPoints[2][1]+xyPoints[3][1];
	e =  3*xyPoints[0][1]-6*xyPoints[1][1]+3*xyPoints[2][1];
	f = -3*xyPoints[0][1]+3*xyPoints[1][1];
}

void ThirdBezier::calculate(){
	for (int i = 0;  i <= parameter; i++){
		float t = (float)i/parameter;
		float x = a*t*t*t + b*t*t + c*t + xyPoints[0][0];
		float y = d*t*t*t + e*t*t + f*t + xyPoints[0][1];
		//printf("%f    %f    %f\n", x, y, t);
		xt.push_back(x);
		yt.push_back(y);
	}
}

FourthBezier::FourthBezier(){}

int FourthBezier::setup(){return 0;}

void FourthBezier::setPoints(std::vector<std::vector<float>> xyPoints){
	this->xyPoints=xyPoints;
	//[行数]×[列数]
	a =    xyPoints[0][0]- 4*xyPoints[1][0]+ 6*xyPoints[2][0]-4*xyPoints[3][0]+xyPoints[4][0];
	b = -4*xyPoints[0][0]+12*xyPoints[1][0]-12*xyPoints[2][0]+4*xyPoints[3][0];
	c =  6*xyPoints[0][0]-12*xyPoints[1][0]+ 6*xyPoints[2][0];
	d = -4*xyPoints[0][0]+ 4*xyPoints[1][0];

	e =    xyPoints[0][1]- 4*xyPoints[1][1]+ 6*xyPoints[2][1]-4*xyPoints[3][1]+xyPoints[4][1];
	f = -4*xyPoints[0][1]+12*xyPoints[1][1]-12*xyPoints[2][1]+4*xyPoints[3][1];
	g =  6*xyPoints[0][1]-12*xyPoints[1][1]+ 6*xyPoints[2][1];
	h = -4*xyPoints[0][1]+ 4*xyPoints[1][1];
}

void FourthBezier::calculate(){
	for (int i = 0;  i <= parameter; i++){
		float t = (float)i/parameter;
		float x = a*t*t*t*t + b*t*t*t + c*t*t + d*t + xyPoints[0][0];
		float y = e*t*t*t*t + f*t*t*t + g*t*t + h*t + xyPoints[0][1];
		//printf("%f    %f    %f\n", x, y, t);
		xt.push_back(x);
		yt.push_back(y);
	}
}
