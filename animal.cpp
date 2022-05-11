#include <string>
#include <iostream>
#include <exception>
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

string Animal::toString() const{
	string representation = tostring(e)+" "+to_string(id)+", ("+to_string(c.getLine())+
		", "+to_string(c.getColumn())+")";
	return representation;
}

void Animal::setCoord(Coord &newCoord){
	c = newCoord;
}

//void Animal::seReproduit(){
//	return;
//}

//void Animal::jeune(){
//	return;
//}

//void Animal::mange(){
//	return;
//}

bool Animal::meurt(){
	if(e==renard){
		cout << foodlevel << endl;
		if(foodlevel==0){
			return true;
		}
		return false;
	}
	return true;
}

//ostream &operator << ( ostream& out, Espece E ){
//   const string nameEE[] = { "lapin", "renard" };
//   return out << nameEE[E];
//}

string tostring(Espece e){
    if(e==renard){
    	return "renard";
    }
    return "lapin";
}