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

/**
 class motmystere qui met en oeuvre une sorte de genome.
 
 Cette classe doit impérativement dériver de genome. Elle doit donc aussi implanter la spec complete de genome. 
*/
class motmystere : public genome {
private:
    /// le contenu du génôme actuel
    string tentative;
    
    /// la solution recherchée
    static string motMystere;
    
    /// le taux de mutation des génômes
    static float tauxMutation;
    
public:
    /// accesseur en lecture sur le mot recherché
    static string getMotMystere() {
        return motMystere;
    }
    
    /// accesseur en écriture sur le mot recherché
    static void setMotMystere(string s) {
        motMystere = s;
    }
    
    /// constructeur
    motmystere(int n);
    
    void mutation();
    
    genome* croisement(genome *g);
    
    int estMeilleurQue(const genome* g) const;
    
    /// mini fonction d'affichage
    void affiche(ostream& o) const {
        o << tentative;
    }
    
    /// accesseur en écriture (uniquement pour les tests unitaires)
    void setTentative(string tentative) { this->tentative = tentative; }
    
    /// accesseur en lecture
    string getTentative() { return this->tentative; }
    
    /// vérification d'une tentative
    bool found();
};

ostream& operator<<(ostream &o,const motmystere& m);

#endif /* defined(__AlgoGen__motmystere__) */
