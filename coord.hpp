//#include <iostream>
//#include <string>
//using namespace std;
#ifndef INCLUDE_COORD_H
#define INCLUDE_COORD_H
static const int TAILLEGRILLE = 20;
#include <iostream>

class Coord {
	private:
		//private members go here
		int lign, column;

	public:
		//public memembers go here
		int getLine();
		int getColumn();
		Coord(int lig, int col);

};
ostream &operator<<(ostream &out, const Coord &c);
//std::ostream& operator<<(std::ostream&, const Math::Matrix&);
#endif
