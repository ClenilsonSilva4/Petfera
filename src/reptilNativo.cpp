#include "reptilNativo.h"

//Construtor Parametrizado
ReptilNativo::ReptilNativo(int _rep_ID, std::string _rep_Classe, std::string _rep_NomeComum, std::string _rep_NomeCientifico, char _rep_Sexo,
						   double _rep_Tamanho, std::string _rep_Dieta, int _rep_Veterinario, int _rep_Tratador, std::string _rep_NomeBatismo,
						   bool rep_Venenoso, std::string rep_TipoVeneno, std::string _rep_AutorizIBAMA, std::string _rep_UFOrigem,
						   std::string _rep_Autorizacao): Reptil(_rep_ID, _rep_Classe, _rep_NomeComum, _rep_NomeCientifico, _rep_Sexo, _rep_Tamanho,
						   _rep_Dieta, _rep_Veterinario, _rep_Tratador, _rep_NomeBatismo, rep_Venenoso, rep_TipoVeneno), AnimalNativo(_rep_AutorizIBAMA,
						   _rep_UFOrigem, _rep_Autorizacao){
}

ReptilNativo::ReptilNativo(void){

}

ReptilNativo::~ReptilNativo(void){
	//Destrutor
}


int ReptilNativo::getID(void){
	return ani_ID;
}

std::string ReptilNativo::getClasse(void){
	return ani_Classe;
}

std::string ReptilNativo::getNomeComum(void){
	return ani_NomeComum;
}

std::string ReptilNativo::getNomeCientifico(void){
	return ani_NomeCientifico;
}

char ReptilNativo::getSexo(void){
	return ani_Sexo;
}

double ReptilNativo::getTamanho(void){
	return ani_Tamanho;
}

std::string ReptilNativo::getDieta(void){
	return ani_Dieta;
}

int ReptilNativo::getVeterinarioID(void){
	return ani_Veterinario;
}

int ReptilNativo::getTratadorID(void){
	return ani_Tratador;
}

std::string ReptilNativo::getNomeBatismo(void){
	return ani_NomeBatismo;
}

bool ReptilNativo::getVenenoso(void){
	return rep_Venenoso;
}

std::string ReptilNativo::getTipoVeneno(void){
	return rep_TipoVeneno;
}

std::string ReptilNativo::getAutorIBAMA(void){
	return sil_AutorizIBAMA;
}

std::string ReptilNativo::getUF_Origem(void){
	return nat_UF_Origem;
}

std::string ReptilNativo::getLicenTrans(void){
	return nat_LicTrans;
}

std::ostream& operator<< (std::ostream &o, const ReptilNativo reNa){
	std::string venenoso;
	//Condicional para receber o dado true ou false para imprimir corretamente.
	if(reNa.rep_Venenoso){
		venenoso = "Sim";
	}else{
		venenoso = "Não";
	}
	o << "ID: " << reNa.ani_ID << delimit << std::endl << "Classe: " << "Reptilia" << delimit << std::endl << "Nome Comum da Espécie: " << reNa.ani_NomeComum
	  << delimit << std::endl << "Nome Científico da Espécie: " << reNa.ani_NomeCientifico << delimit << std::endl << "Sexo: " << reNa.ani_Sexo << delimit
	  << std::endl << "Nome de Batismo: " << reNa.ani_NomeBatismo << delimit << std::endl << "Tamanho (m): " << reNa.ani_Tamanho << delimit << std::endl
	  << "Dieta Predominante: " << reNa.ani_Dieta << delimit << std::endl << "ID do Veterinário Responsável: " << reNa.ani_Veterinario << delimit << std::endl
	  << "ID do Tratador Responsável: " << reNa.ani_Tratador << delimit << std::endl << "Animal Venenoso: " << venenoso << delimit << std::endl
	  << "Tipo do Veneno: " << reNa.rep_TipoVeneno << delimit << std::endl << "Autorização do IBAMA: " << reNa.sil_AutorizIBAMA << delimit << std::endl
	  << "Estado de Origem: " << reNa.nat_UF_Origem << delimit << std::endl << "Licença de Transporte: " << reNa.nat_LicTrans << delimit << std::endl;
	return o;
}

