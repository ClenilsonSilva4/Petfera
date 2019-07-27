#include "anfibioNativo.h"

AnfibioNativo::AnfibioNativo(int _anf_ID, std::string _anf_Classe, std::string _anf_NomeComum, std::string _anf_NomeCientifico, char _anf_Sexo,
							 double _anf_Tamanho, std::string _anf_Dieta, int _anf_Veterinario, int _anf_Tratador, std::string _anf_NomeBatismo,
							 int _anf_TotalMudas, std::string _anf_UltimaMuda, std::string _anf_AutorIBAMA,std::string _anf_PaisOrigem,
							 std::string _anf_LicenTrans): Anfibio(_anf_ID, _anf_Classe, _anf_NomeComum, _anf_NomeCientifico, _anf_Sexo, _anf_Tamanho,
							 _anf_Dieta, _anf_Veterinario, _anf_Tratador, _anf_NomeBatismo, _anf_TotalMudas, _anf_UltimaMuda), AnimalNativo(_anf_AutorIBAMA,
							 _anf_PaisOrigem, _anf_LicenTrans){
}

AnfibioNativo::AnfibioNativo(void){

}

AnfibioNativo::~AnfibioNativo(void){
	//Destrutor
}

int AnfibioNativo::getID(void){
	return ani_ID;
}

std::string AnfibioNativo::getClasse(void){
	return ani_Classe;
}

std::string AnfibioNativo::getNomeComum(void){
	return ani_NomeComum;
}

std::string AnfibioNativo::getNomeCientifico(void){
	return ani_NomeCientifico;
}

char AnfibioNativo::getSexo(void){
	return ani_Sexo;
}

double AnfibioNativo::getTamanho(void){
	return ani_Tamanho;
}

std::string AnfibioNativo::getDieta(void){
	return ani_Dieta;
}

int AnfibioNativo::getVeterinarioID(void){
	return ani_Veterinario;
}

int AnfibioNativo::getTratadorID(void){
	return ani_Tratador;
}

std::string AnfibioNativo::getNomeBatismo(void){
	return ani_NomeBatismo;
}

int AnfibioNativo::getTotalMudas(void){
	return anf_TotalMudas;
}

std::string AnfibioNativo::getDataUltimaMuda(void){
	return anf_UltimaMuda;
}

std::string AnfibioNativo::getAutorIBAMA(void){
	return sil_AutorizIBAMA;
}

std::string AnfibioNativo::getUF_Origem(void){
	return nat_UF_Origem;
}

std::string AnfibioNativo::getLicenTrans(void){
	return nat_LicTrans;
}

std::ostream& operator<< (std::ostream &o, const AnfibioNativo anNa){
	o << "ID: " << anNa.ani_ID << delimit << std::endl << "Classe: " << "Amphibia" << delimit << std::endl << "Nome Comum da Espécie: " << anNa.ani_NomeComum
	  << delimit << std::endl << "Nome Científico da Espécie: " << anNa.ani_NomeCientifico << delimit << std::endl << "Nome de Batismo: "
	  << anNa.ani_NomeBatismo << delimit << std::endl << "Sexo: " << anNa.ani_Sexo << delimit << std::endl << "Tamanho (m): " << anNa.ani_Tamanho << delimit
	  << std::endl << "Dieta Predominante: " << anNa.ani_Dieta << delimit << std::endl << "ID do Veterinário Responsável: " << anNa.ani_Veterinario
	  << delimit << std::endl << "ID do Tratador Responsável: " << anNa.ani_Tratador << delimit << std::endl << "Total de Mudas: " << anNa.anf_TotalMudas
	  << delimit << std::endl << "Data da Última Muda: " << anNa.anf_UltimaMuda << delimit << std::endl << "Autorização do IBAMA: " << anNa.sil_AutorizIBAMA
	  << delimit << std::endl << "Estado de Origem: " << anNa.nat_UF_Origem << delimit << std::endl << "Licença de Transporte: " << anNa.nat_LicTrans
	  << delimit << std::endl;
	return o;
}

std::istream& operator>> (std::istream &i, std::shared_ptr <AnfibioNativo> anNa){
	std::string aux;
	bool condicao = true;
	anNa->ani_Classe = "AnfibioNativo";

	/*A partir desse ponto, serão usados condicionais para verificar se já há alguma informação salva no objeto para saber se tem que adicionar um novo
	dado ou perguntar se quer alterar o existente. Ambos os condicionais e laços tem tratamento de exceções para garantir que sempre receba o dado correto
	para o tipo de dado que se está solicitando.*/
	if(anNa->ani_NomeComum.size() != 0){
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
		std::getline(std::cin, anNa->ani_NomeComum);
		try{
			if(anNa->ani_NomeComum.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	/*Essa modificação do valor de "condicional", existente no início de cada laço a partir de agora, é para garantir que o laço será iniciado
	caso a sobrecarga não esteja sendo usada para alteração.*/
	condicao = true;
	if(anNa->ani_NomeCientifico.size() != 0){
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
		std::getline(std::cin, anNa->ani_NomeCientifico);
		try{
			if(anNa->ani_NomeCientifico.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->ani_NomeBatismo.size() != 0){
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
		std::getline(std::cin, anNa->ani_NomeBatismo);
		try{
			if(anNa->ani_NomeBatismo.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->ani_Sexo != 'P'){
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
		anNa->ani_Sexo = aux[0];
		try{
			if(!(anNa->ani_Sexo == 'F' || anNa->ani_Sexo == 'M')) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->ani_Tamanho != 0){
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
			anNa->ani_Tamanho = std::stod(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->ani_Dieta.size() != 0){
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
		std::getline(std::cin, anNa->ani_Dieta);
		try{
			if(anNa->ani_Dieta.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->ani_Veterinario != 0){
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
			anNa->ani_Veterinario = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->ani_Tratador != 0){
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
			anNa->ani_Tratador = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->anf_TotalMudas != 0){
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
			anNa->anf_TotalMudas = stoi(aux);
			try{
				if(anNa->anf_TotalMudas <= 0) throw ErroCadastro();
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
	if(anNa->anf_UltimaMuda.size() != 0){
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
		std::getline(std::cin, anNa->anf_UltimaMuda);
		try{
			if(anNa->anf_UltimaMuda.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->sil_AutorizIBAMA.size() != 0){
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
		std::getline(std::cin, anNa->sil_AutorizIBAMA);
		try{
			if(anNa->sil_AutorizIBAMA.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->nat_UF_Origem.size() != 0){
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
		std::getline(std::cin, anNa->nat_UF_Origem);
		try{
			if(anNa->nat_UF_Origem.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(anNa->nat_LicTrans.size() != 0){
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
		std::getline(std::cin, anNa->nat_LicTrans);
		try{
			if(anNa->nat_UF_Origem.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	return i;
}