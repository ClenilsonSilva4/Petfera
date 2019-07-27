#ifndef AVEEXOTICA_H
#define AVEEXOTICA_H
#include "ave.h"
#include "animalExotico.h"


//Classe criada para representar o objeto Ave Exótica.
class AveExotica: public Ave, AnimalExotico{
	public:
		//Construtor parametrizado
		AveExotica(int _av_ID, std::string _av_Classe, std::string _av_NomeComum = "", std::string _av_NomeCientifico = "", char _av_Sexo = 'P',
				   double _av_Tamanho = 0, std::string _av_Dieta = "", int _av_Veterinario = 0, int _av_Tratador = 0, std::string _av_NomeBatismo = "",
				   double _av_TamanhoBico = 0, double _av_EnvergaduraAsas = 0, std::string _av_AutorIBAMA = "", std::string _av_PaisOrigem = "");
		//Construtor padrão.
		AveExotica(void);
		//Destrutor
		~AveExotica(void);

		//Métodos para receber dados salvos de objetos do tipo Ave Exótica.
		int getID(void);
		std::string getClasse(void);
		std::string getNomeComum(void);
		std::string getNomeCientifico(void);
		char getSexo(void);
		double getTamanho(void);
		std::string getDieta(void);
		int getVeterinarioID(void);
		int getTratadorID(void);
		std::string getNomeBatismo(void);
		double getTamanhoBico(void);
		double getEnvergadura(void);
		std::string getAutorIBAMA(void);
		std::string getPaisOrigem(void);

		//Sobrecarga do operador de inserção.
		friend std::ostream& operator<< (std::ostream &o, const AveExotica avEx);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <AveExotica> avEx);
};

#endif