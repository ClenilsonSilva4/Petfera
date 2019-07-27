#ifndef ANIMALNATIVO_H
#define ANIMALNATIVO_H
#include "animalSilvestre.h"

//Classe criada para representar o objeto Animal Nativo.
class AnimalNativo: public AnimalSilvestre{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		std::string nat_UF_Origem;
		std::string nat_LicTrans;
	public:
		//Construtor parametrizado.
		AnimalNativo(std::string _nat_AutorizIBAMA, std::string _nat_UFOrigem, std::string _nat_Autorizacao);
		//Construtor padrão.
		AnimalNativo(void);
		//Destrutor.
		~AnimalNativo(void);

		//Métodos virtuais puros para serem implementados pelas classes derivadas.
		virtual std::string getUF_Origem(void) = 0;
		virtual std::string getLicenTrans(void) = 0;
};

#endif