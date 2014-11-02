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
string motmystere::motMystere = "alea";

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

int  motmystere::estMeilleurQue(const genome& g) const {
    int n = 0;
    int m = 0;
    if (typeid(&g) != typeid(this)) {
        cerr << "erreur de type" << endl;
        return -1;
    }
    for (int i(0) ; i<tentative.length() ; i++) {
        if (tentative[i] == motMystere[i]) {
            n++;
        }
        if ((dynamic_cast<const motmystere*>(&g))->tentative[i] == motMystere[i]) {
            m++;
        }
    }
    return n-m;
}

ostream& operator<<(ostream &o,const motmystere& m) {
    o << m;
    return o;
}

