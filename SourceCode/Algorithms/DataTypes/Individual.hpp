#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
	using std::vector;
#include <iostream>
	using std::ostream;
#include <memory>

#include "Result.hpp"

class Individual{
private:
	vector<int> coresAsignedToTasks;
	std::shared_ptr<Instance> usedInstance;
protected:
public:
	explicit Individual(int size=0);
	explicit Individual(std::shared_ptr<Instance> instance, unsigned long size=0);
	explicit Individual(Result& result);

	Individual makeOffspring(Individual& mother);
	Individual makeOffspring2(Individual& mother);
	static Individual makeRandom(std::shared_ptr<Instance> instance);

	void mutate(int maxMutations);

	int valueFunction(std::shared_ptr<Instance> myInstance);
	int valueFunction(std::vector<int>::iterator begin, std::vector<int>::iterator end, int numCores){
		vector<int> Cores(numCores, 0);
		int i = 0;
		int maxSoFar = 0;
		for(auto position = begin; position < end; position++){
			Cores[*position] += usedInstance->getNthTaskLength(i);
			maxSoFar = std::max(maxSoFar,Cores[*position]);
			i++;
		}
		return maxSoFar;
	}


	friend ostream& operator<<(ostream& out, Individual individual);


	/*Setters And Getters*/


	const vector<int> &getCoresAsignedToTasks() const;

	std::shared_ptr<Instance> getUsedInstance() const;

	void setUsedInstance(const std::shared_ptr<Instance> &usedInstance);

};

#endif