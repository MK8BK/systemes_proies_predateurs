#ifndef INCLUDE_COORD_H
#define INCLUDE_COORD_H

#include <iostream>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"

class Coord {
	private:
		//private members go here
		int lign, column;

	public:
		//public memembers go here
		int getLine() const;
		int getColumn() const;
		int toInt() const;
		Coord(int lig, int col);
		Coord(int position);
		Ensemble voisines() const;

};

ostream &operator<<(ostream &out, const Coord &c);
bool operator==(const Coord &c1, const Coord &c2);
bool operator!=(const Coord &c1, const Coord &c2);

#endif