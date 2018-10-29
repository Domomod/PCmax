//
//  main.cpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//


#include <iostream>
#include "Instance.hpp"
#include "LoadingInstance.hpp"
#include "Core.hpp"
#include "Greedy.hpp"


int main(){
    Instance instance(4, {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40});
    std::cout << instance;
    
    LoadingInstance loadInstance;
    
    //loadInstance.Build(instance);
    //std::cout << instance;
    Greedy greed(instance);

    greed.dogreedstaff();
    
    return 0;
}


