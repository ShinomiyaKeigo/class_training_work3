#ifndef LIBRARY_UE_HPP
#define LIBRARY_UE_HPP 1.0

/*******************************************
 * library_ue ver1.0 2020/02/05
 * useful function and class
 * [Dependency]
 *
 * [Note]
 *
 * [Author]
 * Yuta Uehara
 *
 * [Change history]
 * ver1.0 2019/10/20 The first version
 ******************************************/
#include <initializer_list>
#include <functional>

namespace lib_ue{

template<class T1, class ...T2>
T1 max(T1 arg1,T2... arg2){
	T1 max_value = arg1;
	std::initializer_list<T1> list = {arg2...};
	for(const auto value : list){
		if(value > max_value){
			max_value = value;
		}
	}
	return max_value;
}

template<class T1, class ...T2>
T1 	signedAbsMax(T1 arg1,T2... arg2){
	T1 max_value = arg1;
	std::initializer_list<T1> list = {arg2...};
	for(const auto value : list){
		if(abs(value) > abs(max_value)){
			max_value = value;
		}
	}
	return max_value;
}

template<class T1, class ...T2>
T1 	unsignedAbsMax(T1 arg1,T2... arg2){
	return abs(signedAbsMax(arg1,arg2...));
}

template<class T1, class ...T2>
T1 min(T1 arg1,T2... arg2){
	T1 min_value = arg1;
	std::initializer_list<T1> list = {arg2...};
	for(const auto value : list){
		if(value < min_value){
			min_value = value;
		}
	}
	return min_value;
}

template<class T1, class ...T2>
T1 	signedAbsMin(T1 arg1,T2... arg2){
	T1 min_value = abs(arg1);
	std::initializer_list<T1> list = {arg2...};
	for(const auto value : list){
		if(abs(value) < abs(min_value)){
			min_value = value;
		}
	}
	return min_value;
}

template<class T1, class ...T2>
T1 	unsignedAbsMin(T1 arg1,T2... arg2){
	return abs(signedAbsMin(arg1,arg2...));
}

template<class T>
T constrain(T value, T min, T max){
	if(value > max) return max;
	else if(value < min) return min;
	return value;
}

template<class T>
class Change{
public:
	Change(T init):old_value(init){}
	bool operator()(T value){
		if(value != old_value){
			old_value = value;
			return true;
		}
		else{
			old_value = value;
			return false;
		}
	}
private:
	T old_value;
};

class UpEdge{
public:
	UpEdge(bool init):old_value(init){}
	bool operator()(bool value){
		if(value && !old_value){
			old_value = value;
			return true;
		}
		else{
			old_value = value;
			return false;
		}
	}
private:
	bool old_value;	
};

class DownEdge{
public:
	DownEdge(bool init):old_value(init){}
	bool operator()(bool value){
		if(!value && old_value){
			old_value = value;
			return true;
		}
		else{
			old_value = value;
			return false;
		}
	}
private:
	bool old_value;
};

}
#endif //LIBRARY_UE_HPP
