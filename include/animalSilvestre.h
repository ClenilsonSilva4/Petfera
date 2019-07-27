#ifndef ANIMALSILVESTRE_H
#define ANIMALSILVESTRE_H
#include <string>

//Classe criada para representar o objeto Animal Silvestre.
class AnimalSilvestre{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		std::string sil_AutorizIBAMA;

	public:
		//Construtor parametrizado.
		AnimalSilvestre(std::string _sil_AutorizIBAMA);
		//Construtor padrão.
		AnimalSilvestre(void);
		//Destrutor.
		~AnimalSilvestre(void);

		//Método virtual puro para ser implementado pelas classes derivadas.
		virtual std::string getAutorIBAMA(void) = 0;
};

#endif