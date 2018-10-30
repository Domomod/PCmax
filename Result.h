#ifndef RESULT_H
#define RESULT_H

#include "Core.h"
#include "Instance.h"
#include <vector>
	using std::vector;
#include <algorithm>

class Result{
	friend class Greedy;
private:
	vector<Core> Cores;
	int max;
protected:
public:
	Result():max(0){};
	void PrepareForProcessing(Instance&);
	Core& findshortest(Instance&);
	void calcmax();
	void showyourself();

	int getMax () const { return max; }
};

#endif