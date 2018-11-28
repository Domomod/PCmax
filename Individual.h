#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
	using std::vector;

class Individual{
private:
	vector<int> coresAsignedToTasks;
protected:
public:
	Individual(std::initializer_list<int> coreIds){
		for( auto coreId : coreIds ){
			coresAsignedToTasks.push_back(coreId);
		}
	}
	
};

#endif