#ifndef BUILDING_INSTANCE_H
#define BUILDING_INSTANCE_H

#include "SourceCode/Domain/Instance.hpp"

class BuildingInstance {
private:
protected:
public:
	virtual void Build(Instance&) = 0;
	virtual ~BuildingInstance(){};
};

#endif