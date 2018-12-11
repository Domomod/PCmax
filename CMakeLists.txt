cmake_minimum_required(VERSION 3.13)
project(PCmax_GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PCmax_GeneticAlgorithm
        SourceCode/Algorithms/AbstractAlgorithm.cpp
        SourceCode/Algorithms/AbstractAlgorithm.hpp
        SourceCode/Domain/Building/BuildingInstance.hpp
        SourceCode/Domain/Core.cpp
        SourceCode/Domain/Core.hpp
        SourceCode/Domain/Building/GeneratingInstance.cpp
        SourceCode/Domain/Building/GeneratingInstance.hpp
        SourceCode/Algorithms/GeneticAlgorithm.cpp
        SourceCode/Algorithms/GeneticAlgorithm.hpp
        SourceCode/Algorithms/Greedy.cpp
        SourceCode/Algorithms/Greedy.hpp
        SourceCode/Algorithms/DataTypes/Individual.cpp
        SourceCode/Algorithms/DataTypes/Individual.hpp
        SourceCode/Domain/Instance.cpp
        SourceCode/Domain/Instance.hpp
        SourceCode/Domain/Building/LoadingInstance.cpp
        SourceCode/Domain/Building/LoadingInstance.hpp
        SourceCode/Algorithms/LPTF.cpp
        SourceCode/Algorithms/LPTF.hpp
        SourceCode/main.cpp
        SourceCode/Algorithms/DataTypes/Result.cpp
        SourceCode/Algorithms/DataTypes/Result.hpp
        SourceCode/Domain/Task.cpp
        SourceCode/Domain/Task.hpp
        SourceCode/Utility.hpp)
