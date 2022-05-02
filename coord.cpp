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

Coord::getColumn(){
	return column;
}

Coord::getLine(){
	return lign;
}

ostream &operator<<(ostream &out, const Coord &c){
    out << "("<< c.getLine() << ', ' << c.getColumn() << ')';
    return out;
}