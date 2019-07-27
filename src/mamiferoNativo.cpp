#include "mamiferoNativo.h"

MamiferoNativo::MamiferoNativo(int _mam_ID, std::string _mam_Classe, std::string _mam_NomeComum, std::string _mam_NomeCientifico, char _mam_Sexo,
							   double _mam_Tamanho, std::string _mam_Dieta, int _mam_Veterinario, int _mam_Tratador, std::string _mam_NomeBatismo,
							   std::string _mam_CorPelo, std::string _mam_AutorizIBAMA, std::string _mam_UFOrigem, std::string _mam_Autorizacao): Mamifero(
							   _mam_ID, _mam_Classe, _mam_NomeComum, _mam_NomeCientifico, _mam_Sexo, _mam_Tamanho, _mam_Dieta, _mam_Veterinario,
							   _mam_Tratador, _mam_NomeBatismo, _mam_CorPelo), AnimalNativo(_mam_AutorizIBAMA, _mam_UFOrigem, _mam_Autorizacao){
	//Construtor Parametrizado
}

MamiferoNativo::MamiferoNativo(void){
	
}

MamiferoNativo::~MamiferoNativo(void){
	//Destrutor
}

int MamiferoNativo::getID(void){
	return ani_ID;
}

std::string MamiferoNativo::getClasse(void){
	return ani_Classe;
}

std::string MamiferoNativo::getNomeComum(void){
	return ani_NomeComum;
}

std::string MamiferoNativo::getNomeCientifico(void){
	return ani_NomeCientifico;
}

char MamiferoNativo::getSexo(void){
	return ani_Sexo;
}

double MamiferoNativo::getTamanho(void){
	return ani_Tamanho;
}

std::string MamiferoNativo::getDieta(void){
	return ani_Dieta;
}

int MamiferoNativo::getVeterinarioID(void){
	return ani_Veterinario;
}

int MamiferoNativo::getTratadorID(void){
	return ani_Tratador;
}

std::string MamiferoNativo::getNomeBatismo(void){
	return ani_NomeBatismo;
}

std::string MamiferoNativo::getCorPelo(void){
	return mam_CorPelo;
}

std::string MamiferoNativo::getAutorIBAMA(void){
	return sil_AutorizIBAMA;
}

std::string MamiferoNativo::getUF_Origem(void){
	return nat_UF_Origem;
}

std::string MamiferoNativo::getLicenTrans(void){
	return nat_LicTrans;
}

std::ostream& operator<< (std::ostream &o, const MamiferoNativo maNa){
	o << "ID: " << maNa.ani_ID << delimit << std::endl << "Classe: " << "Mammalia" << delimit << std::endl << "Nome Comum da Espécie: "
	  << maNa.ani_NomeComum << delimit << std::endl << "Nome Científico da Espécie: " << maNa.ani_NomeCientifico << delimit << std::endl << "Sexo: "
	  << maNa.ani_Sexo << delimit << std::endl << "Nome de Batismo: " << maNa.ani_NomeBatismo << delimit << std::endl << "Tamanho (m): " << maNa.ani_Tamanho
	  << delimit << std::endl << "Dieta Predominante: " << maNa.ani_Dieta << delimit << std::endl << "ID do Veterinário Responsável: "
	  << maNa.ani_Veterinario << delimit << std::endl << "ID do Tratador Responsável: " << maNa.ani_Tratador << delimit << std::endl << "Cor do Pelo: "
	  << maNa.mam_CorPelo << delimit << std::endl << "Autorização do IBAMA: " << maNa.sil_AutorizIBAMA << delimit << std::endl << "Estado de Origem: "
	  << maNa.nat_UF_Origem << delimit << std::endl << "Licença de transporte: " << maNa.nat_LicTrans << delimit << std::endl;
	return o;
}

std::istream& operator>> (std::istream &i, std::shared_ptr <MamiferoNativo> maNa){
	std::string aux;
	bool condicao =  true;
	
	maNa->ani_Classe = "MamiferoNativo";

	/*A partir desse ponto, serão usados condicionais para verificar se já há alguma informação salva no objeto para saber se tem que adicionar um novo
	dado ou perguntar se quer alterar o existente. Ambos os condicionais e laços tem tratamento de exceções para garantir que sempre receba o dado correto
	para o tipo de dado que se está solicitando.*/
	if(maNa->ani_NomeComum.size() != 0){
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
		std::getline(std::cin, maNa->ani_NomeComum);
		try{
			if(maNa->ani_NomeComum.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	/*Essa modificação do valor de "condicional", existente no início de cada laço a partir de agora, é para garantir que o laço será iniciado
	caso a sobrecarga não esteja sendo usada para alteração.*/
	condicao = true;
	if(maNa->ani_NomeCientifico.size() != 0){
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
		std::getline(std::cin, maNa->ani_NomeCientifico);
		try{
			if(maNa->ani_NomeCientifico.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->ani_NomeBatismo.size() != 0){
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
		std::getline(std::cin, maNa->ani_NomeBatismo);
		try{
			if(maNa->ani_NomeBatismo.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->ani_Sexo != 'P'){
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
		maNa->ani_Sexo = aux[0];
		try{
			if(!(maNa->ani_Sexo == 'F' || maNa->ani_Sexo == 'M')) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->ani_Tamanho != 0){
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
			maNa->ani_Tamanho = std::stod(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->ani_Dieta.size() != 0){
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
		std::getline(std::cin, maNa->ani_Dieta);
		try{
			if(maNa->ani_Dieta.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->ani_Veterinario != 0){
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
			maNa->ani_Veterinario = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->ani_Tratador != 0){
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
			maNa->ani_Tratador = std::stoi(aux);
			condicao = false;
		}catch(std::invalid_argument &erro){
			std::cout << erro.what() << "\nO Valor Inserido Não Corresponde ao Tipo de Dado" << std::endl;
			condicao = true;
		}
	}

	condicao = true;	
	if(maNa->mam_CorPelo.size() != 0){
		do{
			std::cout << "Quer alterar a Cor do Pelo do Animal? Digite S ou N." << std::endl;
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
		std::cout << "Digite a Cor do Pelo do Animal." << std::endl;
		std::getline(std::cin, maNa->mam_CorPelo);
		try{
			if(maNa->mam_CorPelo.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->sil_AutorizIBAMA.size() != 0){
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
		std::getline(std::cin, maNa->sil_AutorizIBAMA);
		try{
			if(maNa->sil_AutorizIBAMA.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->nat_UF_Origem.size() != 0){
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
		std::getline(std::cin, maNa->nat_UF_Origem);
		try{
			if(maNa->nat_UF_Origem.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	condicao = true;
	if(maNa->nat_LicTrans.size() != 0){
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
		std::getline(std::cin, maNa->nat_LicTrans);
		try{
			if(maNa->nat_LicTrans.size() == 0) throw ErroCadastro();
			condicao = false;
		}catch(ErroCadastro &erro){
			std::cout << erro.what() << std::endl;
			condicao = true;
		}
	}

	return i;
}