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
	Individual(int size=0){
		coresAsignedToTasks.resize(size);
	}

	explicit Individual(std::shared_ptr<Instance> instance, unsigned long size=0){
		coresAsignedToTasks.resize(size);
		usedInstance = std::move(instance);
	}

	//TODO: actualize this constructor
	Individual(Result& result);

	Individual makeOffspring(Individual& mother);
	static Individual makeRandom(std::shared_ptr<Instance> instance);

	void mutate();

	int valueFunction(std::shared_ptr<Instance> myInstance);

	friend ostream& operator<<(ostream& out, Individual individual);
};

#endif