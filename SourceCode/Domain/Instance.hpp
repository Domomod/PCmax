#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <iostream>
	using std::ostream;
#include "Task.hpp"

/*
This class represents an Instace of PCmax problem. Tasks are stored in a vector. Class is befriended with other classes resposible for it processing.
*/

typedef std::vector<Task> Tasks;

class Instance {
	friend ostream& operator<< (ostream&, Instance&);
	friend class LoadingInstance;
	friend class GeneratingInstance;
	friend class Greedy;
	friend class LongestProcessingTimeFirst;
private:
	Tasks tasks;
	int numProcessors;
protected:
public:
	Instance() = default;
	Instance(int P, std::initializer_list<int> _tasks) : numProcessors(P)
	 {
		for(auto task : _tasks)
			tasks.push_back(task);
	}
	//You can initialize Instance in such a manner Instance(x,{a,b,c,d,e,f}), where x is number of Processors, and {a,b,c,d,e,f} is a list of Tasks
	void addTask(Task);

	Task& getNthTask(int n) { return tasks.at(n); }
	int getNthTaskLength(int n) { return tasks.at(n).getLength(); }
	int getNumProcessors() const { return numProcessors; }
	int getNumTasks() const { return tasks.size(); }
};

#endif