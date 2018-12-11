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
	std::shared_ptr<Instance> usedInstance;
	int max;
	int numerOfTasks;
protected:
public:
	Result(std::shared_ptr<Instance> instance):max(0){
	usedInstance = std::move(instance);
	Resize(usedInstance->getNumProcessors());
	}

	void Clear();
	void Resize(int n);
	Core &findshortest();
	void calcmax();
	void showyourself();

	int getMax () const { return max; }
	int getNumberOfTasks () const { return numerOfTasks; }

	std::shared_ptr<Instance> getUsedInstance() const {
		return usedInstance;
	}
};

#endif