//
//  Greedy.hpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#ifndef Greedy_hpp
#define Greedy_hpp

#include <stdio.h>
#include "Core.h"
#include "Instance.h"
class Greedy{
private:
    Core *Cores; //i tak raczej w trakcie nie zmienimy ich ilości
    Core *CoreWithShortestTime;
    std::vector<Task> Tasks;
    int CoreNum;
    int MaxTime;
    int TasksNum;
public:
    Greedy(Instance Ins);
    ~Greedy(){};
    void findshortest();
    void dogreedstaff();
};


#endif /* Greedy_hpp */
