#include "Result.hpp"
#include "Individual.hpp"

#include <algorithm>

Result::Result(std::shared_ptr<Instance> instance):longestProcessingTime(0){
	usedInstance = std::move(instance);
	Resize(usedInstance->getNumProcessors());
}

Result::Result(Individual individual){
	usedInstance = individual.getUsedInstance();
	Resize(usedInstance->getNumProcessors());

	int taskId = 0;
	for(auto& coreId : individual.getCoresAsignedToTasks()){
		Cores.at(coreId).addtask( usedInstance->getNthTask(taskId) );
		taskId++;
	}

	calcmax();
}

void Result::Clear(){
	if(!Cores.empty())
		Cores.clear();
	longestProcessingTime = 0;
}

void Result::Resize(int n){
	Cores.resize(n, Core());
}

Core & Result::findshortest() {
	return *std::min_element(Cores.begin(), Cores.end(), [](Core& a,Core& b){ return a.gettime() < b.gettime();});
};

void Result::calcmax(){
	for (auto core : Cores)
		longestProcessingTime=std::max(core.gettime(),longestProcessingTime);
};

void Result::showyourself(){
	for (auto core : Cores)
		core.showyourself();
	std::cout<<"Total time: "<<longestProcessingTime<<"\n";
};
