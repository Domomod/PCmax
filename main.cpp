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
#include <vector>

#include "Instance.hpp"
#include "LoadingInstance.hpp"
#include "GeneratingInstance.hpp"
#include "Core.hpp"
#include "Result.hpp"

#include "Greedy.hpp"
#include "GeneticAlgorithm.hpp"

int main(){
	//Seed for srand
	srand( time (NULL) );
	//Create needed objects
    Instance instance;
	Result result;
	Greedy lptf;
    GeneratingInstance genInstance;

	GeneticAlgorithm geneticAlgorithm;

	//Load data
    genInstance.Build(instance);
   	std::cout << instance;

	lptf(instance, result);
	result.showyourself();

	geneticAlgorithm(instance, result);

    return 0;
}