std::istream& operator>> (std::istream &i, std::shared_ptr <ReptilNativo> reNa){
	std::string aux;
	bool condicao = true;
	
	reNa->ani_Classe = "ReptilNativo";

	/*A partir desse ponto, serão usados condicionais para verificar se já há alguma informação salva no objeto para saber se tem que adicionar um novo
	dado ou perguntar se quer alterar o existente. Ambos os condicionais e laços tem tratamento de exceções para garantir que sempre receba o dado correto
	para o tipo de dado que se está solicitando.*/
	if(reNa->ani_NomeComum.size() != 0){
		do{
			std::cout << "Quer alterar o Nome Comum do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Nome Comum do Animal." << std::endl;
		std::getline(std::cin, reNa->ani_NomeComum);
		try{
			if(reNa->ani_NomeComum.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	/*Essa modificação do valor de "condicional", existente no início de cada laço a partir de agora, é para garantir que o laço será iniciado
	caso a sobrecarga não esteja sendo usada para alteração.*/
	condicao = true;
	if(reNa->ani_NomeCientifico.size() != 0){
		do{
			std::cout << "Quer alterar o Nome Científico do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Nome Científico do Animal." << std::endl;
		std::getline(std::cin, reNa->ani_NomeCientifico);
		try{
			if(reNa->ani_NomeCientifico.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->ani_NomeBatismo.size() != 0){
		do{
			std::cout << "Quer alterar o Nome de Batismo do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Nome de Batismo do Animal." << std::endl;
		std::getline(std::cin, reNa->ani_NomeBatismo);
		try{
			if(reNa->ani_NomeBatismo.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->ani_Sexo != 'P'){
		do{
			std::cout << "Quer alterar o Sexo do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Sexo do Animal (F ou M)." << std::endl;
		std::getline(std::cin, aux);
		reNa->ani_Sexo = aux[0];
		try{
			if(!(reNa->ani_Sexo == 'F' || reNa->ani_Sexo == 'M')) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->ani_Tamanho != 0){
		do{
			std::cout << "Quer alterar o Tamanho do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Tamanho do Animal em Metros." << std::endl;
		std::getline(std::cin, aux);
		try{
			reNa->ani_Tamanho = std::stod(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->ani_Dieta.size() != 0){
		do{
			std::cout << "Quer alterar a Dieta do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira a Dieta Predominante do Animal." << std::endl;
		std::getline(std::cin, reNa->ani_Dieta);
		try{
			if(reNa->ani_Dieta.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->ani_Veterinario != 0){
		do{
			std::cout << "Quer alterar o Veterinário Responsável Pelo Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o ID do Veterinário." << std::endl;
		std::getline(std::cin, aux);
		try{
			reNa->ani_Veterinario = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->ani_Tratador != 0){
		do{
			std::cout << "Quer alterar o Tratador Responsável Pelo Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o ID do Tratador." << std::endl;
		std::getline(std::cin, aux);
		try{
			reNa->ani_Tratador = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->rep_Venenoso != 0){
		do{
			std::cout << "Quer alterar se o Animal É Venenoso ou Não? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		try{
			std::cout << "O Animal em Questão É Venenoso? (Digite S Para Sim e N Para Não)" << std::endl;
			std::getline(std::cin, aux);

			if(aux[0] == 'S'){
				reNa->rep_Venenoso = true;
				do{
					std::cout << "Digite o Tipo do Veneno" << std::endl;
					std::getline(std::cin, reNa->rep_TipoVeneno);
					try{
						if(reNa->rep_TipoVeneno.size() == 0) throw ErroCadastro();
						condicao = false;
					}catch(ErroCadastro &erro){
						std::cout << erro.what() << std::endl;
						condicao = true;
					}
				}while(condicao);
			}else if (aux[0] == 'N'){
				reNa->rep_TipoVeneno = "-";
			}else throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << "\nA Opção Digitada Não Está Disponível" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->sil_AutorizIBAMA.size() != 0){
		do{
			std::cout << "Quer alterar o Código de Autorização do IBAMA? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Código de Autorização do IBAMA." << std::endl;
		std::getline(std::cin, reNa->sil_AutorizIBAMA);
		try{
			if(reNa->sil_AutorizIBAMA.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->nat_UF_Origem.size() != 0){
		do{
			std::cout << "Quer alterar o Estado de Origem do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira o Estado de Origem do Animal." << std::endl;
		std::getline(std::cin, reNa->nat_UF_Origem);
		try{
			if(reNa->nat_UF_Origem.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(reNa->nat_LicTrans.size() != 0){
		do{
			std::cout << "Quer alterar a Licença de Transporte do Animal? Digite S ou N." << std::endl;
			std::getline(std::cin, aux);
			try{
				if(!(aux[0] == 'S' || aux[0] == 'N')) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cerr << "O Dado Inserido Não Corresponde as Opções. Digite Novamente." << std::endl << std::endl;
				condicao = true;
			}
		}while(condicao);
		if(aux[0] == 'S'){
			condicao = true;
		}else{
			condicao = false;
		}
	}
	while(condicao){
		std::cout << "Insira a Licença de Transporte do Animal." << std::endl;
		std::getline(std::cin, reNa->nat_LicTrans);
		try{
			if(reNa->nat_UF_Origem.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	return i;
}