#include "Result.hpp"

void Result::Clear(){
	if(!Cores.empty())
		Cores.clear();
	max = 0;
}

void Result::Resize(int n){
	Cores.resize(n, Core());
}

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
