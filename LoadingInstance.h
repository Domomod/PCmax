#ifndef LOADING_INSTANCE_H
#define LOADING_INSTANCE_H

#include "Task.h"
#include "Instance.h"
#include "BuildingInstance.h"

#include <iostream>
	using std::istream;
#include <memory>
	using std::unique_ptr;

/*
Functor for loading Instances, it's capable to load Instance from istream or ifstream. Ready to work after construction.
*/

class LoadingInstance {
private:
	istream* in;
protected:
public:
	LoadingInstance(istream& source = std::cin){ in = &source; };
	void SetSource(istream& source) { in = &source; }; //Read from istream or ifstream

	void Build(Instance&);//Instance will be overwriteen
	~LoadingInstance(){};// istream in is not your's to delete
};

#endif