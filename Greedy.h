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
#include "Core.h"
#include "Result.h"
#include "Instance.h"
#include "AbstractAlgorithm.h"
class Greedy : public AbstractAlgorithm{
private:
protected:
public:
    Greedy()=default;
    virtual ~Greedy(){};

    void operator()(Instance&, Result&);
};


#endif /* Greedy_hpp */
