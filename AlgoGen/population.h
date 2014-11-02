//
//  population.h
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#ifndef __AlgoGen__population__
#define __AlgoGen__population__

#include <vector>
using namespace std;

#include "genome.h"

class population {
private:
    vector<genome*> pop;
    
public:
    vector<genome*> selection(vector<genome*>, int n);
    
    vector<genome*> reproduction(vector<genome*>, int n);
    
    vector<genome*> mutation(vector<genome*>);
    
    vector<genome*> generation(vector<genome*>,int n,int m);
};


#endif /* defined(__AlgoGen__population__) */
