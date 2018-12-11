//
//  Greedy.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#include "Greedy.hpp"

Result Greedy::operator()(std::shared_ptr<Instance> instance) {
	//Prepare instace for processing, aka. clear previous Result
	Result result(instance);

	//Load task to least overworked Core
    for (int i=0; i<instance->getNumTasks(); i++)
		result.findshortest().addtask(instance->tasks[i]);

	result.calcmax();
	result.numberOfTasks = instance->getNumTasks();

	return result;
}