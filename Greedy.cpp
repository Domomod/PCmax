//
//  Greedy.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#include "Greedy.h"

void Greedy::operator()(Instance& Ins, Result& Res){
	Res.PrepareForProcessing(Ins);

    for (int i=0; i<Ins.numTasks; i++)
    	Res.findshortest(Ins).addtask(Ins.tasks[i]);

	Res.calcmax();
    Res.showyourself();
}