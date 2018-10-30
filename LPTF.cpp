#include "LPTF.h"

void LongestProcessingTimeFirst::operator()(Instance& Ins, Result& Res){
	Instance SortedInstance = Ins;
	//we will manipulate our Instance, so it's better to work on a copy

	std::sort(SortedInstance.tasks.begin(), SortedInstance.tasks.end(),
	[](Task& a, Task& b){return a.getLength() > b.getLength();});
	//descendign sort

	Greedy::operator()(SortedInstance,Res);
	//descending sort ensures that Greedy Algorithm places longest possible Task in every step
}