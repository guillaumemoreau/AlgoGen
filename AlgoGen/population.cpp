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
 comparateur externe utilisé en tant que pointeur de fonction qui se contente d'appeler
 genome::estMeilleurQue(). 
 
 @todo remplacer par un prédicat
 @param a premier génôme à comparer
 @param b second génôme à comparer
 @return positif si a>b, négatif si b>a et nul si a==b
*/
bool compare_fnc(const genome *a,const genome *b) {
    return a->estMeilleurQue(b) > 0;
}

/**
 La sélection des n meilleurs est faite de façon "rude" : tri puis on prend les n meilleurs restants
@param l1 liste de génômes
@param n nombre à sélectionner
@return liste des meilleurs génômes
*/
vector<genome*> population::selection(vector<genome*> l1,int n) {
    vector<genome*> *nBest = new vector<genome*>(n);
    vector<genome*> l2(l1.size());
    
    cout << "population::selection() - input" << endl;
    debugAfficheVecteur(l1);
    
    if (l1.size() < n) {
        cerr << "Pb de taille" << endl;
        //@TODO : il faudra penser à lancer une exception ici !
    }
    
    // copie de l1 dans nBest
    copy(l1.begin(), l1.end(), l2.begin());
    // tri de l2
    sort(l2.begin(), l2.end(), compare_fnc);
    // on garde les n meilleurs
    copy(l2.begin(), l2.begin()+n,nBest->begin());
    
    cout << "resultat de selection :" << endl;
    debugAfficheVecteur(*nBest);
    
    return *nBest;
}

/**
 Choix de n couples de génômes puis appel de la fonction genome::croisement(). On vérifie juste qu'un génôme
 ne se reproduit pas avec lui-même.
 @param l1 liste de génômes qui vont se reproduire
 @param n nombre de génômes à produire
 @return liste de n génômes produits par croisement d'éléments de liste passée en paramètres
 */
vector<genome*> population::reproduction(vector<genome*> l1,int n) {
    vector<genome*> *repList = new vector<genome*>();
    
    for (int i(0) ; i<n ; i++) {
        int i1 = rand()%l1.size();
        int i2 = rand()%l1.size();
        while (i2 == i1) {
            i2 = rand()%l1.size();
        }
        
        repList->push_back(l1[i1]->croisement(l1[i2]));
    }
    
    return *repList;
}

/**
 simple boucle et appel de la fonction de mutation pour chacun.
 
 @todo utiliser un foncteur pour appliquer la mutation à chaque élément de la liste
 @param l1 liste des éléments à muter
 @return liste des éléments mutés
*/
vector<genome*> population::mutation(vector<genome*> l1) {
    
    cout << "population::mutation - input" << endl;
    debugAfficheVecteur(l1);
    
    for (genome*& g : l1) {
        g->mutation();
    }
    
    cout << "population::mutation - output" << endl;
    debugAfficheVecteur(l1);
    
    return l1;
}


vector<genome*> population::generation(vector<genome*> l1,int n,int m) {
    cout << "population::generation() - input" << endl;
    debugAfficheVecteur(l1);
    
    vector<genome*> best = this->selection(l1,m);
    
    cout << "population::generation() - selection" << endl;
    debugAfficheVecteur(best);
    
    vector<genome*> croisements = this->reproduction(best, n-m);
    
    cout << "population::generation() - croisements" << endl;
    debugAfficheVecteur(croisements);
    
    for (genome*& g : croisements) {
        best.push_back(g);
    }
    
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

void debugAfficheVecteur(vector<genome*> l) {
    cout << "[" ;
    for (int i(0) ; i<l.size() ; i++) {
        l[i]->affiche(cout);
        cout << ",";
    }
    cout << "]" << endl;
}