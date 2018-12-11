#ifndef RESULT_H
#define RESULT_H

#include "SourceCode/Domain/Core.hpp"
#include "SourceCode/Domain/Instance.hpp"
#include <vector>
	using std::vector;
#include <algorithm>
#include <memory>

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
	void PrepareForInstance(std::shared_ptr <Instance> instance);
	Core &findshortest();
	void calcmax();
	void showyourself();

	int getMax () const { return max; }
	int getNumberOfTasks () const { return numerOfTasks; }
};

#endif