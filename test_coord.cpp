#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "coord.hpp"
using namespace std;

TEST_CASE("testing Coord class") {
    Coord c1(10,15);
    CHECK(c1.getLine()==10);
    CHECK(c1.getColumn()==15);
    CHECK_THROWS_AS(Coord c2(-1,15), std::invalid_argument);
    CHECK_THROWS_AS(Coord c3(5,20), std::invalid_argument);
    Coord c4(0,19);
    CHECK(c4.getColumn()==19);
    CHECK(c4.getLine()==0);
    cout << c1<<endl;
}
