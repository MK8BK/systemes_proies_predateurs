#include <stdexcept>
#include <string>
#include <iostream>
#include "taillegrille.hpp"
#include "ensemble.hpp"
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

Ensemble Coord::voisines() const{
	Ensemble e;
	//lign, column available
	int imin = max(lign - 1, 0);
	int imax = min(lign+1, TAILLEGRILLE-1);
	int jmin = max(column - 1, 0);
	int jmax = min(column+1, TAILLEGRILLE-1);
	for(int i=imin; i<=imax; i++){
		for(int j=jmin; j<=jmax; j++){
			if(i!= lign or j!= column){
				e.ajoute(Coord {i,j}.toInt());
			}
		}
	}
	return e;
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