#ifndef INCLUDE_TAILLEGRILLE_H
#define INCLUDE_TAILLEGRILLE_H

//grille
static const int TAILLEGRILLE = 20;

//renards
static const int FoodInit = 5;
static const int FoodLapin = 5;
static const int FoodReprod = 8;
static const int MaxFood = 10;
static const float ProbBirthRenard = 0.05;

//lapins
static const float ProbBirthLapin = 0.30;
static const int MinFreeBirthLapin = 4;

//cout colors
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

#endif