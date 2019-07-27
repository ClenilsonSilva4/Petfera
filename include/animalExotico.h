#ifndef ANIMALEXOTICO_H
#define ANIMALEXOTICO_H
#include "animalSilvestre.h"


//Classe criada para representar o objeto Animal Exótico.
class AnimalExotico: public AnimalSilvestre{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		std::string exo_PaisOrigem;
	public:
		//Construtor parametrizado.
		AnimalExotico(std::string _exo_AutorizIBAMA, std::string _exo_PaisOrigem);
		//Construtor padrão.
		AnimalExotico(void);
		//Destrutor.
		~AnimalExotico(void);
		
		//Método virtual puro para ser implementado pelas classes derivadas.
		virtual std::string getPaisOrigem(void) = 0;
};

#endif