#include "Individual.h"
#include "Utility.h"

#include <cstdlib>
	using std::rand;
#include <vector>
	using std::vector;
#include <algorithm>
	using std::max;
	using std::min;

Individual::Individual(Result& result){
	int numberOfTasks = result.getNumberOfTasks();

	coresAsignedToTasks.resize(numberOfTasks);

	int coreId = 0;
	for(auto core : result.Cores){
		for(auto task : core.getTasks()){
			coresAsignedToTasks.at(task.getId()) = coreId;
		}
		coreId++;
	}
}

Individual Individual::makeOffspring(Individual& other){
	Individual* individuals[2] = {this, &other};
	Individual offspring(coresAsignedToTasks.size());

	int numerOfTaks = coresAsignedToTasks.size();
	int startToUseOtherIndividualIdx = rand()%numerOfTaks;
	int offset = rand()%numerOfTaks/2;
	int endToUseOtherIndividualIdx = min(numerOfTaks, startToUseOtherIndividualIdx + offset);
	offset = endToUseOtherIndividualIdx - startToUseOtherIndividualIdx;

	for(int i = 0; i < coresAsignedToTasks.size(); i++){
		if(i < startToUseOtherIndividualIdx || i > endToUseOtherIndividualIdx){
			offspring.coresAsignedToTasks.at(i) = this->coresAsignedToTasks.at(i);
		}
		else{
			offspring.coresAsignedToTasks.at(i) = other.coresAsignedToTasks.at(i);
		}
	}
	return offspring;
}

Individual Individual::makeRandom(int numberOfTasks, int numerOfCores){
	Individual outcome(numberOfTasks);
	for(int i = 0; i < numberOfTasks; i++){
		int randomCore = rand() % numerOfCores;
		outcome.coresAsignedToTasks.at(i) = randomCore;
	}
	return outcome;
}

int Individual::valueFunction(Instance& myInstance){
	vector<int> Cores(myInstance.getNumProcessors(),0);
	int i = 0;
	int maxSoFar = 0;
	for(auto task : coresAsignedToTasks){
		Cores[task] += myInstance.getNthTaskLength(i);
		maxSoFar = max(maxSoFar,Cores[task]);
		i++;
	}
	return maxSoFar;
}

ostream& operator<<(ostream& out, Individual individual){
	out << individual.coresAsignedToTasks;
	return out;
}