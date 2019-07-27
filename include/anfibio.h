#ifndef ANFIBIO_H
#define ANFIBIO_H
#include "animal.h"


//Classe criada para representar o objeto Anfibio.
class Anfibio: public Animal{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		int anf_TotalMudas;
		std::string anf_UltimaMuda;
	
	public:
		//Construtor parametrizado.
		Anfibio(int _anf_ID, std::string _anf_Classe, std::string _anf_NomeComum, std::string _anf_NomeCientifico, char _anf_Sexo,
				double _anf_Tamanho, std::string _anf_Dieta, int _anf_Veterinario, int _anf_Tratador, std::string _anf_NomeBatismo,
				int _anf_TotalMudas, std::string _anf_UltimaMuda);
		//Construtor padrão.
		Anfibio(void);
		//Destrutor.
		~Anfibio(void);

		//Métodos virtuais puros para serem implementados pelas classes derivadas.
		virtual int getTotalMudas(void) = 0;
		virtual std::string getDataUltimaMuda(void) = 0;
};

#endif