#include "LPTF.hpp"

void LongestProcessingTimeFirst::operator()(Instance& Ins, Result& Res){
	//we will manipulate our Instance, so it's better to work on a copy
	Instance SortedInstance = Ins;

	//descendign sort
	std::sort(SortedInstance.tasks.begin(), SortedInstance.tasks.end(),
	[](Task& a, Task& b){return a.getLength() > b.getLength();});
	
	//descending sort ensures that Greedy Algorithm places longest possible Task in every step
	Greedy::operator()(SortedInstance,Res);
}