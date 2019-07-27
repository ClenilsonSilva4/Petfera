#ifndef REPTIL_H
#define REPTIL_H
#include "animal.h"

//Classe criada para representar o objeto Réptil.

class Reptil: public Animal{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		bool rep_Venenoso;
		std::string rep_TipoVeneno;
	public:
		//Construtor parametrizado.
		Reptil(int _rep_ID, std::string _rep_Classe, std::string _rep_NomeComum, std::string _rep_NomeCientifico, char _rep_Sexo,
			   double _rep_Tamanho, std::string _rep_Dieta, int _rep_Veterinario, int _rep_Tratador, std::string _rep_NomeBatismo,
			   bool rep_Venenoso, std::string rep_TipoVeneno);
		//Construtor padrão.
		Reptil(void);
		//Destrutor
		~Reptil(void);

		//Métodos virtuais puros para serem implementados pelas classes derivadas.
		virtual bool getVenenoso(void) = 0;
		virtual std::string getTipoVeneno(void) = 0;
};

#endif