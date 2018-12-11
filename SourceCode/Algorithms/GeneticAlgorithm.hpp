#include <iostream>

#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include "AbstractAlgorithm.hpp"
#include "SourceCode/Algorithms/DataTypes/Individual.hpp"

#include <memory>

class GeneticAlgorithm : public AbstractAlgorithm{
private:
	std::shared_ptr<std::vector<Individual>> population;

	int destinatedPopulationSize;
protected:
public:
	GeneticAlgorithm(): destinatedPopulationSize(100){};
	virtual ~GeneticAlgorithm(){};

	void operator()(std::shared_ptr<Instance> instance, Result &result);
	void initializePopulation(std::shared_ptr<Instance> instance);
	void selectBreedingMaterial();
	void breedNewPopulation();
	int returnBestTime(std::shared_ptr<Instance> instance);

	GeneticAlgorithm& setPopulationSize(int x);
};

#endif