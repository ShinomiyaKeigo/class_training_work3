#ifndef PID_HPP
#define PID_HPP

class Pid{
public:
	Pid();
	int setup(){return 0;};
	void cycle(){};
	void setGain(float kp, float ki, float kd, float div);
	void setKp(float kp){this->kp = kp;reset();}
	void setKi(float ki){this->ki = ki;reset();}
	void setKd(float kd){this->kd = kd;reset();}
	void setDiv(float div){this->div = div;reset();}
	void addGain(float kp, float ki, float kd){this->kp += kp;this->ki += ki;this->kd += kd;reset();}
	void reset();
	float control(float target, float operation);		//pidメイン処理
	float control(float diff){return control(diff,0);}
	float getKp(){return kp;}
	float getKi(){return ki;}
	float getKd(){return kd;}
	float getDiv(){return div;}
	float getKpSum(){return kpSum;}
	float getKiSum(){return kiSum;}
	float getKdSum(){return kdSum;}

private:
	float kp,ki,kd;
	float div;
	float kpSum,kiSum,kdSum;
	float oldDeviation;
	float old2Deviation;
};

#endif //PID_HPP
