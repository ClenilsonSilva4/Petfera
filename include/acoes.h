#ifndef ACOES_H
#define ACOES_H

#include <map>
#include <fstream>
#include <sstream>
#include <typeinfo>

#include "tratador.h"
#include "veterinario.h"
#include "anfibioExotico.h"
#include "anfibioNativo.h"
#include "aveExotica.h"
#include "aveNativa.h"
#include "mamiferoExotico.h"
#include "mamiferoNativo.h"
#include "reptilExotico.h"
#include "reptilNativo.h"
#include "excecoes.h"

//Template de Classe Para Realizar as Operações Entre Animais e Funcionários
template <typename T>
class Acoes{
	public:
		Acoes();
		~Acoes();
		
		void cadastro(std::map <int, std::shared_ptr<T>> &armaz, std::string _classeTipo, int ID);
		void remocao(std::map <int, std::shared_ptr<T>> &armaz, int _ID);
		void alteracao(std::shared_ptr <T> &dado);
		void consulta(const std::map <int, std::shared_ptr<T>> armaz, std::string _classeTipo);
		void consulta(const std::map <int, std::shared_ptr<T>> armaz, int _ID);
		void consultaWithFunID(const std::map <int, std::shared_ptr<T>> armaz, int _ID);
		void mostrarFuncionarios(const std::map <int, std::shared_ptr <Funcionario>> armaz);
};

template <typename T>
Acoes<T>::Acoes(){
	//Construtor
}

template <typename T>
Acoes<T>::~Acoes(){
	//Destrutor
}

