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
	auto end = start + seconds(5);

	initializePopulation(instance);

	while(high_resolution_clock::now() < end){
		std::sort(population->begin(), population->end(), [&instance](Individual& a, Individual& b) { return a.valueFunction(instance) < b.valueFunction(instance); } );

		std::shared_ptr<std::vector<Individual>> newPopulation = std::make_shared<vector<Individual>>();
		int rewriteToNextPopulationCount = 20;
		
		if(rewriteToNextPopulationCount > population->size()) throw std::string("Wanted to rewrite more individuals to next population that there is individuals");

		for(int i = 0; i < rewriteToNextPopulationCount; i++){
			newPopulation->push_back(population->at(i));
		}

		int startingSize = newPopulation->size();
		for(int i = 0; i < startingSize; i++){
			Individual father = newPopulation->at(i);
			for(int j = 0; j < startingSize; j++){
				if(i != j){
					Individual& mother = newPopulation->at(j);
					Individual child = father.makeOffspring(mother);
					newPopulation->push_back(child);
				}
			}
		}

		for(Individual ind : *newPopulation){
			if(rand()%2 == 0)
				ind.mutate();
		}

		population.swap(newPopulation);
	}
	return (Result)returnBestIndividual(instance);
}	


void GeneticAlgorithm::initializePopulation(std::shared_ptr<Instance> instance){
	population = std::make_shared<vector<Individual>>();

	for(int i = 0; i < destinatedPopulationSize-2; i++){
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


GeneticAlgorithm& GeneticAlgorithm::setPopulationSize(int x){ 
	if(x<2) throw std::string("Population size too small");
		destinatedPopulationSize = x;
	return *this;
}