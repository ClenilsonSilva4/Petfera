#ifndef MAMIFEROEXOTICO_H
#define MAMIFEROEXOTICO_H
#include "mamifero.h"
#include "animalExotico.h"

//Classe criada para representar o objeto Mamífero Exótico.
class MamiferoExotico: public Mamifero, AnimalExotico{
	public:
		//Construtor parametrizado.
		MamiferoExotico(int _mam_ID, std::string _mam_Classe, std::string _mam_NomeComum = "", std::string _mam_NomeCientifico = "", char _mam_Sexo = 'P',
						double _mam_Tamanho = 0, std::string _mam_Dieta = "", int _mam_Veter = 0, int _mam_Tratador = 0, std::string _mam_NomeBatismo = "",
						std::string _mam_CorPelo = "", std::string _mam_AutorizIBAMA = "", std::string _mam_PaisOrigem = "");
		//Construtor padrão.
		MamiferoExotico(void);
		//Destrutor.
		~MamiferoExotico(void);
		
		//Métodos para receber dados salvos de objetos do tipo Mamíferos Exótico.
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
		std::string getCorPelo(void);
		std::string getAutorIBAMA(void);
		std::string getPaisOrigem(void);
		//Sobrecarga do operador de inserção.
		friend std::ostream& operator<< (std::ostream &o, const MamiferoExotico maEx);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <MamiferoExotico> maEx);
};

#endif