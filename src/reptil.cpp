#include "reptil.h"
//Construtor parametrizado
Reptil::Reptil(int _rep_ID, std::string _rep_Classe, std::string _rep_NomeComum, std::string _rep_NomeCientifico, char _rep_Sexo,
			   double _rep_Tamanho, std::string _rep_Dieta, int _rep_Veterinario, int _rep_Tratador, std::string _rep_NomeBatismo,
			   bool _rep_Venenoso, std::string _rep_TipoVeneno): Animal(_rep_ID, _rep_Classe, _rep_NomeComum, _rep_NomeCientifico,
			   _rep_Sexo, _rep_Tamanho, _rep_Dieta, _rep_Veterinario, _rep_Tratador, _rep_NomeBatismo){
	 rep_Venenoso = _rep_Venenoso;
	 rep_TipoVeneno = _rep_TipoVeneno;
}

Reptil::Reptil(void){
	
}

Reptil::~Reptil(void){
	//Destrutor
}