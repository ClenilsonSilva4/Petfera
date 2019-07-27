#ifndef VETERINARIO_H
#define VETERINARIO_H
#include "funcionario.h"

//Classe criada para representar o objeto Veterinário.
class Veterinario: public Funcionario{
	//Atributos privados da classe (podem ser acessados apenas por essa classe)
	private:
		std::string vet_CRMV;
	public:
		//Construtor parametrizado
		Veterinario(int _vet_ID, std::string _vet_Funcao, std::string _vet_Nome = "", std::string _vet_CPF = "", int _vet_Idade = 0,
					std::string _vet_TipoSanguineo = "", char _vet_FatorRH = 'P', std::string _vet_Especialidade = "", std::string _vet_CRMV = "");
		//Construtor padrão.
		Veterinario(void);
		//Destrutor
		~Veterinario(void);

		//Métodos para receber dados salvos de objetos do tipo Veterinário.
		int getID(void);
		std::string getFuncao(void);
		std::string getNome(void);
		std::string getCPF(void);
		int getIdade(void);
		std::string getTipoSanguineo(void);
		char getFatorRH(void);
		std::string getEspecialidade(void);
		std::string getCRMV(void);

		//Sobrecarga do operador de inserção.
		friend std::ostream& operator<< (std::ostream &o, const Veterinario vet);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <Veterinario> vet);
};

#endif