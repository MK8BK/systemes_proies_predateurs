#ifndef INCLUDE_POPULATIONS_H
#define INCLUDE_POPULATIONS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "constantes.hpp"
#include "ensemble.hpp"
#include "coord.hpp"
#include "animal.hpp"


class Population {
	private:
		//private members go here
		Ensemble identifiants;
		vector<Animal> faune;


	public:
		//public memembers go here
		Population();
		Animal get(int identifiant);
		Ensemble getIds();
		int reserve();
		void set(Animal &a);
		void supprime(int identifiant);
};


#endif

