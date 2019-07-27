#ifndef TRATADOR_H
#define TRATADOR_H
#include "funcionario.h"

//Classe criada para representar o objeto tratador.
class Tratador: public Funcionario{
	//Atributos privados da classe (podem ser acessados apenas por essa classe).
	private:
		int tra_NivelSeguranca;
	public:
		//Construtor parametrizado
		Tratador(int _tra_ID, std::string _tra_Funcao, std::string _tra_Nome = "", std::string _tra_CPF = "", int _tra_Idade = 0,
				 std::string _tra_TipoSanguineo = "", char _tra_FatorRH = 'P', std::string _tra_Especialidade = "", int _tra_NivelSeguranca = 0);
		Tratador(void);
		//Destrutor
		~Tratador(void);

		//Métodos para receber dados dos tratadores salvos no objeto.
		int getID(void);
		std::string getFuncao(void);
		std::string getNome(void);
		std::string getCPF(void);
		int getIdade(void);
		std::string getTipoSanguineo(void);
		char getFatorRH(void);
		std::string getEspecialidade(void);
		int getNivelSeguranca(void);

		//Sobrecarga do operadore de inserção.
		friend std::ostream& operator<< (std::ostream &o, const Tratador tra);
		//Sobrecarga do operador de extração.
		friend std::istream& operator>> (std::istream &i, std::shared_ptr <Tratador> tra);
};

#endif