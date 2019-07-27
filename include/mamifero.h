#ifndef MAMIFERO_H
#define MAMIFERO_H
#include "animal.h"

//Classe criada para representar o objeto mamífero
class Mamifero: public Animal{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas)
	protected:
		std::string mam_CorPelo;
	public:
		//Construtor parametrizado.
		Mamifero(int _mam_ID, std::string _mam_Classe, std::string _mam_NomeComum, std::string _mam_NomeCientifico, char _mam_Sexo,
				 double _mam_Tamanho, std::string _mam_Dieta, int _mam_Veterinario, int _mam_Tratador, std::string _mam_NomeBatismo,
				 std::string _mam_CorPelo);
		//Construtor padrão.
		Mamifero(void);
		//Destrutor.
		~Mamifero(void);

		//Método virtual puro para ser implementado pelas classes derivadas.
		virtual std::string getCorPelo(void) = 0;
};

#endif