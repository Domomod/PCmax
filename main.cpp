//
//  main.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//


#include <iostream>
#include <fstream>

#include "Instance.h"
#include "LoadingInstance.h"
#include "Core.h"
#include "Result.h"
#include "Greedy.h"
#include "LPTF.h"


int main(){
    Instance instance;
	Result result;
    LoadingInstance loadInstance;
    std::ifstream file("Instances/Instance1");
    Greedy greedyAlgorithm;
	LongestProcessingTimeFirst lptf;
	
	loadInstance.SetSource(file);
    loadInstance.Build(instance);
    std::cout << instance;

	std::cout<<"\n\nGreedy Algorithm:\n\n";
    greedyAlgorithm(instance,result);
	std::cout<<"\n\nLongest Processing Time First Algorithm:\n\n";
	lptf(instance,result);
    
    return 0;
}


