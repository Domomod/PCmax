#ifndef BUILDING_INSTANCE_H
#define BUILDING_INSTANCE_H

#include "Instance.h"

class BuildingInstance {
private:
protected:
public:
	virtual void Build(Instance&) = 0;
	virtual ~BuildingInstance() = 0;
};

#endif