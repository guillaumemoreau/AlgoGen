#define BOOST_TEST_MODULE MotMystere
#include <boost/test/included/unit_test.hpp>

#include "motmystere.h"

BOOST_AUTO_TEST_CASE(mot_mystere) {
    motmystere m(4); m.setTentative("bbbb");
    motmystere n(4); n.setTentative("aaaa");

    genome *g = m.croisement(&n);
    motmystere *c = (motmystere*) g;
    BOOST_CHECK(nullptr != c);
    BOOST_CHECK_EQUAL(c->getTentative().length(),m.getTentative().length());
    // on examine tous les cas possibles
    BOOST_CHECK(c->getTentative()=="aaaa" || c->getTentative() == "bbba" ||
                c->getTentative() == "bbaa" || c->getTentative() == "baaa");

    g = n.croisement(&m);
    c = (motmystere*) g;
    BOOST_CHECK(nullptr != c) ;
    BOOST_CHECK(c->getTentative().length() == m.getTentative().length()) ;
    // on examine tous les cas possibles
    BOOST_CHECK(c->getTentative()=="bbbb" || c->getTentative() == "abbb" ||
                c->getTentative() == "aabb" || c->getTentative() == "aaab") ;

}

BOOST_AUTO_TEST_CASE(comparaison) {
    motmystere m(4); m.setTentative("bbbb");
    motmystere n(4); n.setTentative("abab");

    BOOST_REQUIRE( m.estMeilleurQue(&m) == 0);
    BOOST_REQUIRE( n.estMeilleurQue(&n) == 0);

    BOOST_CHECK(n.estMeilleurQue(&m) > 0);
    BOOST_CHECK( ! (m.estMeilleurQue(&n)> 0));

}

BOOST_AUTO_TEST_CASE(test_mutation) {

    // on verifie juste que pour 100 mutations on a bien un genome different
    // pas certain mais hautement probable...
    motmystere m(4); m.setTentative("bbbb");
    for (int i(0) ; i<100 ; i++) {
        m.mutation();
    }
    BOOST_CHECK(m.getTentative() != "bbbb");
}
