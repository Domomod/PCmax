cmake_minimum_required(VERSION 3.13)
project(OK)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OK
        AbstractAlgorithm.cpp
        AbstractAlgorithm.h
        BuildingInstance.h
        Core.cpp
        Core.h
        GeneratingInstance.cpp
        GeneratingInstance.h
        GeneticAlgorithm.cpp
        GeneticAlgorithm.h
        Greedy.cpp
        Greedy.h
        Individual.cpp
        Individual.h
        Instance.cpp
        Instance.h
        LoadingInstance.cpp
        LoadingInstance.h
        LPTF.cpp
        LPTF.h
        main.cpp
        Result.cpp
        Result.h
        Task.cpp
        Task.h
        Utility.h)
