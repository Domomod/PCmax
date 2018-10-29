#ifndef RESULT_H
#define RESULT_H

#include "Core.h"
#include "Instance.h"
#include <vector>
	using std::vector;
#include <algorithm>

class Result{
	friend class Greedy;
private:
	vector<Core> Cores;
	int max;
protected:
public:
	Result():max(0){};
	void PrepareForProcessing(Instance& Ins){
		if(!Cores.empty())
			Cores.clear();
		max = 0;
		
		for(int i = 0; i < Ins.getNumProcessors(); i++ ) 		Cores.push_back(Core());
	};

	Core& findshortest(Instance& Ins){
		return *std::min_element(Cores.begin(), Cores.end());
	};

	void calcmax(){
		for (auto core : Cores)
		if (core.gettime()>max) max=core.gettime();
	};

	void showyourself(){
		for (auto core : Cores)
			core.showyourself();
		std::cout<<"Total time: "<<max<<"\n";
	};

};

#endif