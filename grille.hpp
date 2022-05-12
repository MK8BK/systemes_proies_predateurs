#ifndef INCLUDE_GRILLE_H
#define INCLUDE_GRILLE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"
#include "population.hpp"


class Grille {
	private:
		//private members go here
		int g[TAILLEGRILLE][TAILLEGRILLE];
		Population p;

	public:
		//public memembers go here
		Grille();
		bool caseVide(Coord c) const;
		int getCase(Coord c) const;
		void videCase(Coord c);
		int reserveId();
		void setCase(Animal &a);
		Animal getAnimal(int identifiant);
		Ensemble getIdentifiants();
		string toString();
};


#endif

