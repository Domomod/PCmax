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
	//Create needed objects
    Instance instance;
	Result result;
    LoadingInstance loadInstance;
    std::ifstream file("Instances/Instance1");
    Greedy greedyAlgorithm;
	LongestProcessingTimeFirst lptf;
	
	//Load data
	loadInstance.SetSource(file);
    loadInstance.Build(instance);
    std::cout << instance;

	//Process data
	std::cout<<"\n\nGreedy Algorithm:\n\n";
    greedyAlgorithm(instance,result);
	std::cout<<"\n\nLongest Processing Time First Algorithm:\n\n";
	lptf(instance,result);
    
    return 0;
}


