//
//  main.cpp
//  AlgoGenTests
//
//  Created by Guillaume Moreau on 02/11/2014.
//  Copyright (c) 2014 Guillaume Moreau. All rights reserved.
//

#include <gtest/gtest.h>

#include "motmystere.h"
#include "population.h"


class TestMotMystere : public ::testing::Test {
protected:
    population myPop;

    virtual void SetUp() {
        motmystere::setMotMystere("aaaa");
        motmystere *g = new motmystere(4);
        g->setTentative("bbbb");
        myPop.getPop().push_back(g);
        g = new motmystere(4);
        g->setTentative("abbb");
        myPop.getPop().push_back(g);
        g = new motmystere(4);
        g->setTentative("bbab");
        myPop.getPop().push_back(g);
        g = new motmystere(4);
        g->setTentative("bbaa");
        myPop.getPop().push_back(g);
    }
    
    virtual void TearDown() {
        
    }
};


TEST_F(TestMotMystere, population_selection) {
    ASSERT_TRUE(myPop.size() == 30);
    vector<genome *> v = myPop.selection(myPop.getPop(),1);
    ASSERT_TRUE(v.size() == 1);
    cout << "le meilleur : " << ((motmystere*)v[0])->getTentative() << endl;
    EXPECT_TRUE(((motmystere*)v[0])->getTentative() == "bbaa");
}


TEST(test_motmystere, test_comparaison) {
    motmystere m(4); m.setTentative("bbbb");
    motmystere n(4); n.setTentative("abab");
    
    ASSERT_TRUE( m.estMeilleurQue(&m) == 0);
    ASSERT_TRUE( n.estMeilleurQue(&n) == 0);

    EXPECT_TRUE(n.estMeilleurQue(&m) > 0);
    EXPECT_FALSE(m.estMeilleurQue(&n)> 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

