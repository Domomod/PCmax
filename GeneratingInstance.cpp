#include "GeneratingInstance.h"

void GeneratingInstance::Build(Instance& instance){
	int numberOfCores = rand() % 97 + 3;
	int numberOfTaks = 0;
	int optimalProcessingTime = numberOfCores * (rand() %40 + 10);
	//Randomly generate Instance's optimum

	for(int i = 0; i < numberOfCores; i++){
		//For every core, generate a random number of tasks, which lengths (also random) when added equal optimum
		int coreLengthSoFar = 0;
		while(coreLengthSoFar<optimalProcessingTime){
			int newTaskLength = rand() %1000 + 3;
			if(coreLengthSoFar + newTaskLength > optimalProcessingTime)
			//Check if newTaskLength does not overload core (aka does not increase optimal processing time), if so trim new TaskLength, so it fits
				newTaskLength = optimalProcessingTime - coreLengthSoFar;

			instance.tasks.push_back(Task(newTaskLength));
			numberOfTaks++;
			coreLengthSoFar += newTaskLength;
		}
	}

	std::random_shuffle(instance.tasks.begin(), instance.tasks.end());
	//reshuffle for even more random result
	
	instance.numProcessors = numberOfCores;
	instance.numTasks = numberOfTaks;
}