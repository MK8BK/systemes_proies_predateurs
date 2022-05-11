#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <exception>
#include <string>
using namespace std;

#include "doctest.h"
#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"

TEST_CASE("testing Coord class") {
	//TAILLEGRILLE
	//cout << TAILLEGRILLE << endl;

	//test simple case
	//currently changing to dynamic grid size testing
	Coord c1(TAILLEGRILLE/2,(TAILLEGRILLE*3)/4);
	CHECK(c1.getLine()==TAILLEGRILLE/2);
	CHECK(c1.getColumn()==(TAILLEGRILLE*3)/4);

	//test grid over the edge cases
	CHECK_THROWS_AS(Coord c2(-1,(TAILLEGRILLE*3)/4), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2((TAILLEGRILLE*3)/4,-1), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(TAILLEGRILLE,(TAILLEGRILLE/4)), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2((TAILLEGRILLE/4),TAILLEGRILLE), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2(-1,TAILLEGRILLE), std::invalid_argument);
	CHECK_THROWS_AS(Coord c2((TAILLEGRILLE+3),-5), std::invalid_argument);
	
	//test corners
	Coord c3(0,0);
	CHECK(c3.getColumn()==0);
	CHECK(c3.getLine()==0);
	Coord c4(TAILLEGRILLE-1,0);
	CHECK(c4.getColumn()==0);
	CHECK(c4.getLine()==TAILLEGRILLE-1);
	Coord c5(0,TAILLEGRILLE-1);
	CHECK(c5.getColumn()==TAILLEGRILLE-1);
	CHECK(c5.getLine()==0);
	Coord c6(TAILLEGRILLE-1,TAILLEGRILLE-1);
	CHECK(c6.getColumn()==TAILLEGRILLE-1);
	CHECK(c6.getLine()==TAILLEGRILLE-1);

	//test == operator
	Coord c7((TAILLEGRILLE/2),(TAILLEGRILLE*3)/4);
	Coord c8((TAILLEGRILLE/2),(TAILLEGRILLE*3)/4);
	Coord c9((TAILLEGRILLE*19)/20,0);
	Coord c10((TAILLEGRILLE*19)/20,0);
	Coord c11((TAILLEGRILLE/4),0);
	Coord c12(0,(TAILLEGRILLE/4));
	Coord c13((TAILLEGRILLE*12)/13,(TAILLEGRILLE/4));
	Coord c14((TAILLEGRILLE*13)/20,(TAILLEGRILLE/10));
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
	//cout << c7 << endl;
	//cout << c9 << endl;
	//cout << c11 << endl;
	//cout << c13 << c14 << endl;

	//test single Int constructor
	Coord c15(TAILLEGRILLE);
	Coord c16(0);
	Coord c17(TAILLEGRILLE*TAILLEGRILLE-1);
	Coord c18(1,0);
	Coord c19(0,0);
	Coord c20(TAILLEGRILLE-1,TAILLEGRILLE-1);
	CHECK(c18 == c15);
	CHECK(c19 == c16);
	CHECK(c20 == c17);
	CHECK(c18.toInt() == TAILLEGRILLE);
	CHECK(c19.toInt() == 0);
	CHECK(c20.toInt() == TAILLEGRILLE*TAILLEGRILLE-1);

	//test voisines() mothod
	Coord c21(0,0);	
	CHECK(c21.voisines().cardinal()==3);
	CHECK(c21.voisines().getElement(0)==1);
	CHECK(c21.voisines().getElement(1)==TAILLEGRILLE);
	CHECK(c21.voisines().getElement(2)==TAILLEGRILLE+1);

	Coord c22(TAILLEGRILLE-1, TAILLEGRILLE-1);
	CHECK(c22.voisines().cardinal()==3);
	CHECK(c22.voisines().getElement(0)==TAILLEGRILLE*(TAILLEGRILLE - 1) - 2);
	CHECK(c22.voisines().getElement(1)==TAILLEGRILLE*(TAILLEGRILLE - 1) - 1);
	CHECK(c22.voisines().getElement(2)==TAILLEGRILLE*TAILLEGRILLE - 2);

	Coord c23(0, TAILLEGRILLE-1);
	CHECK(c23.voisines().cardinal()==3);
	CHECK(c23.voisines().getElement(0)==TAILLEGRILLE - 2);
	CHECK(c23.voisines().getElement(1)==2*TAILLEGRILLE - 2);
	CHECK(c23.voisines().getElement(2)==2*TAILLEGRILLE - 1);


	Coord c24(TAILLEGRILLE-1, 0);
	CHECK(c24.voisines().cardinal()==3);
	CHECK(c24.voisines().getElement(0)==TAILLEGRILLE*(TAILLEGRILLE-2));
	CHECK(c24.voisines().getElement(1)==(TAILLEGRILLE-1)*(TAILLEGRILLE-1) );
	CHECK(c24.voisines().getElement(2)==TAILLEGRILLE*TAILLEGRILLE-TAILLEGRILLE+1);

	Coord c25(TAILLEGRILLE/2, 0);
	CHECK(c25.voisines().cardinal()==5);

	Coord c26(0, TAILLEGRILLE/2);
	CHECK(c26.voisines().cardinal()==5);

	Coord c27(TAILLEGRILLE/2, TAILLEGRILLE-1);
	CHECK(c27.voisines().cardinal()==5);

	Coord c28(TAILLEGRILLE-1, TAILLEGRILLE/2);
	CHECK(c28.voisines().cardinal()==5);

	Coord c29(TAILLEGRILLE/2, TAILLEGRILLE/2);
	CHECK(c29.voisines().cardinal()==8);
}

