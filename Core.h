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

class Core{
private:
    int CurrentTime;
    std::vector<Task> MyTasks;
public:
    Core(){CurrentTime=0;};
    ~Core(){};

    void addtask(Task task);
    void removetask(Task task);
    int gettime() const {return CurrentTime;};
    void showyourself();

	bool operator<(Core& other){return CurrentTime<other.CurrentTime;};
};


#endif /* Core_hpp */
