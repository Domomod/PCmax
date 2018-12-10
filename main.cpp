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
#include "Individual.h"

int main(){
	//Seed for srand
	srand( time (NULL) );
	//Create needed objects
    Instance instance;
	Result result1, result2;
    GeneratingInstance genInstance;
    Greedy greedyAlgorithm;
	LongestProcessingTimeFirst lptf;

	//Load data
    genInstance.Build(instance);
    std::cout << instance;

	//Process data
	std::cout<<"\n\nGreedy Algorithm:\n\n";
    greedyAlgorithm(instance,result1);
	std::cout<<"\n\nLongest Processing Time First Algorithm:\n\n";
	lptf(instance,result2);

	//Individual;
	Individual individual1(result1);
	Individual individual2(result2);

	std::cout << individual1.valueFunction(instance) << "\n";
	std::cout << individual2.valueFunction(instance) << "\n";

	Individual individual3 = individual1.makeOffspring(individual2);
	std::cout << individual3.valueFunction(instance) << "\n";
    
    return 0;
}


