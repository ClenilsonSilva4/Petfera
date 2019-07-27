#ifndef ANFIBIONATIVO_H
#define ANFIBIONATIVO_H
#include "anfibio.h"
#include "animalNativo.h"

//Classe criada para representar o objeto Anfibio Nativo.
class AnfibioNativo: public Anfibio, AnimalNativo{
	
	public:
		//Construtor parametrizado.
		AnfibioNativo(int _anf_ID, std::string _anf_Classe, std::string _anf_NomeComum = "", std::string _anf_NomeCientifico = "", char _anf_Sexo= 'P',
					  double _anf_Tamanho = 0, std::string _anf_Dieta = "", int _anf_Veterinario = 0, int _anf_Tratador = 0,
					  std::string _anf_NomeBatismo = "", int _anf_TotalMudas = 0, std::string _anf_UltimaMuda = "", std::string _anf_AutorIBAMA = "",
					  std::string _anf_PaisOrigem = "", std::string _anf_LicenTrans = "");
		//Construtor padrão.
		AnfibioNativo(void);
		//Destrutor.
		~AnfibioNativo(void);

		//Métodos para receber dados salvos de objetos do tipo Anfíbios Nativo.
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
		int getTotalMudas(void);
		std::string getDataUltimaMuda(void);
		std::string getAutorIBAMA(void);
		std::string getUF_Origem(void);
		std::string getLicenTrans(void);

		//Sobrecarga do operador de inserção.
		friend std::ostream& operator<< (std::ostream &o, const AnfibioNativo anNa);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <AnfibioNativo> anNa);
};

#endif