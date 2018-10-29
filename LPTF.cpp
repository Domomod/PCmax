#include "LPTF.h"

void LongestProcessingTimeFirst::operator()(Instance& Ins, Result& Res){
	Instance SortedInstance = Ins;
	std::sort(SortedInstance.tasks.begin(), SortedInstance.tasks.end(),
	[](Task& a, Task& b){return a.getLength() > b.getLength();});
	Greedy::operator()(SortedInstance,Res);
}