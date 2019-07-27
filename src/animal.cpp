#include "animal.h"

Animal::Animal(int _ani_ID, std::string _ani_Classe, std::string _ani_NomeComum, std::string _ani_NomeCientifico, char _ani_Sexo,
			   double _ani_Tamanho, std::string _ani_Dieta, int _ani_Veterinario, int _ani_Tratador, std::string _ani_NomeBatismo){
	ani_ID = _ani_ID;
	ani_Classe = _ani_Classe;
	ani_NomeComum = _ani_NomeComum;
	ani_NomeCientifico = _ani_NomeCientifico;
	ani_Sexo = _ani_Sexo;
	ani_Tamanho = _ani_Tamanho;
	ani_Dieta = _ani_Dieta;
	ani_Veterinario = _ani_Veterinario;
	ani_Tratador = _ani_Tratador;
	ani_NomeBatismo = _ani_NomeBatismo;
}

Animal::Animal(void){
	
}

Animal::~Animal(void){
	//Destrutor
}

int Animal::getID(void){
	return ani_ID;
}

std::string Animal::getClasse(void){
	return ani_Classe;
}