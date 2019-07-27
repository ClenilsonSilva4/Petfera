#include "anfibio.h"

Anfibio::Anfibio(int _anf_ID, std::string _anf_Classe, std::string _anf_NomeComum, std::string _anf_NomeCientifico, char _anf_Sexo,
				 double _anf_Tamanho, std::string _anf_Dieta, int _anf_Veterinario, int _anf_Tratador, std::string _anf_NomeBatismo,
				 int _anf_TotalMudas, std::string _anf_UltimaMuda): Animal(_anf_ID, _anf_Classe, _anf_NomeComum, _anf_NomeCientifico,
				 _anf_Sexo, _anf_Tamanho, _anf_Dieta, _anf_Veterinario, _anf_Tratador, _anf_NomeBatismo){
	anf_TotalMudas = _anf_TotalMudas;
	anf_UltimaMuda = _anf_UltimaMuda;
}

Anfibio::Anfibio(void){
	
}

Anfibio::~Anfibio(void){
	//Destrutor
}