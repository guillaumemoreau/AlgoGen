//
//  motmystere.h
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#ifndef __AlgoGen__motmystere__
#define __AlgoGen__motmystere__

#include <iostream>
#include <string>
using namespace std;

#include "genome.h"

class motmystere : public genome {
private:
    string tentative;
    static string motMystere;
    static float tauxMutation;
    
public:
    static string getMotMystere() {
        return motMystere;
    }
    
    static void setMotMystere(string s) {
        motMystere = s;
    }
    
    motmystere(int n);
    
    void mutation();
    
    genome* croisement(genome *g);
    
    int estMeilleurQue(const genome& g) const;
    
    void affiche(ostream& o) const {
        o << tentative;
    }
};

ostream& operator<<(ostream &o,const motmystere& m);

#endif /* defined(__AlgoGen__motmystere__) */
