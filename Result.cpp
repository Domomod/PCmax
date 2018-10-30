#include "Result.h"

void Result::PrepareForProcessing(Instance& Ins){
	if(!Cores.empty())
		Cores.clear();
	max = 0;
	//Clear content if *this was already processed, vector actual capacity might not change
	Cores.resize(Ins.getNumProcessors(), Core());
};

Core& Result::findshortest(Instance& Ins){
	return *std::min_element(Cores.begin(), Cores.end());
};

void Result::calcmax(){
	for (auto core : Cores)
	if (core.gettime()>max) max=core.gettime();
};

void Result::showyourself(){
	for (auto core : Cores)
		core.showyourself();
	std::cout<<"Total time: "<<max<<"\n";
};
