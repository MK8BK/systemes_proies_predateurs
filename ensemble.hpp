#ifndef INCLUDE_ENSEMBLE_H
#define INCLUDE_ENSEMBLE_H

#include <iostream>
using namespace std;

#include "constantes.hpp"


class Ensemble {
	private:
		//private members go here
		static const int MAXCARD = TAILLEGRILLE*TAILLEGRILLE + 1;
		int card;
		int t[MAXCARD];

	public:
		//public memembers go here
		Ensemble();
		bool estVide() const;
		int cardinal() const;
		void ajoute(int elem);
		int tire();
		//for usage in the << operator
		int getElement(int pos) const;
		void empty();
};

ostream &operator<<(ostream &out, const Ensemble &e);

#endif