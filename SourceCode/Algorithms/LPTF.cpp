#include "LPTF.hpp"

Result LongestProcessingTimeFirst::operator()(std::shared_ptr<Instance> instance) {
	//we will manipulate our Instance, so it's better to work on a copy

	std::shared_ptr<Instance> SortedInstance( new Instance(*instance) );

	//descendign sort
	std::sort(SortedInstance->tasks.begin(), SortedInstance->tasks.end(),
	[](Task& a, Task& b){return a.getLength() > b.getLength();});
	
	//descending sort ensures that Greedy Algorithm places longest possible Task in every step
	return Greedy::operator()(SortedInstance);
}