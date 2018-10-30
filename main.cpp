//
//  main.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <cstdlib>
	using std::rand;
#include <ctime>

#include "Instance.h"
#include "LoadingInstance.h"
#include "GeneratingInstance.h"
#include "Core.h"
#include "Result.h"
#include "Greedy.h"
#include "LPTF.h"


int main(){
	//Seed for srand
	srand( time (NULL) );
	//Create needed objects
    Instance instance;
	Result result;
    GeneratingInstance genInstance;
    Greedy greedyAlgorithm;
	LongestProcessingTimeFirst lptf;
	
	//Load data
    genInstance.Build(instance);
    std::cout << instance;

	//Process data
	std::cout<<"\n\nGreedy Algorithm:\n\n";
    greedyAlgorithm(instance,result);
	std::cout<<"\n\nLongest Processing Time First Algorithm:\n\n";
	lptf(instance,result);
    
    return 0;
}


