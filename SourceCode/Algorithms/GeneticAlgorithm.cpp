#include "GeneticAlgorithm.hpp"

#include "Greedy.hpp"
#include "LPTF.hpp"

#include <chrono>
	using namespace std::chrono;
#include <memory>
	using std::make_shared;
#include <vector>
	using std::vector;
#include <algorithm>
	using std::min;
	using std::swap;


void GeneticAlgorithm::operator()(Instance& instance, Result& result){
	auto start = high_resolution_clock::now();
	auto end = start + seconds(5);

	initializePopulation(instance);

	while(high_resolution_clock::now() < end){
		std::sort(population->begin(), population->end(), [&instance](Individual& a, Individual& b) { return a.valueFunction(instance) < b.valueFunction(instance); } );

		std::shared_ptr<std::vector<Individual>> newPopulation = make_shared<vector<Individual>>();
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

	std::cout << returnBestTime(instance) << "\n";
}	


void GeneticAlgorithm::initializePopulation(Instance& instance){
	population = make_shared<vector<Individual>>();

	for(int i = 0; i < destinatedPopulationSize-2; i++){
		population->push_back(Individual::makeRandom(instance.getNumTasks(), instance.getNumProcessors()));
	}

	Result result;
	LongestProcessingTimeFirst lptf;
	Greedy greedy;
	lptf(instance, result);
	population->push_back( (Individual)result );
	greedy(instance, result);
	population->push_back( (Individual)result );
}


int GeneticAlgorithm::returnBestTime(Instance& instance){
	int vauleOfBestSoFar = population->at(0).valueFunction(instance);
	for(auto& individual: *population){
		int valueOfIndividual = individual.valueFunction(instance);
		vauleOfBestSoFar = min(vauleOfBestSoFar, valueOfIndividual);
	}
	return vauleOfBestSoFar;
}


GeneticAlgorithm& GeneticAlgorithm::setPopulationSize(int x){ 
	if(x<2) throw std::string("Population size too small");
		destinatedPopulationSize = x;
	return *this;
}