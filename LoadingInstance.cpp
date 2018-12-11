#include "LoadingInstance.hpp"

void LoadingInstance::Build(Instance& instance){
	int numerOfTaks;
	(*in) >> instance.numProcessors >> numerOfTaks;
	if(!instance.tasks.empty()) instance.tasks.clear();
	//if previous Instance was already built, replace it's old content

	int val = 0;
	for(int i = 0; i < numerOfTaks; i++){
		(*in) >> val;
		instance.tasks.push_back(Task(val, i));
	}
}