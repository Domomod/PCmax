//
//  Greedy.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#include "Greedy.h"


Greedy::Greedy(Instance Ins){
    CoreNum=Ins.getNumProcessors();
    Cores = new Core[CoreNum];
    CoreWithShortestTime=&Cores[0];
    Tasks=Ins.tasks;
    TasksNum=Ins.getNumTasks();
}


void Greedy::dogreedstaff(){
    for (int i=0; i<TasksNum; i++)
    {CoreWithShortestTime->addtask(Tasks[i]);
        this->findshortest();
    }
    int max=0;
    for (int i=0; i<CoreNum;i++){
        Cores[i].showyourself();
        if (Cores[i].gettime()>max) max=Cores[i].gettime();
    }
    std::cout<<"Total time: "<<max<<"\n";
}


void Greedy::findshortest(){
    int min=Cores[0].gettime();
    CoreWithShortestTime=&Cores[0];
    for (int i=0; i<CoreNum;i++){
        if (Cores[i].gettime()<min){
            min=Cores[i].gettime();
            CoreWithShortestTime=&Cores[i];
        }
    }
}
