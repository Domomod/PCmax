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
#include <SourceCode/Algorithms/LPTF.hpp>

#include "Domain/Instance.hpp"
#include "Domain/Building/LoadingInstance.hpp"
#include "Domain/Building/GeneratingInstance.hpp"
#include "Domain/Core.hpp"

#include "Algorithms/DataTypes/Result.hpp"
#include "Algorithms/GeneticAlgorithm.hpp"

#include "Utility.hpp"

int main(){
	//Seed for srand
	srand( time (NULL) );
	//Create needed objects
    LoadingInstance loadInstance;


	std::ifstream source50("Instances/m50");
    std::ifstream source50n200("Instances/m50n200");
    std::ifstream source50n1000("Instances/m50n1000");
    std::ifstream source10n200("Instances/m10n200");
    std::ifstream source25("Instances/m25");


	auto m50 = std::make_shared<Instance>( Instance() );
    auto m50n200 = std::make_shared<Instance>( Instance() );
    auto m50n1000 = std::make_shared<Instance>( Instance() );
    auto m10n200 = std::make_shared<Instance>( Instance() );
    auto m25 = std::make_shared<Instance>( Instance() );


	//Load data
	loadInstance.SetSource(source50);
	loadInstance.Build(*m50);
    loadInstance.SetSource(source50n200);
    loadInstance.Build(*m50n200);
    loadInstance.SetSource(source50n1000);
    loadInstance.Build(*m50n1000);
    loadInstance.SetSource(source10n200);
    loadInstance.Build(*m10n200);
    loadInstance.SetSource(source25);
    loadInstance.Build(*m25);


	GeneticAlgorithm geneticAlgorithm;
	geneticAlgorithm
			.setDueTimeInSeconds(5)
			.setStartingPopulationSize(100)
			.setIndivudualsAmountPassedToNextGeneration(20)
			.setX_CrossoversInN_Tries(0,10)
			.setX_MutationsInN_Tries(0,10)
			.setMaxMutations(2);


	//std::vector<int> test = {1, 5, 7, 10, 18, 36};
	//std::sort(test.begin(), test.end(), [](int a, int b){ return a < b; });
	//std::cout << test;

	//std::cout << "\nm50\t";
	//auto result1 = geneticAlgorithm(m50);
	//std::cout << "\n";
	//result1.showyourself();

	std::cout << "\nm50n200\t";
    auto result2 = geneticAlgorithm(m50n200);
    std::cout << "\n";
    result2.showyourself();

    std::cout << "\nm50n1000\t";
    auto result3 = geneticAlgorithm(m50n1000);
    std::cout << "\n";
    result3.showyourself();

    std::cout << "\nm10n200\t";
    auto result4 = geneticAlgorithm(m10n200);
    std::cout << "\n";
    result4.showyourself();

    std::cout << "\nm25\t";
    auto result5 = geneticAlgorithm(m25);
    std::cout << "\n";
    result5.showyourself();

    return 0;
}