//
//  Core.hpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include <iostream>
#include <vector>
#include "Task.h"

/*
A Core stores it's processing time and vector of Tasks
*/

class Core{
private:
    int CurrentProcessingTime;
    std::vector<Task> MyTasks;
public:
    Core(){CurrentProcessingTime=0;};
    ~Core(){};

    void addtask(Task task);
    void removetask(Task task);
    int gettime() const {return CurrentProcessingTime;};
    void showyourself();

	bool operator<(Core& other){return CurrentProcessingTime<other.CurrentProcessingTime;};
};


#endif /* Core_hpp */
