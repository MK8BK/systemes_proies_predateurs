//#include <stdexcept>
#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"
#include "population.hpp"
#include "grille.hpp"
#include "jeu.hpp"


void Jeu::ajouteAnimal(Espece e, Coord c){
	int id = g.reserveId();
	Animal a(id, e, c.toInt());
	g.setCase(a);
}

Jeu::Jeu(bool vide){
	if(vide){
		return;
	}
	int probLapin = 0.2*100;
	int probRenard = 0.07*100;
	for(int i=0; i<TAILLEGRILLE; i++){
		for(int j=0; j<TAILLEGRILLE; j++){

			//int probVide = 0.73*100;
			bool choix = (rand() % 100);

			cout << choix<< endl;
			cout << probLapin << " " << probRenard<<endl;
			if(choix<probRenard){
				Coord *c = new Coord(i,j);
				ajouteAnimal(renard, *c);
				//delete c;
				continue;
			}else if(choix<probLapin+probRenard){
				Coord *c = new Coord(i,j);
				ajouteAnimal(lapin, *c);
				//delete c;
				continue;
			}
		}
	}
}

//void verifieGrille(){
//}
//
//Ensemble voisinsVides(){
//}
//
//Ensemble voisinsLapins(){
//}
//
//void deplace(int identifiant, Coord nc){
//}
//
//void deplaceAleatoirement(int identifiant){
//}
//
//void mange(int identifiant, int identifiant){
//}
//
//void evolueLapin(int identifiant){
//}
//
//void evolueRenard(int identifiant){
//}//


string Jeu::toString(){
	return g.toString();
}


ostream &operator<<(ostream &out,Jeu &j){
	string representation = j.toString();
	//out << representation;
	//return out;
	//cout << representation;
	for(char c:representation){
		if(c=='\n'){
			out << '\n';
		}
		if(c=='L'){
			out << cyan << 'L' << reset;
			continue;
		}else if(c=='R'){
			out << red << 'R' << reset;
			continue;
		}else{
			out << "  ";
			continue;
		}
	}
	return out;
}