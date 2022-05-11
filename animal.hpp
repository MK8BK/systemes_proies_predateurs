#ifndef INCLUDE_ANIMAL_H
#define INCLUDE_ANIMAL_H

#include <iostream>
#include <string>
#include "coord.hpp"

#include "constantes.hpp"
#include "ensemble.hpp"
using namespace std;


enum Espece{lapin, renard, animal};

class Animal {
	private:
		//private members go here
		const int id;
		Espece e;
		Coord c;
		int foodlevel;

	public:
		//public memembers go here
		Animal(int identifiant, Espece espece, int position);
		int getId() const;
		Coord getCoord() const;
		Espece getEspece() const;
		int getFoodLevel() const;
		string toString() const;
		void setCoord(Coord &newCoord);
		void jeune();
		void mange(Ensemble voisines);
		bool meurt() const;
		bool seReproduit(int voisinsVides);
		Animal& operator=(const Animal&) { return *this; }
};

//ostream &operator<<(ostream& out, Espece E);
string tostring(Espece e);
#endif

