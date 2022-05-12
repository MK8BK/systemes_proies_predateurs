
//#include <stdexcept>
#include <string>
#include <iostream>
#include <exception>
//#include <stdlib.h>
//#include <time.h>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"
#include "population.hpp"
#include "grille.hpp"



Grille::Grille(){
	for(int i=0; i<TAILLEGRILLE; i++){
		for(int j=0; j<TAILLEGRILLE; j++){
			g[i][j] = -1;
		}
	}
}

bool Grille::caseVide(Coord c) const{
	if(g[c.getLine()][c.getColumn()]==-1){
		return true;
	}
	return false;
}

int Grille::getCase(Coord c) const{
	return g[c.getLine()][c.getColumn()];
}

void Grille::videCase(Coord c){
	int identifiant = g[c.getLine()][c.getColumn()];
	if(identifiant==-1){
		throw invalid_argument("coordinate already empty");
	}
	p.supprime(identifiant);
	g[c.getLine()][c.getColumn()] = -1;
}

int Grille::reserveId(){
	return p.reserve();
}

Animal Grille::getAnimal(int identifiant){
	return p.get(identifiant);
}

Ensemble Grille::getIdentifiants(){
	return p.getIds();
}


void Grille::setCase(Animal &a){
	if(not caseVide(a.getCoord())){
		throw runtime_error("non empty position, can't overwite animal with another");
	}
	p.set(a);
	g[a.getCoord().getLine()][a.getCoord().getColumn()] = a.getId();

}


string Grille::toString(){
	Ensemble ids = p.getIds();
	string representation = "\n";
	for(int i=0; i<TAILLEGRILLE; i++){
		for(int j=0; j<TAILLEGRILLE; j++){
			if(ids.contains(g[i][j])){
				Animal a = p.get(g[i][j]);
				if(a.getEspece()==lapin){
					representation = representation + "L";
					continue;
				}
				representation = representation + "R";
				continue;
			}
			representation = representation + " ";
			continue;
		}
		representation = representation+"\n";
	}
	return representation;
}