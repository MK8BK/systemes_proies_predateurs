#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <exception>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "doctest.h"
#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"
#include "population.hpp"
#include "grille.hpp"
#include "jeu.hpp"

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

	for(int i=1; i<TAILLEGRILLE*TAILLEGRILLE; i++){
		e1.ajoute(i);
	}

	CHECK(e1.cardinal()==TAILLEGRILLE*TAILLEGRILLE);
	//test ajoute() method
	int i = 0;
	while(e1.cardinal()<=TAILLEGRILLE*TAILLEGRILLE){
		//cout << e1.cardinal()<<" | "<<endl;
		e1.ajoute(i);
		i++;
	}
	CHECK_THROWS_AS(e1.ajoute(i), std::invalid_argument);
	
	//test tire() method
	CHECK_THROWS_AS(e2.tire(), std::length_error);

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
	//cout << e1 << endl;
	
	//test contains() method
	e1.ajoute(64);
	//cout << e1 << endl;
	CHECK(e1.contains(64));
	e1.empty();
	CHECK_FALSE(e1.contains(64));



	//test empty() method
	e1.ajoute(1);
	CHECK_FALSE(e1.estVide());
	e1.empty();
	CHECK(e1.estVide());

	//test removeEelement() method
	e1.ajoute(1);
	e1.ajoute(2);
	CHECK(e1.cardinal()==2);
	e1.removeElement(1);
	CHECK(e1.cardinal()==1);
	CHECK(e1.contains(2));


	//test << operator
	//cout << e1 << endl;
}

TEST_CASE("testing Animal class") {
	//test enum Espece
	Espece e1 = lapin;
	Espece e2 = renard;
	Espece e3 = animal;
	//cout << toString(e1) << endl;

	//test Animal constuctor
	Animal l1(0,e1,0);
	Animal r1(1, e2, (TAILLEGRILLE * TAILLEGRILLE)-1);
	Animal generique(-1, e3, 0);

	//test getId() const method
	CHECK(l1.getId()==0);
	CHECK(r1.getId()==1);
	CHECK(generique.getId()==-1);

	//test getCoord() const method
	CHECK(l1.getCoord().getLine()==0);
	CHECK(l1.getCoord().getColumn()==0);
	CHECK(r1.getCoord().getLine()==TAILLEGRILLE-1);
	CHECK(r1.getCoord().getColumn()==TAILLEGRILLE-1);
	CHECK(generique.getCoord().getLine()==0);
	CHECK(generique.getCoord().getColumn()==0);

	//test getEspece() const method
	CHECK(tostring(l1.getEspece())=="lapin");
	CHECK(tostring(r1.getEspece())=="renard");
	CHECK(tostring(generique.getEspece())=="animal");


	//test toString() method
	CHECK(l1.toString()=="lapin 0, (0, 0)");
	string renard_texte =  "renard 1, ("+to_string(TAILLEGRILLE-1)
			+", "+to_string(TAILLEGRILLE-1)+")";
	CHECK(r1.toString()==renard_texte);	
	CHECK(generique.toString()=="animal -1, (0, 0)");

	//cout << l1.toString() << endl;
	//cout << r1.toString() << endl;
	
	//test setCoord() method
	Coord cn(0, TAILLEGRILLE-1);
	l1.setCoord(cn);
	CHECK(l1.getCoord().getLine()==0);
	CHECK(l1.getCoord().getColumn()==TAILLEGRILLE-1);


	//test jeune() method
	int before = r1.getFoodLevel();
	r1.jeune();
	int after = r1.getFoodLevel();
	CHECK(after+1==before);

	//test mange() method
	Ensemble lapinsVoisinsRenard;
	lapinsVoisinsRenard.ajoute(TAILLEGRILLE*(TAILLEGRILLE-1)-1);
	lapinsVoisinsRenard.ajoute(TAILLEGRILLE*(TAILLEGRILLE-1)-2);
	r1.mange(lapinsVoisinsRenard);
	CHECK(after+5 == r1.getFoodLevel());
	//cout << r1.getCoord() << endl;

	//test meurt() method
	while(r1.getFoodLevel()!=1){
		r1.jeune();
	}
	CHECK_FALSE(r1.meurt());
	r1.jeune();
	CHECK(r1.meurt());

	//test seReproduit() method
	r1.mange(lapinsVoisinsRenard);
	r1.mange(lapinsVoisinsRenard);
	int cl = 0;
	int cr = 0;
	unsigned seed = time(0);
	srand(seed);
	for(int i=0; i<10000; i++){
		if(l1.seReproduit(6)){
			cl++;
		}
		if(r1.seReproduit(2)){
			cr++;
		}
	}
	//2% accepted deviation
	CHECK(abs(cl-3000<200));
	CHECK(abs(cr-500<200));
	//cout << cl << endl;
	//cout << cr << endl;
}

