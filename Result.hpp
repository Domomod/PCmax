#ifndef RESULT_H
#define RESULT_H

#include "Core.hpp"
#include "Instance.hpp"
#include <vector>
	using std::vector;
#include <algorithm>

class Result{
	friend class Greedy;
	friend class LPTF;
	friend class Individual;
private:
	vector<Core> Cores;
	int max;
	int numerOfTasks;
protected:
public:
	Result():max(0){};
	void Clear();
	void Resize(int n);
	void PrepareForInstance(Instance&);
	Core& findshortest(Instance&);
	void calcmax();
	void showyourself();

	int getMax () const { return max; }
	int getNumberOfTasks () const { return numerOfTasks; }
};

#endif