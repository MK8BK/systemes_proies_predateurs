#include <stdexcept>
#include <string>
#include <iostream>
#include "coord.hpp"
using namespace std;




Coord::Coord(int lig, int col){
	if(lig >= TAILLEGRILLE or lig<0){
		string error_message = "lign "+to_string(lig)
							+" not in grid of size "+to_string(TAILLEGRILLE)+"\n";
		throw invalid_argument(error_message);
		return;
	}
	if(col >= TAILLEGRILLE or col<0){
		string error_message = "column "+to_string(col)
							+" not in grid of size "+to_string(TAILLEGRILLE)+"\n";
		throw invalid_argument(error_message);
		return;
	}
	lign = lig;
	column = col;
}


Coord::Coord(int position){
	if(position > TAILLEGRILLE*TAILLEGRILLE -1){
		throw invalid_argument("position "+to_string(position)+
			" larger than t^2 - 1 = "+to_string(TAILLEGRILLE*TAILLEGRILLE-1));
	}
	column = position % TAILLEGRILLE;
	lign = position / TAILLEGRILLE;
}


int Coord::toInt() const{
	return TAILLEGRILLE*lign + column;
}


int Coord::getColumn() const{
	return column;
}

int Coord::getLine() const{
	return lign;
}

ostream &operator<<(ostream &out, const Coord &c){
    out << "("<< c.getLine() << ", " << c.getColumn() << ")";
    return out;
}


bool operator==(const Coord &c1, const Coord &c2){
	return (c1.getLine() == c2.getLine() and c1.getColumn() == c2.getColumn());
}

bool operator!=(const Coord &c1, const Coord &c2){
	return not(c1 == c2);
}