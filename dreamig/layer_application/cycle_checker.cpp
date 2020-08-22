#include "./cycle_checker.hpp" //ver1.1
static_assert(CYCLE_CHECKER_HPP ==1.1,"CycleChecker version does not match. Check the latest version of the file on github.（CycleCheckerクラスのcppとhppのバージョンが一致しません。githubで最新バージョンのファイルを確認してください。）");
CycleChecker::CycleChecker(int cycle_ms){
	timeDiff = 0;
	oldTime = millis();
	maxDelay = 0;
	stdCycleTime = cycle_ms;
	delayFlag = false;
}

void CycleChecker::cycle(){
	int64_t time = millis();
	timeDiff = time - oldTime;
	if(timeDiff > stdCycleTime){
		delayFlag = true;
		if(timeDiff > maxDelay){
			maxDelay = timeDiff;
		}
	}
	oldTime = time;
}
