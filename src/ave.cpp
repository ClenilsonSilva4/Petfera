#include "ave.h"

Ave::Ave(int _av_ID, std::string _av_Classe, std::string _av_NomeComum, std::string _av_NomeCientifico, char _av_Sexo,
		 double _av_Tamanho, std::string _av_Dieta, int _av_Veterinario, int _av_Tratador, std::string _av_NomeBatismo,
		 double _av_TamanhoBico, double _av_EnvergaduraAsas): Animal(_av_ID, _av_Classe, _av_NomeComum, _av_NomeCientifico, _av_Sexo,
		 _av_Tamanho, _av_Dieta, _av_Veterinario, _av_Tratador, _av_NomeBatismo){
	av_TamanhoBico =  _av_TamanhoBico;
	av_EnvergaduraAsas = _av_EnvergaduraAsas;
}

Ave::Ave(void){
	
}

Ave::~Ave(void){
	//Destrutor
}