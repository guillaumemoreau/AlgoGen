//
//  main.cpp
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#include <iostream>
using namespace std;

#include "motmystere.h"
#include "population.h"

int main(int argc, const char * argv[]) {

    motmystere::setMotMystere("alea");
    
    // creation d'une population
    population myPop;
    for (int i(0) ; i<30 ; i++) {
        genome *g = new motmystere(4);
        myPop.getPop().push_back(g);
    }
    
    cout << myPop << endl;
    
    return 0;
}
