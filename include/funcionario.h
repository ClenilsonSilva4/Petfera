#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <memory>
#include "excecoes.h"

const char delimit = ';';

//Classe criada para representar o objeto Funcionário.
class Funcionario{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		int fun_ID;
		std::string fun_Funcao;
		std::string fun_Nome;
		std::string fun_CPF;
		int fun_Idade;
		std::string fun_TipoSanguineo;
		char fun_FatorRH;
		std::string fun_Especialidade;
	public:
		//Construtor parametrizado.
		Funcionario(int _fun_ID, std::string _fun_Funcao, std::string _fun_Nome, std::string _fun_CPF, int _fun_Idade,
					std::string _fun_TipoSanguineo, char _fun_FatorRH, std::string _fun_Especialidade);
		//Construtor padrão.
		Funcionario(void);
		//Destrutor.
		~Funcionario(void);

		//Métodos virtuais puros para serem implementados pelas classes derivadas.
		virtual int getID(void);
		virtual std::string getFuncao(void) = 0;
		virtual std::string getNome(void) = 0;
		virtual std::string getCPF(void) = 0;
		virtual int getIdade(void) = 0;
		virtual std::string getTipoSanguineo(void) = 0;
		virtual char getFatorRH(void) = 0;
		virtual std::string getEspecialidade(void) = 0;
};

#endif