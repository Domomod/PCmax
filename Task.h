#ifndef TASK_H
#define TASK_H

#include <iostream>
	using std::ostream;
	using std::istream;

class Task{
private:
	int length;
protected:
public:
	Task(int i) : length (i) {}
	int getLength() const { return length; }
	friend ostream& operator<<(ostream&, const Task&);
	friend istream& operator>>(istream&, Task&);

	bool operator<(Task& other){ return length < other.length; }
};


#endif