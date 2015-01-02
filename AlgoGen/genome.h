//
//  genome.h
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#ifndef AlgoGen_genome_h
#define AlgoGen_genome_h

/* 
 @class genome classe asbtraite elle servira uniquement par heritage.
 
 on se se contente de donner les signatures des fonctions a implanter dans les classes derivees.
 Toutes les fonctions sont virtuelles pures. On utilise des pointeurs sur les genomes dans les 
 parametres pour éviter les copies et permettre la liaison dynamique. On pourrait aussi utiliser
 des references.
 
*/
class genome {
public:
    
    /**
     mutation : operation interne, retour void
    */
    virtual void mutation() = 0;
    
    /** 
     croisement : le croisement de deux genomes en donne un troisieme
    */
    virtual genome* croisement(genome *g) = 0;
    
    /**
     comparaison : on se compare a un autre genome. >0 si this est le meilleur
    */
    virtual int estMeilleurQue(const genome* g) const = 0;
    
    /**
     fonction d'affichage : pour la mise au point seulement
    */
    virtual void affiche(ostream &o) const = 0;
    
};

bool compare_fnc(const genome *a,const genome *b);

#endif
