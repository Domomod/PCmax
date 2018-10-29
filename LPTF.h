#ifndef LPTF_H
#define LPTF_H

#include "Greedy.h"
#include <algorithm>

class LongestProcessingTimeFirst : public Greedy {
private:
protected:
public:
	LongestProcessingTimeFirst()=default;
	virtual ~LongestProcessingTimeFirst(){};

	void operator()(Instance&, Result&);
};

#endif