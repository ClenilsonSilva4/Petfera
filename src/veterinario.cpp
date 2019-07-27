#include "veterinario.h"

Veterinario::Veterinario(int _vet_ID, std::string _vet_Funcao, std::string _vet_Nome, std::string _vet_CPF, int _vet_Idade, std::string _vet_TipoSanguineo,
						 char _vet_FatorRH, std::string _vet_Especialidade, std::string _vet_CRMV): Funcionario(_vet_ID, _vet_Funcao, _vet_Nome, _vet_CPF,
						 _vet_Idade, _vet_TipoSanguineo, _vet_FatorRH, _vet_Especialidade){
	vet_CRMV = _vet_CRMV;
}

Veterinario::Veterinario(void){
	
}

Veterinario::~Veterinario(void){
	//Destrutor
}

int Veterinario::getID(void){
	return fun_ID;
}

std::string Veterinario::getFuncao(void){
	return fun_Funcao;
}

std::string Veterinario::getNome(void){
	return fun_Nome;
}

std::string Veterinario::getCPF(void){
	return fun_CPF;
}

int Veterinario::getIdade(void){
	return fun_Idade;
}

std::string Veterinario::getTipoSanguineo(void){
	return fun_TipoSanguineo;
}

char Veterinario::getFatorRH(void){
	return fun_FatorRH;
}

std::string Veterinario::getEspecialidade(void){
	return fun_Especialidade;
}

std::string Veterinario::getCRMV(void){
	return vet_CRMV;
}

std::ostream& operator<<(std::ostream &o, const Veterinario vet){
	o << "ID: " << vet.fun_ID << delimit << std::endl << "Função: " << vet.fun_Funcao << delimit << std::endl << "Nome: " << vet.fun_Nome << delimit
	  << std::endl << "CPF: " << vet.fun_CPF << delimit << std::endl << "Idade: " << vet.fun_Idade << delimit << std::endl << "Tipo Sanguíneo: "
	  << vet.fun_TipoSanguineo << vet.fun_FatorRH << delimit << std::endl << "Especialidade de Animais: " << vet.fun_Especialidade << delimit << std::endl
	  << "CRMV: " << vet.vet_CRMV << delimit << std::endl;
	return o;
}

std::istream& operator>>(std::istream &i, std::shared_ptr <Veterinario> vet){
	std::string cad_aux;
	bool condicao = true;

	vet->fun_Funcao = "Veterinario";
	
	/*A partir desse ponto, serão usados condicionais para verificar se já há alguma informação salva no objeto para saber se tem que adicionar um novo
	dado ou perguntar se quer alterar o existente. Ambos os condicionais e laços tem tratamento de exceções para garantir que sempre receba o dado correto
	para o tipo de dado que se está solicitando.*/
	if(vet->fun_Nome.size() != 0){
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
	}while(condicao){
		std::cout << "Insira o Nome do Funcionario." << std::endl;
		std::getline(std::cin, vet->fun_Nome);
		try{
			if(vet->fun_Nome.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	/*Essa modificação do valor de "condicional", existente no início de cada laço a partir de agora, é para garantir que o laço será iniciado
	caso a sobrecarga não esteja sendo usada para alteração.*/
	condicao = true;
	if(vet->fun_Idade != 0){
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
			vet->fun_Idade = std::stoi(cad_aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(vet->fun_CPF.size() != 0){
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
		std::getline(std::cin, vet->fun_CPF);
		try{
			if(vet->fun_CPF.size() != 14) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(vet->fun_TipoSanguineo.size() != 0){
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
		std::getline(std::cin, vet->fun_TipoSanguineo);
		try{
			if(vet->fun_TipoSanguineo.size() == 0) throw ErroCadastro();
			if(!(vet->fun_TipoSanguineo.compare("AB") == 0 || vet->fun_TipoSanguineo.compare("A") == 0 ||
				 vet->fun_TipoSanguineo.compare("B") == 0 || vet->fun_TipoSanguineo.compare("O") == 0)) throw ErroCadastro();
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(vet->fun_FatorRH != 'P'){
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
		vet->fun_FatorRH = cad_aux[0];
		try{
			if(!(vet->fun_FatorRH == '-' || vet->fun_FatorRH == '+')) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(vet->fun_Especialidade.size() != 0){
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
		std::getline(std::cin, vet->fun_Especialidade);
		try{
			if(vet->fun_Especialidade.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(vet->vet_CRMV.size() != 0){
		do{
			std::cout << "Quer Alterar o CRMV do Veterinario? Digite S ou N." << std::endl;
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
		std::cout << "Digite o Código CRMV do Veterinario. (UF - 000000)" << std::endl;
		std::getline(std::cin, vet->vet_CRMV);
		try{
			if(vet->vet_CRMV.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	return i;
}