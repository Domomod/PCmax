#include "Result.h"

void Result::Clear(){
	if(!Cores.empty())
		Cores.clear();
	max = 0;
}

void Result::Resize(int n){
	Cores.resize(n, Core());
}

void Result::PrepareForInstance(Instance& Ins){
	//Clear content if *this was already processed, vector actual capacity might not change
	Clear();
	
	//Set vector actual capacity to be able to store all Cores
	Resize(Ins.getNumProcessors());
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
