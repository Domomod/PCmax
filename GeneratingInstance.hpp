#ifndef GENERATING_INSTANCE_H
#define GENERATING_INSTANCE_H

#include <cstdlib>
#include <algorithm>

#include "BuildingInstance.h"
#include "Instance.h"
#include "Task.h"

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