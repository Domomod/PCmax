#ifndef RESULT_H
#define RESULT_H

#include "SourceCode/Domain/Core.hpp"
#include "SourceCode/Domain/Instance.hpp"

#include <vector>
	using std::vector;
#include <algorithm>
#include <memory>

//Forward declaration instead of include allows to avoid circular dependency
class Individual;

class Result{
	friend class Greedy;
	friend class LPTF;
	friend class Individual;
private:
	vector<Core> Cores;
	std::shared_ptr<Instance> usedInstance;
	int longestProcessingTime;
	int numberOfTasks;
protected:
public:
	Result(std::shared_ptr<Instance> instance);

	Result(Individual individual);

	void Clear();
	void Resize(int n);
	Core &findshortest();
	void calcmax();
	void showyourself();
	void showOnlyTime();


		int getMax () const { return longestProcessingTime; }
	int getNumberOfTasks () const { return numberOfTasks; }

	std::shared_ptr<Instance> getUsedInstance() const {
		return usedInstance;
	}
};

#endif