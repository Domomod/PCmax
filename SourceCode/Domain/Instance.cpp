#include "Instance.hpp"
#include "SourceCode/Utility.hpp"

void Instance::addTask(Task newTask){
	tasks.push_back(newTask);
}

ostream& operator<< (ostream& out, Instance& instance ){
	out << "Number of Processors: " << instance.numProcessors 
		<< "\tNumber of Tasks: " << instance.getNumTasks()
		<< "\n" << instance.tasks;
    return out;
}