/*O inline foi usado para evitar os erros de definição prévia do compilador e para não ter que usar um arquivo CPP para a implementação do método.
Além disso, o método de cadastro foi especializado para Animais.*/
template <> inline
void Acoes<Animal>::cadastro(std::map <int, std::shared_ptr<Animal>> &armaz, std::string _classeTipo, int ID){
	std::shared_ptr <Animal> newCadas;
	//Condicionais usados para identificar a classe correta do animal e usar a sobrecarga do operador para pegar os dados e adicionar ao MAP.
	if(_classeTipo.compare("Anfibio Exotico") == 0){
		std::shared_ptr <AnfibioExotico> aux = std::make_shared <AnfibioExotico> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Anfibio Nativo") == 0){
		std::shared_ptr <AnfibioNativo> aux = std::make_shared <AnfibioNativo> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Ave Exotica") == 0){
		std::shared_ptr <AveExotica> aux = std::make_shared <AveExotica> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Ave Nativa") == 0){
		std::shared_ptr <AveNativa> aux = std::make_shared <AveNativa> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Mamifero Exotico") == 0){
		std::shared_ptr <MamiferoExotico> aux = std::make_shared <MamiferoExotico> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Mamifero Nativo") == 0){
		std::shared_ptr <MamiferoNativo> aux = std::make_shared <MamiferoNativo> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Reptil Exotico") == 0){
		std::shared_ptr <ReptilExotico> aux = std::make_shared <ReptilExotico> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else{
		std::shared_ptr <ReptilNativo> aux = std::make_shared <ReptilNativo> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}
	armaz.insert(std::pair <int, std::shared_ptr <Animal>> (newCadas->getID(), newCadas));
}

//Método especializado para o cadastro de Funcionários.
template <> inline
void Acoes<Funcionario>::cadastro(std::map <int, std::shared_ptr<Funcionario>> &armaz, std::string _classeTipo, int ID){
	std::shared_ptr <Funcionario> newCadas;

	//Condicionais para verificar a classe atráves do dado recebido e mostra os dados de acordo.
	if(_classeTipo.compare("Veterinario") == 0){
		std::shared_ptr <Veterinario> aux = std::make_shared <Veterinario> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}else if(_classeTipo.compare("Tratador") == 0){
		std::shared_ptr <Tratador> aux = std::make_shared <Tratador> (ID, _classeTipo);
		std::cin >> aux;
		newCadas = aux;
	}
	std::cout << "Funcionário Cadastrado Com Sucesso." << std::endl << std::endl;

	armaz.insert(std::pair <int, std::shared_ptr <Funcionario>> (newCadas->getID(), newCadas));
}

//Método com template usado para a remoção do MAP de animais ou funcionários.
template <typename T>
void Acoes<T>::remocao(std::map <int, std::shared_ptr<T>> &armaz, int _ID){
	//Testa se realmente encontrou o animal correto e o remove, caso não, lança uma exceção.
	try{
		//Condicional para verificar se o dado realmente existe no MAP, em caso verdadeiro, apaga e apresenta uma mensagem.
		if (armaz.find(_ID) != armaz.end()){
			armaz.erase(_ID);
			std::cout << "Dado Removido Com Sucesso" << std::endl << std::endl;
		}else throw ErroBusca();
	}catch(ErroBusca &erro){
		std::cerr << erro.what() << std::endl << "O Dado Não Pode Ser Removido" << std::endl << std::endl;
	}
}

/*Método especializado para a alteração dos dados de animais usando-se da sobrecarga de operador para realizar a operação
e passa as alterações para o MAP por ter recebido o dado por referência.*/
template <> inline
void Acoes<Animal>::alteracao(std::shared_ptr <Animal> &dado){
	//Condicional que verifica a classe correta para poder receber o dado.
	if(dado->getClasse().compare("AnfibioExotico") == 0){
		std::shared_ptr <AnfibioExotico> aux = std::static_pointer_cast <AnfibioExotico> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getClasse().compare("AnfibioNativo") == 0){
		std::shared_ptr <AnfibioNativo> aux = std::static_pointer_cast <AnfibioNativo> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getClasse().compare("AveExotica") == 0){
		std::shared_ptr <AveExotica> aux = std::static_pointer_cast <AveExotica> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getClasse().compare("AveNativa") == 0){
		std::shared_ptr <AveNativa> aux = std::static_pointer_cast <AveNativa> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getClasse().compare("MamiferoExotico") == 0){
		std::shared_ptr <MamiferoExotico> aux = std::static_pointer_cast <MamiferoExotico> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getClasse().compare("MamiferoNativo") == 0){
		std::shared_ptr <MamiferoNativo> aux = std::static_pointer_cast <MamiferoNativo> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getClasse().compare("ReptilExotico") == 0){
		std::shared_ptr <ReptilExotico> aux = std::static_pointer_cast <ReptilExotico> (dado);
		std::cin >> aux;
		dado = aux;
	}else{
		std::shared_ptr <ReptilNativo> aux = std::static_pointer_cast <ReptilNativo> (dado);
		std::cin >> aux;
		dado = aux;
	}
	std::cout << "Animal Alterado Com Sucesso." << std::endl << std::endl;
}

template <> inline
void Acoes<Funcionario>::alteracao(std::shared_ptr <Funcionario> &dado){
	//Condicionais para verificar a classe atráves do dado recebido e mostra os dados de acordo.
	if(dado->getFuncao().compare("Veterinario") == 0){
		std::shared_ptr <Veterinario> aux = std::static_pointer_cast <Veterinario> (dado);
		std::cin >> aux;
		dado = aux;
	}else if(dado->getFuncao().compare("Tratador") == 0){
		std::shared_ptr <Tratador> aux = std::static_pointer_cast <Tratador> (dado);
		std::cin >> aux;
		dado = aux;
	}
	std::cout << "Funcionário Alterado Com Sucesso." << std::endl << std::endl;
}

//Decidi especializar o método apenas para animal já que a consulta é realizada apenas no MAP de Animais.
template <> inline
void Acoes<Animal>::consulta(const std::map <int, std::shared_ptr<Animal>> armaz, std::string _classeTipo){
	//Contador utilizado para verificar se algum dado foi impresso para emitir o aviso se foi ou não imprimido algum dado.
	int cont = 0;
	//Condicional para verificar se há dados salvos no armazenamento
	if(armaz.size() == 0){
		std::cout << std::endl << "Não Há Animais Salvos no Sistema." << std::endl;
	}else if(_classeTipo.compare("Amphibia") == 0){ //Condicionais para verificar a classe atráves do dado recebido e mostra os dados de acordo.
		for(auto i = armaz.begin(); i != armaz.end(); i++){
			if(i->second->getClasse().compare("AnfibioExotico") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <AnfibioExotico> aux = std::static_pointer_cast <AnfibioExotico> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}else if(i->second->getClasse().compare("AnfibioNativo") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <AnfibioNativo> aux = std::static_pointer_cast <AnfibioNativo> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}
		}
	}else if(_classeTipo.compare("Aves") == 0){ //Condicionais para verificar a classe atráves do dado recebido e mostra os dados de acordo.
		for(auto i = armaz.begin(); i != armaz.end(); i++){
			if(i->second->getClasse().compare("AveExotica") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <AveExotica> aux = std::static_pointer_cast <AveExotica> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}else if(i->second->getClasse().compare("AveNativa") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <AveNativa> aux = std::static_pointer_cast <AveNativa> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}
		}
	}else if(_classeTipo.compare("Mammalia") == 0){ //Condicionais para verificar a classe atráves do dado recebido e mostra os dados de acordo.
		for(auto i = armaz.begin(); i != armaz.end(); i++){
			if(i->second->getClasse().compare("MamiferoExotico") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <MamiferoExotico> aux = std::static_pointer_cast <MamiferoExotico> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}else if(i->second->getClasse().compare("MamiferoNativo") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <MamiferoNativo> aux = std::static_pointer_cast <MamiferoNativo> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}
		}
	}else{
		for(auto i = armaz.begin(); i != armaz.end(); i++){ //Condicionais para verificar a classe atráves do dado recebido e mostra os dados de acordo.
			if(i->second->getClasse().compare("ReptilExotico") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <ReptilExotico> aux = std::static_pointer_cast <ReptilExotico> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}else if(i->second->getClasse().compare("ReptilNativo") == 0){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				std::shared_ptr <ReptilNativo> aux = std::static_pointer_cast <ReptilNativo> (i->second);
				std::cout << *aux << std::endl;
				cont++;
			}
		}
	}

	if(cont == 0){
		std::cout << std::endl << "Não Há Animais Salvos com Essa Classe no Sistema." << std::endl;
	}
}

//Template especializado que também faz a consulta de animal porém recebe como dado o ID do mesmo.
template <> inline
void Acoes<Animal>::consulta(const std::map <int, std::shared_ptr<Animal>> armaz, int _ID){
	//Condicional para verificar se há dados salvos no MAP.
	if(armaz.size() == 0){
		std::cout << std::endl << "Não Há Animais Salvos no Sistema." << std::endl;
	}else{
		for(auto i = armaz.begin(); i != armaz.end(); i++){
			//Condicional para verificar se o dado recebido bate com algum dado armazenado.
			if(i->second->getID() == _ID){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				//Condicionais para verificar a classe do animal e imprimir os dados corretamente.
				if(i->second->getClasse().compare("AnfibioExotico") == 0){
					std::shared_ptr <AnfibioExotico> aux = std::static_pointer_cast <AnfibioExotico> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("AnfibioNativo") == 0){
					std::shared_ptr <AnfibioNativo> aux = std::static_pointer_cast <AnfibioNativo> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("AveExotica") == 0){
					std::shared_ptr <AveExotica> aux = std::static_pointer_cast <AveExotica> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("AveNativa") == 0){
					std::shared_ptr <AveNativa> aux = std::static_pointer_cast <AveNativa> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("MamiferoExotico") == 0){
					std::shared_ptr <MamiferoExotico> aux = std::static_pointer_cast <MamiferoExotico> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("MamiferoNativo") == 0){
					std::shared_ptr <MamiferoNativo> aux = std::static_pointer_cast <MamiferoNativo> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("ReptilExotico") == 0){
					std::shared_ptr <ReptilExotico> aux = std::static_pointer_cast <ReptilExotico> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("ReptilNativo") == 0){
					std::shared_ptr <ReptilNativo> aux = std::static_pointer_cast <ReptilNativo> (i->second);
					std::cout << *aux << std::endl;
				}
			}
		}
	}
}

//Template especializado para realizar a consulta dos dados de animais a partir do funcionário responsável.
template <> inline
void Acoes<Animal>::consultaWithFunID(const std::map <int, std::shared_ptr<Animal>> armaz, int _ID){
	//Condicional para verificar se há dados salvos no MAP.
	if(armaz.size() == 0){
		std::cout << std::endl << "Não Há Animais Salvos no Sistema." << std::endl;
	}else{
		for(auto i = armaz.begin(); i != armaz.end(); i++){
			//Condicional para verificar se o dado recebido bate com algum dado armazenado.
			if(i->second->getVeterinarioID() == _ID || i->second->getTratadorID() == _ID){
				std::cout << "***** Consulta de Animais *****" << std::endl;
				//Condicionais para verificar a classe do animal e imprimir os dados corretamente.
				if(i->second->getClasse().compare("AnfibioExotico") == 0){
					std::shared_ptr <AnfibioExotico> aux = std::static_pointer_cast <AnfibioExotico> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("AnfibioNativo") == 0){
					std::shared_ptr <AnfibioNativo> aux = std::static_pointer_cast <AnfibioNativo> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("AveExotica") == 0){
					std::shared_ptr <AveExotica> aux = std::static_pointer_cast <AveExotica> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("AveNativa") == 0){
					std::shared_ptr <AveNativa> aux = std::static_pointer_cast <AveNativa> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("MamiferoExotico") == 0){
					std::shared_ptr <MamiferoExotico> aux = std::static_pointer_cast <MamiferoExotico> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("MamiferoNativo") == 0){
					std::shared_ptr <MamiferoNativo> aux = std::static_pointer_cast <MamiferoNativo> (i->second);
					std::cout << *aux << std::endl;
				}else if(i->second->getClasse().compare("ReptilExotico") == 0){
					std::shared_ptr <ReptilExotico> aux = std::static_pointer_cast <ReptilExotico> (i->second);
					std::cout << *aux << std::endl;
				}else{
					std::shared_ptr <ReptilNativo> aux = std::static_pointer_cast <ReptilNativo> (i->second);
					std::cout << *aux << std::endl;
				}
			}
		}
	}
}

//Método específico de funcionários para mostrar todos que estão cadastrados no sistema.
template <> inline
void Acoes<Funcionario>::mostrarFuncionarios(const std::map <int, std::shared_ptr <Funcionario>> armaz){
	for(auto i = armaz.begin(); i != armaz.end(); i++){
		std::cout << "***** Consulta de Funcionários *****" << std::endl;
		if(i->second->getFuncao().compare("Veterinario") == 0){
			std::shared_ptr <Veterinario> aux = std::static_pointer_cast <Veterinario> (i->second);
			std::cout << *aux << std::endl << std::endl;
		}else{
			std::shared_ptr <Tratador> aux = std::static_pointer_cast <Tratador> (i->second);
			std::cout << *aux << std::endl << std::endl;
		}
	}
}

#endif