#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
	using std::vector;
#include <iostream>
	using std::ostream;

#include "Result.h" 

class Individual{
private:
	vector<int> coresAsignedToTasks;
protected:
public:
	Individual(int size=0){
		coresAsignedToTasks.resize(size);
	}

	Individual(Result& result);

	Individual makeOffspring(Individual& other);
	static Individual makeRandom(int numberOfTasks, int numberOfCores);

	void mutate();

	int valueFunction(Instance& myInstance);

	friend ostream& operator<<(ostream& out, Individual individual);
};

#endif