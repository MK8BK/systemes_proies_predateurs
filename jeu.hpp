#ifndef INCLUDE_JEU_H
#define INCLUDE_JEU_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"
#include "population.hpp"
#include "grille.hpp"

class Jeu {
	private:
		//private members go here
	Grille g;


	public:
		//public memembers go here
		void ajouteAnimal(Espece e, Coord c);
		string toString();
		Jeu(bool vide);
		//void verifieGrille();
		//Ensemble voisinsVides();
		//Ensemble voisinsLapins();
		//void deplace(int identifiant, Coord nc);
		//void deplaceAleatoirement(int identifiant);
		//void mange(int identifiant, int identifiant);
		//void evolueLapin(int identifiant);
		//void evolueRenard(int identifiant);
};

ostream &operator<<(ostream &out, Jeu &j);

#endif