#ifndef LPTF_H
#define LPTF_H

#include "Greedy.hpp"
#include <algorithm>
#include <memory>

/*
An algorithm based on Greedy Algorithm, the only diffrence is that it ensures, Tasks are assigned size descending.
*/

class LongestProcessingTimeFirst : public Greedy {
private:
protected:
public:
	LongestProcessingTimeFirst()=default;
	virtual ~LongestProcessingTimeFirst(){};

	Result operator()(std::shared_ptr<Instance> instance);
};

#endif