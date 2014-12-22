//
//  genome.h
//  AlgoGen
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#ifndef AlgoGen_genome_h
#define AlgoGen_genome_h

/// classe genome abstraite
class genome {
public:
    virtual void mutation() = 0;
    virtual genome* croisement(genome *g) = 0;
    
    virtual int estMeilleurQue(const genome* g) const = 0;
    
    virtual void affiche(ostream &o) const = 0;
    
};

bool compare_fnc(const genome *a,const genome *b);

#endif
