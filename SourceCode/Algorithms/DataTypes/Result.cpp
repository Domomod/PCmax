#include "Result.hpp"

void Result::Clear(){
	if(!Cores.empty())
		Cores.clear();
	max = 0;
}

void Result::Resize(int n){
	Cores.resize(n, Core());
}

void Result::PrepareForInstance(std::shared_ptr <Instance> instance){
	//Clear content if *this was already processed, vector actual capacity might not change
	Clear();
	
	//Set vector actual capacity to be able to store all Cores
	Resize(instance->getNumProcessors());
};

Core & Result::findshortest() {
	return *std::min_element(Cores.begin(), Cores.end(), [](Core& a,Core& b){ return a.gettime() < b.gettime();});
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
