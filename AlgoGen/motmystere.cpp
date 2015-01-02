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

float motmystere::tauxMutation = 0.08;
string motmystere::motMystere = "alea";

/**
  constructeur : remplissage de la tentative avec des lettres choisies au hasard
*/
motmystere::motmystere(int n) {
    tentative = "";
    for (int i(0) ; i<n ; i++) {
        int r = rand()%26;
        char l = 'a'+r;
        tentative += l;
    }
}

/**
 mutation : avec une proba de tauxMutation, on remplace une lettre au hasard
*/
void motmystere::mutation() {
    for (int i(0) ; i<tentative.length() ; i++) {
        float m = random()%10000;
        if (m < tauxMutation*10000) {
            int r = rand()%26;
            char l = 'a'+r;
            tentative[i] = l;
        }
    }
}

/**
 croisement : on utilise les n premières lettres du premier génôme (n étant tiré au sort)
 et les l-n dernières de l'autre
 
 @param g génôme avec lequel on effectue le croisement
 @return le nouveau génôme issu du croisement
*/
genome* motmystere::croisement(genome *g) {
    string tt;
    int n = rand()%this->tentative.length();
    for (int i(0) ; i<n ; i++) {
        tt += this->tentative[i];
    }
    for (int i(n) ; i<tentative.length() ; i++) {
        motmystere *m = (motmystere*)(g);
        if (m != nullptr) {
            tt += m->tentative[i];
        }
        else {
            throw "motmystere::estMeilleurQue() : le génôme fourni n'est pas un motmystere";
        }
    }
    motmystere *r = new motmystere(this->tentative.length());
    r->tentative = tt;
    return r;
}

/**
 comparaison de deux génômes : différence entre le nombre de lettres coïncidantes avec la solution
 
 @param g génôme avec lequel on se compare
 @return différence entre le nombre de lettres coïncidantes avec la solution
*/
int  motmystere::estMeilleurQue(const genome* g) const {
    int n = 0;
    int m = 0;

    motmystere *tmp = (motmystere *) g;
    if (tmp == nullptr) {
        throw "motmystere::estMeilleurQue() : le génôme fourni n'est pas un motmystere";
    }
    for (int i(0) ; i<tentative.length() ; i++) {
        if (tentative[i] == motMystere[i]) {
            n++;
        }
        if (tmp->tentative[i] == motMystere[i]) {
            m++;
        }
    }
    return n-m;
}

ostream& operator<<(ostream &o,const motmystere& m) {
    o << m;
    return o;
}

/**
 vérifie l'égalité entre la tentative et la solution
 
 @return vrai si la solution a été trouvée
*/
bool motmystere::found() {
    return this->tentative == motmystere::motMystere;
}
