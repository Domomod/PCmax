#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include "SourceCode/Domain/Instance.hpp"
#include "SourceCode/Algorithms/DataTypes/Result.hpp"

class AbstractAlgorithm{
private:
protected:
public:
	AbstractAlgorithm()=default;
	virtual ~AbstractAlgorithm(){};

	virtual void operator()(Instance&, Result&)=0;
};

#endif