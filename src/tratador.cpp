#include "tratador.h"

Tratador::Tratador(int _tra_ID, std::string _tra_Funcao, std::string _tra_Nome, std::string _tra_CPF, int _tra_Idade, std::string _tra_TipoSanguineo,
				   char _tra_FatorRH, std::string _tra_Especialidade, int _tra_NivelSeguranca): Funcionario(_tra_ID, _tra_Funcao, _tra_Nome, _tra_CPF,
				   _tra_Idade, _tra_TipoSanguineo, _tra_FatorRH, _tra_Especialidade){
	tra_NivelSeguranca = _tra_NivelSeguranca;
}

Tratador::Tratador(void){
	
}

Tratador::~Tratador(void){
	//Destrutor
}

int Tratador::getID(void){
	return fun_ID;
}

std::string Tratador::getFuncao(void){
	return fun_Funcao;
}

std::string Tratador::getNome(void){
	return fun_Nome;
}

std::string Tratador::getCPF(void){
	return fun_CPF;
}

int Tratador::getIdade(void){
	return fun_Idade;
}

std::string Tratador::getTipoSanguineo(void){
	return fun_TipoSanguineo;
}

char Tratador::getFatorRH(void){
	return fun_FatorRH;
}

std::string Tratador::getEspecialidade(void){
	return fun_Especialidade;
}

int Tratador::getNivelSeguranca(void){
	return tra_NivelSeguranca;
}

std::ostream& operator<<(std::ostream &o, const Tratador tra){
	o << "ID: " << tra.fun_ID << delimit << std::endl << "Função: " << tra.fun_Funcao << delimit << std::endl << "Nome: " << tra.fun_Nome << delimit
	  << std::endl << "CPF: " << tra.fun_CPF << delimit << std::endl << "Idade: " << tra.fun_Idade << delimit << std::endl << "Tipo Sanguíneo: "
	  << tra.fun_TipoSanguineo << tra.fun_FatorRH << delimit << std::endl << "Especialidade de Animais: " << tra.fun_Especialidade << delimit << std::endl
	  << "Nível de Segurança: " << tra.tra_NivelSeguranca << delimit << std::endl;
	return o;
}

std::istream& operator>>(std::istream &i, std::shared_ptr <Tratador> tra){
	std::string cad_aux;
	bool condicao = true;

	tra->fun_Funcao = "Tratador";
	
	/*A partir desse ponto, serão usados condicionais para verificar se já há alguma informação salva no objeto para saber se tem que adicionar um novo
	dado ou perguntar se quer alterar o existente. Ambos os condicionais e laços tem tratamento de exceções para garantir que sempre receba o dado correto
	para o tipo de dado que se está solicitando.*/
	if(tra->fun_Nome.size() != 0){
		do{
			std::cout << "Quer Alterar o Nome do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Nome do Funcionario." << std::endl;
		std::getline(std::cin, tra->fun_Nome);
		try{
			if(tra->fun_Nome.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	/*Essa modificação do valor de "condicional", existente no início de cada laço a partir de agora, é para garantir que o laço será iniciado
	caso a sobrecarga não esteja sendo usada para alteração.*/
	condicao = true;
	if(tra->fun_Idade != 0){
		do{
			std::cout << "Quer Alterar a Idade do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira a Idade do Funcionario." << std::endl;
		std::getline(std::cin, cad_aux);
		try{
			tra->fun_Idade = std::stoi(cad_aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(tra->fun_CPF.size() != 0){
		do{
			std::cout << "Quer Alterar o CPF do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o CPF do Funcionario. (000.000.000-00)" << std::endl;
		std::getline(std::cin, tra->fun_CPF);
		try{
			if(tra->fun_CPF.size() != 14) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(tra->fun_TipoSanguineo.size() != 0){
		do{
			std::cout << "Quer Alterar o Tipo Sanguíneo do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Tipo Sanguíneo do Funcionario." << std::endl;
		std::getline(std::cin, tra->fun_TipoSanguineo);
		try{
			if(tra->fun_TipoSanguineo.size() == 0) throw ErroCadastro();
			if(!(tra->fun_TipoSanguineo.compare("AB") == 0 || tra->fun_TipoSanguineo.compare("A") == 0 ||
				 tra->fun_TipoSanguineo.compare("B") == 0 || tra->fun_TipoSanguineo.compare("O") == 0)) throw ErroCadastro();
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(tra->fun_FatorRH != 'P'){
		do{
			std::cout << "Quer Alterar o Fator RH do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Fator RH do Funcionario. (- ou +)" << std::endl;
		std::getline(std::cin, cad_aux);
		tra->fun_FatorRH = cad_aux[0];
		try{
			if(!(tra->fun_FatorRH == '-' || tra->fun_FatorRH == '+')) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(tra->fun_Especialidade.size() != 0){
		do{
			std::cout << "Quer Alterar a Especialidade do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira a Especialidade do Funcionario." << std::endl;
		std::getline(std::cin, tra->fun_Especialidade);
		try{
			if(tra->fun_Especialidade.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(tra->tra_NivelSeguranca != 0){
		do{
			std::cout << "Quer Alterar o Nível de Segurança do Funcionário? Digite S ou N." << std::endl;
			std::getline(std::cin, cad_aux);
			try{
				if(!(cad_aux[0] == 'S' || cad_aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(cad_aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Digite o Nível de Segurança do Tratador:" << std::endl;
		std::getline(std::cin, cad_aux);
		try{
			tra->tra_NivelSeguranca = std::stoi(cad_aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	return i;
}