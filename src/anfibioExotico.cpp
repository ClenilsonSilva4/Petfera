#include "anfibioExotico.h"

AnfibioExotico::AnfibioExotico(int _anf_ID, std::string _anf_Classe, std::string _anf_NomeComum, std::string _anf_NomeCientifico,
							   char _anf_Sexo, double _anf_Tamanho, std::string _anf_Dieta, int _anf_Veterinario, int _anf_Tratador,
							   std::string _anf_NomeBatismo, int _anf_TotalMudas, std::string _anf_UltimaMuda, std::string _anf_AutorIBAMA,
							   std::string _anf_PaisOrigem): Anfibio(_anf_ID, _anf_Classe, _anf_NomeComum, _anf_NomeCientifico, _anf_Sexo, _anf_Tamanho,
							   _anf_Dieta, _anf_Veterinario, _anf_Tratador, _anf_NomeBatismo, _anf_TotalMudas, _anf_UltimaMuda), AnimalExotico(
							   _anf_AutorIBAMA,_anf_PaisOrigem){
}

AnfibioExotico::AnfibioExotico(void){

}

AnfibioExotico::~AnfibioExotico(void){
	//Destrutor
}

int AnfibioExotico::getID(void){
	return ani_ID;
}

std::string AnfibioExotico::getClasse(void){
	return ani_Classe;
}

std::string AnfibioExotico::getNomeComum(void){
	return ani_NomeComum;
}

std::string AnfibioExotico::getNomeCientifico(void){
	return ani_NomeCientifico;
}

char AnfibioExotico::getSexo(void){
	return ani_Sexo;
}

double AnfibioExotico::getTamanho(void){
	return ani_Tamanho;
}

std::string AnfibioExotico::getDieta(void){
	return ani_Dieta;
}

int AnfibioExotico::getVeterinarioID(void){
	return ani_Veterinario;
}

int AnfibioExotico::getTratadorID(void){
	return ani_Tratador;
}

std::string AnfibioExotico::getNomeBatismo(void){
	return ani_NomeBatismo;
}

int AnfibioExotico::getTotalMudas(void){
	return anf_TotalMudas;
}

std::string AnfibioExotico::getDataUltimaMuda(void){
	return anf_UltimaMuda;
}

std::string AnfibioExotico::getAutorIBAMA(void){
	return sil_AutorizIBAMA;
}

std::string AnfibioExotico::getPaisOrigem(void){
	return exo_PaisOrigem;
}

std::ostream& operator<< (std::ostream &o, const AnfibioExotico anEx){
	o << "ID: " << anEx.ani_ID << delimit << std::endl << "Classe: " << "Amphibia" << delimit << std::endl << "Nome Comum da Espécie: "
	  << anEx.ani_NomeComum << delimit << std::endl << "Nome Científico da Espécie: " << anEx.ani_NomeCientifico << delimit << std::endl << "Sexo: "
	  << anEx.ani_Sexo << delimit << std::endl << "Nome de Batismo: " << anEx.ani_NomeBatismo << delimit << std::endl << "Tamanho (m): " << anEx.ani_Tamanho
	  << delimit << std::endl << "Dieta Predominante: " << anEx.ani_Dieta << delimit << std::endl << "ID do Veterinário Responsável: "
	  << anEx.ani_Veterinario << delimit << std::endl << "ID do Tratador Responsável: " << anEx.ani_Tratador << delimit << std::endl << "Total de Mudas: "
	  << anEx.anf_TotalMudas << delimit << std::endl << "Data da Última Muda: " << anEx.anf_UltimaMuda << delimit << std::endl << "Autorização do IBAMA: "
	  << anEx.sil_AutorizIBAMA << delimit << std::endl << "País de Origem: " << anEx.exo_PaisOrigem << delimit << std::endl;
	return o;
}

std::istream& operator>> (std::istream &i, std::shared_ptr <AnfibioExotico> anEx){
	std::string aux;
	bool condicao = true;
	anEx->ani_Classe = "AnfibioExotico";

	/*A partir desse ponto, serão usados condicionais para verificar se já há alguma informação salva no objeto para saber se tem que adicionar um novo
	dado ou perguntar se quer alterar o existente. Ambos os condicionais e laços tem tratamento de exceções para garantir que sempre receba o dado correto
	para o tipo de dado que se está solicitando.*/
	if(anEx->ani_NomeComum.size() != 0){
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
		std::getline(std::cin, anEx->ani_NomeComum);
		try{
			if(anEx->ani_NomeComum.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	/*Essa modificação do valor de "condicional", existente no início de cada laço a partir de agora, é para garantir que o laço será iniciado
	caso a sobrecarga não esteja sendo usada para alteração.*/
	condicao = true;
	if(anEx->ani_NomeCientifico.size() != 0){
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
		std::getline(std::cin, anEx->ani_NomeCientifico);
		try{
			if(anEx->ani_NomeCientifico.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->ani_NomeBatismo.size() != 0){
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
		std::getline(std::cin, anEx->ani_NomeBatismo);
		try{
			if(anEx->ani_NomeBatismo.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->ani_Sexo != 'P'){
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
		anEx->ani_Sexo = aux[0];
		try{
			if(!(anEx->ani_Sexo == 'F' || anEx->ani_Sexo == 'M')) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->ani_Tamanho != 0){
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
			anEx->ani_Tamanho = std::stod(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->ani_Dieta.size() != 0){
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
		std::getline(std::cin, anEx->ani_Dieta);
		try{
			if(anEx->ani_Dieta.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->ani_Veterinario != 0){
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
			anEx->ani_Veterinario = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->ani_Tratador != 0){
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
			anEx->ani_Tratador = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->anf_TotalMudas != 0){
		do{
			std::cout << "Quer alterar a Quantidade de Mudas Realizadas Pelo Animal? Digite S ou N." << std::endl;
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
		std::cout << "Digite a Quantidade de Mudas Realizadas Até Agora." << std::endl;
		std::getline(std::cin, aux);
		try{
			anEx->anf_TotalMudas = stoi(aux);
			try{
				if(anEx->anf_TotalMudas <= 0) throw ErroCadastro();
				condicao = false;
			}catch(ErroCadastro &erro){
				std::cout << erro.what() << std::endl;
				condicao = true;
			}
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;	
	if(anEx->anf_UltimaMuda.size() != 0){
		do{
			std::cout << "Quer alterar a Data da Última Muda do Animal? Digite S ou N." << std::endl;
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
		std::cout << "Digite a Data da Última Troca de Pele do Animal. (00/00/0000)" << std::endl;
		std::getline(std::cin, anEx->anf_UltimaMuda);
		try{
			if(anEx->anf_UltimaMuda.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->sil_AutorizIBAMA.size() != 0){
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
		std::getline(std::cin, anEx->sil_AutorizIBAMA);
		try{
			if(anEx->sil_AutorizIBAMA.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anEx->exo_PaisOrigem.size() != 0){
		do{
			std::cout << "Quer alterar o País de Origem do Animal? Digite S ou N." << std::endl;
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
		std::cout << "Insira o País de Origem do Animal." << std::endl;
		std::getline(std::cin, anEx->exo_PaisOrigem);
		try{
			if(anEx->exo_PaisOrigem.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	return i;
}