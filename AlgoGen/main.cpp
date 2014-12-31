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

const int popSize = 10;

int main(int argc, const char * argv[]) {

    motmystere::setMotMystere("alea");
    
    // creation d'une population
    population myPop;
    for (int i(0) ; i<popSize ; i++) {
        genome *g = new motmystere(4);
        myPop.getPop().push_back(g);
    }
    
    cout << myPop << endl;
    
    for (int iter(0) ; iter<5000 ; iter++) {
        cout << "iteration " << iter << endl;
        myPop.generation(myPop.getPop(), popSize, 2);
        for (int i(0) ; i<myPop.getPop().size() ; i++) {
            genome *g = myPop.getPop()[i];
            motmystere *m = (motmystere*) g;
            if (m->found()) {
                cout << "trouve en " << iter << " iterations !"<< endl;
                exit(0);
            }
        }
        cout << myPop << endl;
    }
    
    cout << myPop << endl;
    
    return 0;
}
