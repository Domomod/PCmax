#include <iostream>
#include "Instance.h"
#include "LoadingInstance.h"
int main(){
	Instance instance(4, {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40});
	std::cout << instance;

	LoadingInstance loadInstance;

	loadInstance.Build(instance);
	std::cout << instance;
	
	return 0;
}