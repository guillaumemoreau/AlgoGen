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

/**
 la classe population définit les opérations sur une population de génômes (de classes dérivées de genome).
 Elle ne contient qu'une liste de genome (implémentée avec un vecteur de pointeurs sur des génômes pour 
 permettre le polymorphisme
*/
class population {
private:
    /// Liste de genômes d'une population
    vector<genome*> pop;
    
public:
    /// opération de sélecton des n meilleurs génômes.
    vector<genome*> selection(vector<genome*> l, int n);
    
    
    /// opération de reproduction des genômes.
    vector<genome*> reproduction(vector<genome*> l, int n);
    
    /// mutation d'une liste de genômes
    vector<genome*> mutation(vector<genome*>);
    
    vector<genome*> generation(vector<genome*>,int n,int m);
    
    /// accesseur : renvoie la liste de génômes
    vector<genome *>& getPop() { return pop; }
    
    /// affiche la population
    void affiche(ostream& o) const;
    
    /// taille de la population
    int size() { return this->pop.size(); }
    
};

ostream& operator<<(ostream& o,const population& p);

void debugAfficheVecteur(vector<genome*> l);

#endif /* defined(__AlgoGen__population__) */
