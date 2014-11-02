//
//  motmystere.cpp
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#include <cstdlib>
#include <iostream>
using namespace std;

#include "motmystere.h"

float motmystere::tauxMutation = 0.05;

motmystere::motmystere(int n) {
    tentative = "";
    for (int i(0) ; i<n ; i++) {
        int r = rand()%26;
        char l = 'a'+r;
        tentative += l;
    }
}

void motmystere::mutation() {
    for (int i(0) ; i<tentative.length() ; i++) {
        float m = random();
        if (m < tauxMutation) {
            int r = rand()%26;
            char l = 'a'+r;
            tentative[i] = l;
        }
    }
}

genome* motmystere::croisement(genome *g) {
    string tt;
    int n = rand()%this->tentative.length();
    for (int i(0) ; i<n ; i++) {
        tt += this->tentative[i];
    }
    for (int i(n+1) ; i<tentative.length() ; i++) {
        if (typeid(g) == typeid(this)) {
            motmystere *m = dynamic_cast<motmystere*>(g);
            tt += m->tentative[i];
        }
        else {
            cerr << "pb de type" << endl;
        }
    }
    motmystere *r = new motmystere(this->tentative.length());
    r->tentative = tt;
    return r;
}

bool  motmystere::estMeilleurQue(const genome& g) const {
    return true;
}