//
//  Greedy.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#include "Greedy.hpp"

void Greedy::operator()(std::shared_ptr<Instance> instance, Result &result) {
	//Prepare instace for processing, aka. clear previous Result
	result.PrepareForInstance(instance);

	//Load task to least overworked Core
    for (int i=0; i<instance->getNumTasks(); i++)
		result.findshortest().addtask(instance->tasks[i]);

	result.calcmax();
	result.numerOfTasks = instance->getNumTasks();
}