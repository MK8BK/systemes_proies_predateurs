#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "coord.hpp"
#include <string>
using namespace std;

TEST_CASE("testing Coord class") {
	//test simple case
	//currently changing to dynamic grid size testing
	Coord c1(TAILLEGRILLE/2,TAILLEGRILLE*2);
	CHECK(c1.getLine()==10);
	CHECK(c1.getColumn()==15);

	//test grid over the edge cases
	CHECK_THROWS_AS(Coord c2(-1,15), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(15,-1), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(20,5), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(5,20), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(-1,20), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(23,-5), std::invalid_argument);
	
	//test corners
	Coord c3(0,0);
	CHECK(c3.getColumn()==0);
	CHECK(c3.getLine()==0);
	Coord c4(19,0);
	CHECK(c4.getColumn()==0);
	CHECK(c4.getLine()==19);
	Coord c5(0,19);
	CHECK(c5.getColumn()==19);
	CHECK(c5.getLine()==0);
	Coord c6(19,19);
	CHECK(c6.getColumn()==19);
	CHECK(c6.getLine()==19);

	//test == operator
	Coord c7(10,15);
	Coord c8(10,15);
	Coord c9(19,0);
	Coord c10(19,0);
	Coord c11(1,0);
	Coord c12(0,1);
	Coord c13(18,5);
	Coord c14(13,2);
	CHECK(c7==c8);
	CHECK(c9==c10);
	CHECK_FALSE(c11==c12);
	CHECK_FALSE(c13==c14);

	//test != operator
	CHECK_FALSE(c7!=c8);
	CHECK_FALSE(c9!=c10);
	CHECK(c11!=c12);
	CHECK(c13!=c14);    


	//test << operator 
	cout << c7 << endl;
	cout << c9 << endl;
	cout << c11 << endl;
	cout << c13 << c14 << endl;

	//test single Int constructor
	Coord c15(TAILLEGRILLE);
	Coord c16(0);
	Coord c17(TAILLEGRILLE*TAILLEGRILLE-1)
	//cout << c1<<endl;
	//CHECK_FALSE(c1 == c4);
	//CHECK(c1 == c1);
	//Coord c7(10,15);
	//CHECK(c7 == c1);
	//Coord c6(399);
	//cout << c6 << endl;
}


