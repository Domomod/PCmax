#include "LoadingInstance.h"

void LoadingInstance::Build(Instance& instance){
	(*in) >> instance.numProcessors >> instance.numTasks;
	if(!instance.tasks.empty()) instance.tasks.clear();
	//if previous Instance was already built, replace it's old content

	int val = 0;
	for(int i = 0; i < instance.numTasks; i++){
		(*in) >> val;
		instance.tasks.push_back(Task(val));
	}
}