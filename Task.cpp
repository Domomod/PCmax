#include "Task.h"


ostream& operator<<(ostream& out, const Task& task){ 
	out << task.length; 
	return out; 
}


istream& operator>>(istream& in, Task& task){ 
	in >> task.length; 
	return in; 
}