//
//  Greedy.hpp
//  PCmax
//
//  Created by Julia on 28.10.2018.
//  Copyright © 2018 Julia. All rights reserved.
//

#ifndef Greedy_hpp
#define Greedy_hpp

#include <stdio.h>
#include "Core.hpp"
#include "Result.hpp"
#include "Instance.hpp"
#include "AbstractAlgorithm.hpp"
class Greedy : public AbstractAlgorithm{
private:
protected:
public:
    Greedy()=default;
    virtual ~Greedy(){};

    void operator()(Instance&, Result&);
};


#endif /* Greedy_hpp */
