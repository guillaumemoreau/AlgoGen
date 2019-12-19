#define BOOST_TEST_MODULE Population
#include <boost/test/included/unit_test.hpp>

#include "motmystere.h"
#include "population.h"


struct TestMotMystere  {

    population myPop;

    TestMotMystere() {
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

    ~TestMotMystere() {

    }
};

BOOST_FIXTURE_TEST_SUITE(AlgoGen,TestMotMystere)

BOOST_AUTO_TEST_CASE( population_selection) {
    BOOST_REQUIRE(myPop.size() == 4);
    vector<genome *> v = myPop.selection(myPop.getPop(),1);
    BOOST_REQUIRE(v.size() == 1);
    //cout << "le meilleur : " << ((motmystere*)v[0])->getTentative() << endl;
    BOOST_CHECK(((motmystere*)v[0])->getTentative() == "bbaa");

    v = myPop.selection(myPop.getPop(),2);
    BOOST_REQUIRE(v.size() == 2);
    //cout << "le meilleur : " << ((motmystere*)v[0])->getTentative() << endl;
    BOOST_CHECK(((motmystere*)v[0])->getTentative() == "bbaa");
    BOOST_CHECK(((motmystere*)v[1])->getTentative() == "abbb" || ((motmystere*)v[1])->getTentative() == "bbab");
}

BOOST_AUTO_TEST_CASE( population_reproduction) {
    BOOST_REQUIRE(myPop.size() == 4);

    vector<genome*> v = myPop.reproduction(myPop.getPop(), 5);
    BOOST_CHECK(5 == v.size());

}




BOOST_AUTO_TEST_SUITE_END()
