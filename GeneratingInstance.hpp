#ifndef GENERATING_INSTANCE_H
#define GENERATING_INSTANCE_H

#include <cstdlib>
#include <algorithm>

#include "BuildingInstance.hpp"
#include "Instance.hpp"
#include "Task.hpp"

/*
Functor overwrites a given Instance, with a new randomly generated Instance. Previous Instance (if there was any) is erased.
*/

class GeneratingInstance : public BuildingInstance{
private:
protected:
public:
	void Build(Instance&);
	~GeneratingInstance(){};
};

#endif