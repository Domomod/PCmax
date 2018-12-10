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
	Individual(int size){
		coresAsignedToTasks.resize(size);
	}
	Individual(std::initializer_list<int> coreIds){
		for( auto coreId : coreIds ){
			coresAsignedToTasks.push_back(coreId);
		}
	}
	Individual(Result& result);

	Individual makeOffspring(Individual& other);

	int valueFunction(Instance& myInstance);

	friend ostream& operator<<(ostream& out, Individual individual);
};

#endif