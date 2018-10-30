#ifndef LPTF_H
#define LPTF_H

#include "Greedy.h"
#include <algorithm>

/*
An algorithm based on Greedy Algorithm, the only diffrence is that it ensures, Tasks are assigned size descending.
*/

class LongestProcessingTimeFirst : public Greedy {
private:
protected:
public:
	LongestProcessingTimeFirst()=default;
	virtual ~LongestProcessingTimeFirst(){};

	void operator()(Instance&, Result&);
};

#endif