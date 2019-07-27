#include "mamifero.h"

Mamifero::Mamifero(int _mam_ID, std::string _mam_Classe, std::string _mam_NomeComum, std::string _mam_NomeCientifico, char _mam_Sexo,
				   double _mam_Tamanho, std::string _mam_Dieta, int _mam_Veterinario, int _mam_Tratador, std::string _mam_NomeBatismo,
				   std::string _mam_CorPelo): Animal(_mam_ID, _mam_Classe, _mam_NomeComum, _mam_NomeCientifico, _mam_Sexo, _mam_Tamanho,
				   _mam_Dieta, _mam_Veterinario, _mam_Tratador, _mam_NomeBatismo){
	mam_CorPelo = _mam_CorPelo;
}

Mamifero::Mamifero(void){
	
}

Mamifero::~Mamifero(void){
	//Destrutor
}