TEST_CASE("testing Population class") {
	//test Population constructor
	Population p;

	//test reserve() method
	int id1 = p.reserve();
	CHECK(id1==0);
	int id2 = p.reserve();
	CHECK(id2==1);

	//test set() method
	Animal l1(id1,lapin,0);
	Animal r1(id2, renard, (TAILLEGRILLE * TAILLEGRILLE)-1);
	p.set(l1);
	p.set(r1);

	//test get() method
	CHECK(p.get(id1).getCoord().toInt()==0);
	CHECK(p.get(id1).getCoord().getLine()==0);
	CHECK(p.get(id1).getCoord().getColumn()==0);
	CHECK(p.get(id1).getEspece()==lapin);

	CHECK(p.get(id2).getCoord().toInt()==(TAILLEGRILLE * TAILLEGRILLE)-1);
	CHECK(p.get(id2).getCoord().getLine()==TAILLEGRILLE-1);
	CHECK(p.get(id2).getCoord().getColumn()==TAILLEGRILLE-1);
	CHECK(p.get(id2).getEspece()==renard);

	//test getIds() method
	Ensemble ids = p.getIds();
	CHECK(ids.cardinal()==2);
	CHECK(ids.contains(id1));
	CHECK(ids.contains(id2));

	//test supprime() method
	p.supprime(id1);
	CHECK(p.getIds().cardinal()==1);
	CHECK(p.getIds().contains(id2));
}

TEST_CASE("testing Grille class") {
//test constructor
	Grille g1;

	//test caseVide() method
	for(int i=0; i<TAILLEGRILLE; i++){
		for(int j=0; j<TAILLEGRILLE; j++){
			Coord *c1 = new Coord(i,j);
			CHECK(g1.caseVide(*c1));
			delete c1;
		}
	}

	//test reserveId() method
	int id1 = g1.reserveId();
	int id2 = g1.reserveId();
	int id3 = g1.reserveId();
	int id4 = g1.reserveId();

	Animal l1(id1,lapin,TAILLEGRILLE*TAILLEGRILLE-1);
	Animal l2(id2,lapin,TAILLEGRILLE-1);
	Animal r1(id3,renard,0);
	Animal r2(id4,renard,TAILLEGRILLE*TAILLEGRILLE-TAILLEGRILLE);
	
	//test setCase() method
	g1.setCase(l1);
	g1.setCase(l2);
	g1.setCase(r1);
	g1.setCase(r2);

	//test getCase() method
	Coord c1(TAILLEGRILLE*TAILLEGRILLE-1);
	Coord c2(TAILLEGRILLE-1);
	Coord c3(0);
	Coord c4(TAILLEGRILLE*TAILLEGRILLE-TAILLEGRILLE);
	CHECK(g1.getCase(c1)==0);
	CHECK(g1.getCase(c2)==1);
	CHECK(g1.getCase(c3)==2);
	CHECK(g1.getCase(c4)==3);

	//test getAnimal() method
	CHECK(g1.getAnimal(id1).toString()==l1.toString());
	CHECK(g1.getAnimal(id2).toString()==l2.toString());
	CHECK(g1.getAnimal(id3).toString()==r1.toString());
	CHECK(g1.getAnimal(id4).toString()==r2.toString());

	//test getIdentifiants()
	Ensemble IDS = g1.getIdentifiants();
	CHECK(IDS.cardinal() == 4);
	CHECK(IDS.contains(0));
	CHECK(IDS.contains(1));
	CHECK(IDS.contains(2));
	CHECK(IDS.contains(3));
	//cout << g1.getAnimal(0).toString() << endl;
	//cout << g1.getAnimal(1).toString() << endl;
	//cout << g1.getAnimal(2).toString() << endl;
	//cout << g1.getAnimal(3).toString() << endl;


	//test videCase() method
	g1.videCase(l1.getCoord());
	IDS = g1.getIdentifiants();
	CHECK(IDS.cardinal() == 3);
	CHECK_FALSE(IDS.contains(0));
	CHECK(IDS.contains(1));
	CHECK(IDS.contains(2));
	CHECK(IDS.contains(3));
	//cout << IDS << endl;
	//cout << g1.getAnimal(1).toString() << endl;
	//cout << g1.getAnimal(2).toString() << endl;
	//cout << g1.getAnimal(3).toString() << endl;
	
	//test toString() method
	//cout << g1.toString() << endl;
}

TEST_CASE("testing Jeu class"){
	//test constructor
	Jeu simulation(true);

	//test ajoutAnimal() method
	Coord c1(TAILLEGRILLE*TAILLEGRILLE-1);
	simulation.ajouteAnimal(lapin, c1);
	Coord c2(0);
	simulation.ajouteAnimal(renard, c2);
	Coord c3(TAILLEGRILLE-1);
	simulation.ajouteAnimal(lapin, c3);
	Coord c4(TAILLEGRILLE*TAILLEGRILLE-TAILLEGRILLE);
	simulation.ajouteAnimal(lapin, c4);
	Coord c5((TAILLEGRILLE/2)*(TAILLEGRILLE+1));
	simulation.ajouteAnimal(renard, c5);
	Coord c6((TAILLEGRILLE/2)*(TAILLEGRILLE));
	simulation.ajouteAnimal(lapin, c6);
	Coord c7((TAILLEGRILLE/3)*(TAILLEGRILLE+1));
	simulation.ajouteAnimal(renard, c7);
	cout << simulation << endl;

	//test proba constructor
	//unsigned seed = time(0);
	//srand(seed);
	//Jeu simulation2(false);
	//cout << simulation2 << endl;
}