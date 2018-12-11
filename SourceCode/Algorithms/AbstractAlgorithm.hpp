#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include <memory>
#include "SourceCode/Domain/Instance.hpp"
#include "SourceCode/Algorithms/DataTypes/Result.hpp"

class AbstractAlgorithm{
private:
protected:
public:
	AbstractAlgorithm()=default;
	virtual ~AbstractAlgorithm(){};

	virtual void operator()(std::shared_ptr<Instance> instance, Result &result) =0;
};

#endif