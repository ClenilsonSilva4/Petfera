#ifndef REPTILEXOTICO_H
#define REPTILEXOTICO_H
#include "reptil.h"
#include "animalExotico.h"

//Classe criada para representar o objeto Réptil Exótico
class ReptilExotico: public Reptil, AnimalExotico{
	public:
		//Construtor parametrizado.
		ReptilExotico(int _rep_ID, std::string _rep_Classe, std::string _rep_NomeComum = "", std::string _rep_NomeCientifico = "", char _rep_Sexo = 'P',
					  double _rep_Tamanho = 0, std::string _rep_Dieta = "", int _rep_Veterinario = 0, int _rep_Tratador = 0, std::string _rep_NomeBatismo = "",
					  bool rep_Venenoso = false, std::string rep_TipoVenenoso = "", std::string _rep_AutorizIBAMA = "", std::string _rep_PaisOrigem = "");
		//Construtor padrão.
		ReptilExotico(void);
		//Destrutor.
		~ReptilExotico(void);

		//Métodos para receber dados salvos de objetos do tipo Réptil Exótico.
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
		bool getVenenoso(void);
		std::string getTipoVeneno(void);
		std::string getAutorIBAMA(void);
		std::string getPaisOrigem(void);

		//Sobrecarga do operador de inserção.
		friend std::ostream& operator<< (std::ostream &o, const ReptilExotico reEx);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <ReptilExotico> reEx);
};

#endif