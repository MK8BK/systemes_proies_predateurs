#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"

Ensemble::Ensemble(){
	card = 0;
}

bool Ensemble::estVide() const{
	return card==0;
}

int Ensemble::cardinal() const{
	return card;
}

int Ensemble::tire(){
	if(card==0){
		throw length_error("can't remove element from empty set");
	}
	srand(time(NULL));
	int position = rand() % card;
	int retiree = t[position];
	t[position] = t[card-1];
	card = card - 1;
	return retiree;
}

void Ensemble::ajoute(int elem){
	if(card == MAXCARD){
		throw invalid_argument("can't add element to set, full capacity MAXCARD="
			+to_string(MAXCARD)+" reached");
		return;
	}
	t[card] = elem;
	card = card+1;
}

int Ensemble::getElement(int pos) const{
	if(card==0){
		throw invalid_argument("no elements in empty set");
	}
	if(pos>=card or pos<0){
		throw invalid_argument("position "+to_string(pos)+" not in bounds [[0 , "
			+to_string(card-1)+"]]");
	}
	return t[pos];
}

void Ensemble::empty(){
	card = 0;
}

ostream &operator<<(ostream &out, const Ensemble &e){
	out << "{ ";
	for(int i = 0; i<e.cardinal(); i++){
		if(i==e.cardinal()-1){
			break;
		}
		out << e.getElement(i) << ", ";
	}
	if(e.estVide()){
		out << "}";
	}else{
		out << e.getElement(e.cardinal()-1) <<" }";		
	}
	return out;
}
