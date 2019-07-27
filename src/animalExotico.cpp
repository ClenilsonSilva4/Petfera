#include "animalExotico.h"

AnimalExotico::AnimalExotico(std::string _exo_AutorizIBAMA, std::string _exo_PaisOrigem): AnimalSilvestre(_exo_AutorizIBAMA){
	exo_PaisOrigem = _exo_PaisOrigem;
}

AnimalExotico::AnimalExotico(void){
	
}

AnimalExotico::~AnimalExotico(void){
	//Destrutor
}