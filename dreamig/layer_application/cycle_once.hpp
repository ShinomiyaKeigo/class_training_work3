#ifndef CYCLE_ONCE_HPP
#define CYCLE_ONCE_HPP 2.1

/*******************************************
 * CycleOnce ver2.1 2020/01/31
 * This program is timer
 *
 * [Note]
 * Execute cycle() only once in one control cycle
 * Prevent "cycle ()" from being executed many times in one control cycle
 *
 * [Author]
 * Yuta Uehara
 *
 * [Change history]
 * ver2.1 2020/01/31 add check() by Yuta Uehara
 * ver2.0 2020/01/30 large change by Yuta Uehara
 * ver1.0 2020/01/23 The first version by Yuta Uehara
 ******************************************/

class CycleOnce{
public:
	CycleOnce(){}
	bool check(){
		if(has_done){
			return false;
		}
		has_done=true;
		return true;

	}
	void restart(){has_done=false;}
	bool operator()(){return check();}
private:
	bool has_done=false;
};

#endif //CYCLE_CLASS
