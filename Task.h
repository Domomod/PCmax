#ifndef TASK_H
#define TASK_H

#include <iostream>
	using std::ostream;
	using std::istream;

class Task{
private:
	int length;
	int id;
protected:
public:
	Task(int _len, int _id=0) : length (_len), id(_id)  {}
	int getLength() const { return length; }
	friend ostream& operator<<(ostream&, const Task&);
	friend istream& operator>>(istream&, Task&);

	bool operator<(Task& other){ return length < other.length; }
};


#endif