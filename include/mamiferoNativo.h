#ifndef MAMIFERONATIVO_H
#define MAMIFERONATIVO_H
#include "mamifero.h"
#include "animalNativo.h"

//Classe criada para representar o objeto Mamífero Nativo.
class MamiferoNativo: public Mamifero, AnimalNativo{
	public:
		//Construtor parametrizado.
		MamiferoNativo(int _mam_ID, std::string _mam_Classe, std::string _mam_NomeComum = "", std::string _mam_NomeCientifico = "", char _mam_Sexo = 'P',
					   double _mam_Tamanho = 0, std::string _mam_Dieta = "", int _mam_Veter = 0, int _mam_Tratador = 0, std::string _mam_NomeBatismo = "",
					   std::string _mam_CorPelo = "", std::string _mam_AutorizIBAMA = "", std::string _mam_UFOrigem = "", std::string _mam_Autorizacao = "");
		//Construtor padrão.
		MamiferoNativo(void);
		//Destrutor.
		~MamiferoNativo(void);
		
		//Métodos para receber dados salvos de objetos do tipo Mamífero Nativo.
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
		std::string getUF_Origem(void);
		std::string getLicenTrans(void);

		//Sobrecarga do operador de inserção.
		friend std::ostream& operator<< (std::ostream &o, const MamiferoNativo maNa);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <MamiferoNativo> maNa);
};

#endif