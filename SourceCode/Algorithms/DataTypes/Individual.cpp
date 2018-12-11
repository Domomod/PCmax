#include "Individual.hpp"
#include "SourceCode/Utility.hpp"

#include <cstdlib>
	using std::rand;
#include <vector>
	using std::vector;
#include <algorithm>
	using std::max;
	using std::min;

Individual::Individual(Result& result){
	usedInstance = result.getUsedInstance();
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

Individual Individual::makeOffspring(Individual& mother){
	Individual* individuals[2] = {this, &mother};
	Individual offspring(this->usedInstance);

	int numerOfTaks = coresAsignedToTasks.size();
	int startToUseOtherIndividualIdx = rand()%numerOfTaks;
	int fromFatherCount = rand()%numerOfTaks;
	int fromMotherCount=numerOfTaks-fromFatherCount;
	int endToUseOtherIndividualIdx = min(numerOfTaks, startToUseOtherIndividualIdx + fromFatherCount);
	fromFatherCount = endToUseOtherIndividualIdx - startToUseOtherIndividualIdx;


	for(int i = 0; i < coresAsignedToTasks.size(); i++){
		int randomnum=rand()%2;
		if((randomnum==1 && fromFatherCount>0)||fromMotherCount==0){
			offspring.coresAsignedToTasks.push_back( this->coresAsignedToTasks.at(i) );
			fromFatherCount--;
		}
		else{
			offspring.coresAsignedToTasks.push_back( mother.coresAsignedToTasks.at(i) );
			fromMotherCount--;
		}
	}

	return offspring;
}

Individual Individual::makeRandom(std::shared_ptr<Instance> instance){
	int numberOfTasks = instance->getNumTasks();
	int numerOfCores = instance->getNumProcessors();
	Individual outcome(instance, numberOfTasks);
	for(int i = 0; i < numberOfTasks; i++){
		int randomCore = rand() % numerOfCores;
		outcome.coresAsignedToTasks.at(i) = randomCore;
	}
	return outcome;
}

void Individual::mutate(){
	int numberOfTasks = coresAsignedToTasks.size();
	for(int i = 0; i < rand() % (int)(numberOfTasks/8); i++){
		int a = rand() % numberOfTasks;
		int b = rand() % numberOfTasks;
		std::swap( coresAsignedToTasks[a], coresAsignedToTasks[b] );
	}
}

int Individual::valueFunction(std::shared_ptr<Instance> myInstance){
	vector<int> Cores(myInstance->getNumProcessors(),0);
	int i = 0;
	int maxSoFar = 0;
	for(auto task : coresAsignedToTasks){
		Cores[task] += myInstance->getNthTaskLength(i);
		maxSoFar = max(maxSoFar,Cores[task]);
		i++;
	}
	return maxSoFar;
}

ostream& operator<<(ostream& out, Individual individual){
	out << individual.coresAsignedToTasks;
	return out;
}