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

#include "Domain/Instance.hpp"
#include "Domain/Building/LoadingInstance.hpp"
#include "Domain/Building/GeneratingInstance.hpp"
#include "Domain/Core.hpp"
#include "Algorithms/DataTypes/Result.hpp"

#include "Algorithms/Greedy.hpp"
#include "Algorithms/GeneticAlgorithm.hpp"

int main(){
	//Seed for srand
	srand( time (NULL) );
	//Create needed objects
	Greedy lptf;
    LoadingInstance loadInstance;

	GeneticAlgorithm geneticAlgorithm;

	std::ifstream m50n1000("Instances/m50");

	auto instance = std::make_shared<Instance>( Instance() );

	//Load data
	loadInstance.SetSource(m50n1000);
	loadInstance.Build(*instance);
   	std::cout << *instance;

	Result result(instance);

	lptf(instance, result);

	result.showyourself();

	Individual test1 = (Individual) result;

	Result result2 = (Result) test1;

	result2.showyourself();

	geneticAlgorithm(instance, result);

    return 0;
}


