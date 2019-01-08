#include <iostream>

#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include "AbstractAlgorithm.hpp"
#include "SourceCode/Algorithms/DataTypes/Individual.hpp"

#include <memory>
#include <chrono>

class GeneticAlgorithm : public AbstractAlgorithm{
private:
	std::shared_ptr<std::vector<Individual>> population;

	struct Chance{
		int succeses;
		int tries;
		Chance(int suc=1, int tri=10) : succeses(suc), tries(tri){}
		bool didSucced(){ return (rand() % tries) < succeses; };
	};
	Chance mutationChance;
	Chance crossoverChance;

	std::chrono::seconds dueTime;

	int maxMutations;
	int startingPopulationSize;
	int rewriteToNextGenerationAmount;
protected:
public:
	GeneticAlgorithm(): startingPopulationSize(100), rewriteToNextGenerationAmount(10), dueTime(std::chrono::seconds(10)){};
	virtual ~GeneticAlgorithm(){};

	Result operator()(std::shared_ptr<Instance> instance);
	void initializePopulation(std::shared_ptr<Instance> instance);
	void selectBreedingMaterial();
	void breedNewPopulation();
	Individual & returnBestIndividual(std::shared_ptr<Instance> instance);

	GeneticAlgorithm& setDueTimeInSeconds(int x);
	GeneticAlgorithm& setStartingPopulationSize(int x);
    GeneticAlgorithm& setMaxMutations(int x);
	GeneticAlgorithm& setIndivudualsAmountPassedToNextGeneration(int x);
	GeneticAlgorithm& setX_MutationsInN_Tries(int x, int n);
	GeneticAlgorithm& setX_CrossoversInN_Tries(int x, int n);
};

#endif