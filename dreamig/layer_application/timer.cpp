#include "layer_application/timer.hpp" 	//ver1.2
static_assert(TIMER_HPP==1.2,"Timer version does not match. Check the latest version of the file on github.（Timerクラスのcppとhppのバージョンが一致しません。githubで最新バージョンのファイルを確認してください。）");

void Timer::set(int64_t time, bool auto_reset){
	settedTime = time;
	startTime = millis();
	this->auto_reset=auto_reset;
}

bool Timer::check(){
	if(millis()-startTime >= settedTime){
		if(auto_reset) startTime=millis();
		return true;
	}
	return false;
}


