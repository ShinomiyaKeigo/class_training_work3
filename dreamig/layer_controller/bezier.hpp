#ifndef BEZIER_HPP
#define BEZIER_HPP

#include <math.h>
#include <vector>

#include "layer_driver/board/pin.hpp"
#include "layer_driver/base/serial.hpp"

class SecondBezier{//二次
public:
	SecondBezier();
	int setup();
	void setPoints(std::vector<std::vector<float>> xyPoints);
	void setPrametric(float parameter){this->parameter=parameter;};
	void calculate();
	std::vector<float>& getXt(){return xt;}
	std::vector<float>& getYt(){return yt;}

private:

	float a = 0;
	float b = 0;

	float c = 0;
	float d = 0;
	int parameter = 0;
	std::vector<std::vector<float>> xyPoints;
	std::vector<float>xt;
	std::vector<float>yt;
};

class ThirdBezier{//3次
public:
	ThirdBezier();
	int setup();
	void setPoints(std::vector<std::vector<float>> xyPoints);
	void setPrametric(float parameter){this->parameter=parameter;};
	void calculate();
	std::vector<float>& getXt(){return xt;}
	std::vector<float>& getYt(){return yt;}

private:

	float a = 0;
	float b = 0;
	float c = 0;

	float d = 0;
	float e = 0;
	float f = 0;
	int parameter = 0;
	std::vector<std::vector<float>> xyPoints;
	std::vector<float>xt;
	std::vector<float>yt;

};

class FourthBezier{//4次
public:
	FourthBezier();
	int setup();
	void setPoints(std::vector<std::vector<float>> xyPoints);
	void setPrametric(float parameter){this->parameter=parameter;};
	void calculate();
	std::vector<float>& getXt(){return xt;}
	std::vector<float>& getYt(){return yt;}

private:
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;
	float e = 0;

	float f = 0;
	float g = 0;
	float h = 0;
	float i = 0;
	float j = 0;
	int parameter = 0;
	std::vector<std::vector<float>> xyPoints;
	std::vector<float>xt;
	std::vector<float>yt;
};

#endif
