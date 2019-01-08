#include "GeneticAlgorithm.hpp"

#include "Greedy.hpp"
#include "LPTF.hpp"

#include <chrono>
	using namespace std::chrono;
#include <memory>
#include <vector>
#include <algorithm>


Result GeneticAlgorithm::operator()(std::shared_ptr<Instance> instance) {
	auto start = high_resolution_clock::now();
	auto end = start + dueTime;

	int bestValueSoFar = -1;

	initializePopulation(instance);

	while(high_resolution_clock::now() < end){
		std::sort(population->begin(), population->end(), [&bestValueSoFar, &instance](Individual& a, Individual& b) {
			int aValue = a.valueFunction(instance);
			int bValue = b.valueFunction(instance);

			if (bestValueSoFar == -1 || aValue < bestValueSoFar || bValue < bestValueSoFar) {
				bestValueSoFar = std::min(aValue, bValue);
			}


			return aValue < bValue;
		} );

		std::shared_ptr<std::vector<Individual>> newPopulation = std::make_shared<vector<Individual>>();

		if(rewriteToNextGenerationAmount > population->size()) throw std::string("Wanted to rewrite more individuals to next population that there is individuals");

		for(int i = 0; i < rewriteToNextGenerationAmount; i++){
			newPopulation->push_back(population->at(i));
		}

		int startingSize = newPopulation->size();
		for(int i = 0; i < startingSize; i++){
			Individual father = newPopulation->at(i);
			for(int j = 0; j < startingSize; j++){
				if(i != j && mutationChance.didSucced()){
					Individual& mother = newPopulation->at(j);
					Individual child1 = father.makeOffspring(mother);
					Individual child2 = father.makeOffspring2(mother);
					//newPopulation->push_back(child1);
					//newPopulation->push_back(child2);
				}
			}
		}


		for(Individual ind : *newPopulation){
			//if(mutationChance.didSucced())
			//	ind.mutate(maxMutations);
		}

		population.swap(newPopulation);
	}
	std::cout << bestValueSoFar;

	std::cout << "\n" << returnBestIndividual(instance).valueFunction(instance);
	auto test1 = (Result)returnBestIndividual(instance);
	auto test2 = (Individual)test1;
	std::cout << "\n" << test2.valueFunction(instance);


	return (Result)returnBestIndividual(instance);
}	


void GeneticAlgorithm::initializePopulation(std::shared_ptr<Instance> instance){
	population = std::make_shared<vector<Individual>>();

	for(int i = 0; i < startingPopulationSize-2; i++){
		population->push_back(Individual::makeRandom(instance));
	}

	LongestProcessingTimeFirst lptf;
	Greedy greedy;
	auto lptfResult = lptf(instance);
	population->push_back( (Individual)lptfResult );
	auto greedyResult = greedy(instance);
	population->push_back( (Individual)greedyResult );
}


Individual & GeneticAlgorithm::returnBestIndividual(std::shared_ptr<Instance> instance){
	int vauleOfBestSoFar = population->at(0).valueFunction(instance);
	Individual *bestSoFar = &(population->at(0));

	for(auto& individual: *population){
		int valueOfIndividual = individual.valueFunction(instance);
		if(valueOfIndividual < vauleOfBestSoFar){
			vauleOfBestSoFar = valueOfIndividual;
			bestSoFar = &individual;
		}
	}
	return *bestSoFar;
}


GeneticAlgorithm& GeneticAlgorithm::setDueTimeInSeconds(int x){
	if(x<2) throw std::string("Population size too small");
		dueTime = std::chrono::seconds(x);
	return *this;
}


GeneticAlgorithm& GeneticAlgorithm::setStartingPopulationSize(int x){
	if(x<2) throw std::string("Population size too small");
		startingPopulationSize = x;
	return *this;
}


GeneticAlgorithm& GeneticAlgorithm::setMaxMutations(int x){
	maxMutations = x;
	return  *this;
};


GeneticAlgorithm& GeneticAlgorithm::setIndivudualsAmountPassedToNextGeneration(int x){
	if(x<2) throw std::string("Population size too small");
		rewriteToNextGenerationAmount = x;
	return *this;
}


GeneticAlgorithm& GeneticAlgorithm::setX_MutationsInN_Tries(int x, int n){
	mutationChance.succeses = x;
	mutationChance.tries = n;
	return *this;
}


GeneticAlgorithm& GeneticAlgorithm::setX_CrossoversInN_Tries(int x, int n){
	crossoverChance.succeses = x;
	crossoverChance.tries = n;
	return *this;
}