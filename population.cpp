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



Population::Population(){
	return;
}

int Population::reserve(){
	for(int i=0; i<=identifiants.cardinal(); i++){
		if(not identifiants.contains(i)){
			identifiants.ajoute(i);
			return i;
		}
	}
	throw runtime_error("no unique id could be generated, you dun goofed up");
}

void Population::set(Animal &a){
	if(identifiants.contains(a.getId())){
		faune.push_back(a);
		return;
	}
	throw invalid_argument("animal space was not reserved");

}

void Population::supprime(int identifiant){
	if(not identifiants.contains(identifiant)){
		throw invalid_argument("animal not in population");
	}
	identifiants.removeElement(identifiant);
	for(std::size_t i=0; i<faune.size(); i++){
		if(faune[i].getId()==identifiant){
			faune.erase(faune.begin()+i);
			return;
		}
	}
	throw runtime_error("animal id exists, but no animal structure in population found");
	return;
}


Animal Population::get(int identifiant){
	if(identifiants.contains(identifiant)){
		for(unsigned i=0; i!=faune.size(); i++){
			if(faune[i].getId() == identifiant){
				Animal b(faune[i].getId(), faune[i].getEspece(), faune[i].getCoord().toInt());
				return b;
			}
		}
	}
	throw invalid_argument("no such animal in popultion");
}

Ensemble Population::getIds(){
	return identifiants;
}



//v.erase(v.begin()+6)