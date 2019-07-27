#include "animalNativo.h"

AnimalNativo::AnimalNativo(std::string _nat_AutorizIBAMA, std::string _nat_UF_Origem, std::string _nat_LicTrans):
						   AnimalSilvestre(_nat_AutorizIBAMA){
	nat_UF_Origem = _nat_UF_Origem;
	nat_LicTrans = _nat_LicTrans;
}

AnimalNativo::AnimalNativo(void){
	
}

AnimalNativo::~AnimalNativo(void){
	//Destrutor
}