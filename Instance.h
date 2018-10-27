#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <iostream>
	using std::ostream;
#include "Task.h"

typedef std::vector<Task> Tasks;

class Instance {
	friend ostream& operator<< (ostream&, Instance&);
	friend class LoadingInstance;
private:
	Tasks tasks;
	int numProcessors;
	int numTasks;
protected:
public:
	Instance() = default;
	Instance(int P, std::initializer_list<int> _tasks) : numProcessors(P), numTasks(_tasks.size()) {
		for(auto task : _tasks)
			tasks.push_back(task);
	}
	void addTask(Task);

	int getNumProcessors() const { return numProcessors; }
	int getNumTasks() const { return numTasks; }
};

#endif