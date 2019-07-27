#include "funcionario.h"

Funcionario::Funcionario(int _fun_ID, std::string _fun_Funcao, std::string _fun_Nome, std::string _fun_CPF, int _fun_Idade,
						 std::string _fun_TipoSanguineo, char _fun_FatorRH, std::string _fun_Especialidade){
	fun_ID = _fun_ID;
	fun_Funcao = _fun_Funcao;
	fun_Nome = _fun_Nome;
	fun_CPF = _fun_CPF;
	fun_Idade = _fun_Idade;
	fun_TipoSanguineo = _fun_TipoSanguineo;
	fun_FatorRH = _fun_FatorRH;
	fun_Especialidade = _fun_Especialidade;
}

Funcionario::Funcionario(void){
	
}

Funcionario::~Funcionario(void){
	//Destrutor
}

int Funcionario::getID(void){
	return fun_ID;
}