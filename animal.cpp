#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"

Animal::Animal(int identifiant, Espece espece, int position):id(identifiant), c(position){
	e = espece;
	if(espece==renard){
		foodlevel = FoodInit;
	}
}

int Animal::getId() const{
	return id;
}

Coord Animal::getCoord() const{
	return c;
}

Espece Animal::getEspece() const{
	return e;
}

int Animal::getFoodLevel() const{
	return foodlevel;
}


string Animal::toString() const{
	string representation = tostring(e)+" "+to_string(id)+", ("+to_string(c.getLine())+
		", "+to_string(c.getColumn())+")";
	return representation;
}

void Animal::setCoord(Coord &newCoord){
	c = newCoord;
}

void Animal::jeune(){
	foodlevel = foodlevel - 1;
}

void Animal::mange(Ensemble voisines){
	//voisines contenant des lapins
	//Ensemble de coordonees en int unique
	int choix = rand() % voisines.cardinal();
	foodlevel = foodlevel+FoodLapin;
	Coord cn(voisines.getElement(choix));
	setCoord(cn);
}

bool Animal::meurt() const{
	if(e==renard){
		//cout << foodlevel << endl;
		if(foodlevel<1){
			return true;
		}
		return false;
	}
	return false;
}

bool Animal::seReproduit(int voisinsVides){
	//srand(time(NULL));
	if(e==lapin and voisinsVides>=MinFreeBirthLapin){
		int prob = ProbBirthLapin*100;
		bool sereproduit = (rand() % 100) < prob;
		return sereproduit;
	}else{
		if(e==renard and foodlevel>=FoodReprod){
			int prob = ProbBirthRenard*100;
			bool sereproduit = (rand() % 100) < prob;
			return sereproduit;
		}
	}
	return false;
}

string tostring(Espece e){
    if(e==renard){
    	return "renard";
    }else if(e==lapin){
	    return "lapin";
	}
	return "animal";
}