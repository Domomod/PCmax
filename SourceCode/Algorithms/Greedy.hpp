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
#include <memory>
#include "SourceCode/Domain/Core.hpp"
#include "SourceCode/Algorithms/DataTypes/Result.hpp"
#include "SourceCode/Domain/Instance.hpp"
#include "AbstractAlgorithm.hpp"
class Greedy : public AbstractAlgorithm{
private:
protected:
public:
    Greedy()=default;
    virtual ~Greedy(){};

    Result operator()(std::shared_ptr<Instance> instance);
};


#endif /* Greedy_hpp */
