//
//  population.cpp
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//
#include <iostream>
using namespace std;

#include "population.h"



/**
 methode bourrin : on prend n fois le meilleur...
*/
vector<genome*> population::selection(vector<genome*> l1,int n) {
    vector<genome*> *nBest = new vector<genome*>();
    vector<genome*> l2;
    
    if (l1.size() < n) {
        cerr << "Pb de taille" << endl;
        //@TODO : il faudra penser à lancer une exception ici !
    }
    
    // copie de l1 dans nBest
    copy(l1.begin(), l1.end(), l2.begin());
    for (int i(0); i<n ; i++) {
        // on recupere le meilleur de l2 et on le supprime
        genome* best = *(l2.begin());
        vector<genome*>::iterator ibest;
        for (vector<genome*>::iterator j=l2.begin() ; j!=l2.end() ; j++) {
            if ((*j)->estMeilleurQue(*best) > 0) {
                best = *j;
                ibest = j;
            }
        }
        nBest->push_back(best);
        l2.erase(ibest);
    }
    return *nBest;
}

vector<genome*> population::reproduction(vector<genome*> l1,int n) {
    vector<genome*> *repList = new vector<genome*>();
    
    for (int i(0) ; i<n ; i++) {
        int i1 = rand()%n;
        int i2 = rand()%n;
        while (i2 == i1) {
            i2 = rand()%n;
        }
        
        repList->push_back(l1[i1]->croisement(l1[i2]));
    }
    
    return *repList;
}

vector<genome*> population::mutation(vector<genome*> l1) {
    for (genome*& g : l1) {
        g->mutation();
    }
    return l1;
}


vector<genome*> population::generation(vector<genome*> l1,int n,int m) {
    vector<genome*> best = this->selection(l1,m);
    vector<genome*> croisements = this->reproduction(best, n-m);
    copy(croisements.begin(),croisements.end(),best.begin());
    this->mutation(best);
    return best;
}

void population::affiche(ostream &o) const {
    for (int i(0) ; i<pop.size() ; i++) {
        pop[i]->affiche(o);
        o << ",";
    }
}

ostream& operator<<(ostream& o,const population& p) {
    o << "[" ;
    p.affiche(o);
    o << "]";
    return o;
}

