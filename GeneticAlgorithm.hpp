#include <iostream>

#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include "AbstractAlgorithm.hpp"
#include "Individual.hpp"

#include <memory>

class GeneticAlgorithm : public AbstractAlgorithm{
private:
	std::shared_ptr<std::vector<Individual>> population;

	int destinatedPopulationSize;
protected:
public:
	GeneticAlgorithm(): destinatedPopulationSize(100){};
	virtual ~GeneticAlgorithm(){};

	void operator()(Instance&, Result&);
	void initializePopulation(Instance& instance);
	void selectBreedingMaterial();
	void breedNewPopulation();
	int returnBestTime(Instance& instance);

	GeneticAlgorithm& setPopulationSize(int x);
};

#endif