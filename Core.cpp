//
//  Core.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#include "Core.h"
#include <iostream>
#include "Task.h"
#include "Utility.h"

void Core::showyourself(){
    std::cout<<CurrentProcessingTime<<" [units of time] were used for "<<MyTasks;
}

void Core::addtask(Task task){
    CurrentProcessingTime+=task.getLength();
    MyTasks.push_back(task);
}
