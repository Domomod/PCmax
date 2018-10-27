#ifndef LOADING_INSTANCE_H
#define LOADING_INSTANCE_H

#include "Task.h"
#include "Instance.h"
#include "BuildingInstance.h"

#include <iostream>
	using std::istream;
#include <memory>
	using std::unique_ptr;
class LoadingInstance {
private:
	istream* in;
protected:
public:
	LoadingInstance(){ in = &std::cin; };
	void SetSource(istream& source) { in = &source; };
	void Build(Instance&);
	~LoadingInstance(){};// istream in is not your's to delete
};

#endif