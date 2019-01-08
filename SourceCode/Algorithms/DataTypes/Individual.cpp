#include "Individual.hpp"
#include "SourceCode/Utility.hpp"

#include <cstdlib>
	using std::rand;
#include <vector>
	using std::vector;
#include <stack>
	using std::stack;
#include <algorithm>
	using std::max;
	using std::min;

Individual::Individual(int size){
	coresAsignedToTasks.resize(size);
}

Individual::Individual(std::shared_ptr<Instance> instance, unsigned long size){
coresAsignedToTasks.resize(size);
usedInstance = std::move(instance);
}

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

Individual Individual::makeOffspring2(Individual& mother){
	Individual* individuals[2] = {this, &mother};
	Individual offspring(this->usedInstance);

	int numerOfTaks = coresAsignedToTasks.size();

	std::stack<int> changeSourceAt;
	int nextChangingPoint;
	int largestPoint = numerOfTaks;
	for(int i = 0; i < 10; i++){
		int point = largestPoint - (rand() % largestPoint);
		largestPoint = point;
		if(largestPoint <= 0) break;
		changeSourceAt.push(point);
	}

	bool fromFather = (bool) rand() % 2;
	nextChangingPoint = changeSourceAt.top();
	changeSourceAt.pop();
    int previousChangingPoint = 0;


	for(int i = 0; i < coresAsignedToTasks.size(); i++){
		if (i >= nextChangingPoint) {
			if(!changeSourceAt.empty()) {
			    previousChangingPoint = nextChangingPoint;
				nextChangingPoint = changeSourceAt.top();
				changeSourceAt.pop();
			}
		}

		if(valueFunction(this->coresAsignedToTasks.begin() + previousChangingPoint, this->coresAsignedToTasks.begin() + nextChangingPoint, usedInstance->getNumProcessors()) <
		    valueFunction(mother.coresAsignedToTasks.begin() + previousChangingPoint, mother.coresAsignedToTasks.begin() + nextChangingPoint, usedInstance->getNumProcessors()))
		    fromFather = false;
		else
		    fromFather = true;

		if(fromFather){
			offspring.coresAsignedToTasks.push_back( this->coresAsignedToTasks.at(i) );
		}
		else{
			offspring.coresAsignedToTasks.push_back( mother.coresAsignedToTasks.at(i) );
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

void Individual::mutate(int maxMutations){
	int numberOfTasks = coresAsignedToTasks.size();
	for(int i = 0; i < rand() %  maxMutations; i++){
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

const vector<int> &Individual::getCoresAsignedToTasks() const {
	return coresAsignedToTasks;
}

std::shared_ptr<Instance> Individual::getUsedInstance() const {
	return usedInstance;
}

void Individual::setUsedInstance(const std::shared_ptr<Instance> &usedInstance) {
	Individual::usedInstance = usedInstance;
}