TEST_CASE("testing Ensemble class") {
	//constructor usage
	Ensemble e1;
	Ensemble e2;

	//test estVide() method
	CHECK(e1.estVide());
	CHECK(e2.estVide());

	//test ajoute() method
	e1.ajoute(0);
	CHECK_FALSE(e1.estVide());

	//test cardinal() method
	CHECK(e1.cardinal()==1);

	for(int i=1; i<100; i++){
		e1.ajoute(i);
	}

	CHECK(e1.cardinal()==100);
	//test ajoute() method
	int i = 100;
	while(e1.cardinal()<TAILLEGRILLE*TAILLEGRILLE + 1){
		e1.ajoute(i);
		i++;
	}
	CHECK_THROWS_AS(e1.ajoute(i), std::invalid_argument);
	
	//test tire() method
	CHECK_THROWS_AS(e2.tire(), length_error);

	int before = e1.cardinal();
	int elem = e1.tire();
	int after = e1.cardinal();
	CHECK(before == after+1);
	//cout << e1.cardinal() << endl;
	
	//due to the uniqueness of elements within
	for(int i=0; i<after; i++){
		//cout << i << " | "; 
		CHECK(e1.getElement(i)!=elem);
	}
	
	//test getElement() method
	e2.ajoute(2);
	CHECK(e2.getElement(e2.cardinal()-1)==2);

	//test empty() method
	CHECK_FALSE(e1.estVide());
	e1.empty();
	CHECK(e1.estVide());

	//test << operator
	//cout << e1 << endl;
}

TEST_CASE("testing Animal class") {
	//test enum Espece
	Espece e1 = lapin;
	Espece e2 = renard;
	//cout << toString(e1) << endl;

	//test Animal constuctor
	Animal l1(0,e1,0);
	Animal r1(1, e2, (TAILLEGRILLE * TAILLEGRILLE)-1);

	//test getId() const method
	CHECK(l1.getId()==0);
	CHECK(r1.getId()==1);

	//test getCoord() const method
	CHECK(l1.getCoord().getLine()==0);
	CHECK(l1.getCoord().getColumn()==0);
	CHECK(r1.getCoord().getLine()==TAILLEGRILLE-1);
	CHECK(r1.getCoord().getColumn()==TAILLEGRILLE-1);

	//test getEspece() const method
	CHECK(tostring(l1.getEspece())=="lapin");
	CHECK(tostring(r1.getEspece())=="renard");

	//test toString() method
	CHECK(l1.toString()=="lapin 0, (0, 0)");
	CHECK(r1.toString()=="renard 1, (9, 9)");	
	//cout << l1.toString() << endl;
	//cout << r1.toString() << endl;
	
	//test setCoord() method
	Coord cn(0, TAILLEGRILLE-1);
	l1.setCoord(cn);
	CHECK(l1.getCoord().getLine()==0);
	CHECK(l1.getCoord().getColumn()==TAILLEGRILLE-1);

	r1.meurt();


}