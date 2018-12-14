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
#include <ctime>
#include <vector>

#include "Domain/Instance.hpp"
#include "Domain/Building/LoadingInstance.hpp"
#include "Domain/Building/GeneratingInstance.hpp"
#include "Domain/Core.hpp"

#include "Algorithms/DataTypes/Result.hpp"
#include "Algorithms/GeneticAlgorithm.hpp"

int main(){
	//Seed for srand
	srand( time (NULL) );
	//Create needed objects
    LoadingInstance loadInstance;


	std::ifstream m50("Instances/m50");


	auto instance = std::make_shared<Instance>( Instance() );

	//Load data
	loadInstance.SetSource(m50);
	loadInstance.Build(*instance);
   	std::cout << *instance;

	GeneticAlgorithm geneticAlgorithm;
	geneticAlgorithm
			.setDueTimeInSeconds(15)
			.setStartingPopulationSize(1000)
			.setIndivudualsAmountPassedToNextGeneration(100)
			.setX_CrossoversInN_Tries(7,10)
			.setX_MutationsInN_Tries(1,40);

	auto result = geneticAlgorithm(instance);

	result.showyourself();

    return 0;
}