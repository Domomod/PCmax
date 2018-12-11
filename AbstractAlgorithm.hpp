#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include "Instance.h"
#include "Result.h"

class AbstractAlgorithm{
private:
protected:
public:
	AbstractAlgorithm()=default;
	virtual ~AbstractAlgorithm(){};

	virtual void operator()(Instance&, Result&)=0;
};

#endif