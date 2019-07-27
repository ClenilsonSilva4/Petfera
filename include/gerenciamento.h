#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include "acoes.h"

//Classe criada para gerenciar todos os métodos de ler dados de um arquivo, escrever dados em um arquivo, cadastrar, remover, alterar e consultar dados de animais
class Gerenciamento{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas)
	protected:
		std::map <int, std::shared_ptr<Animal>> gerencAnimal;
		std::map <int, std::shared_ptr<Funcionario>> gerencFunc;
		Acoes <Animal> acoesAnimais;
		Acoes <Funcionario> acoesFuncionarios;
		const std::string pathArqAnimal = "./data/animais.csv";
		const std::string pathArqFuncionario = "./data/funcionarios.csv";
	public:
		//Construtores e Destrutores.
		Gerenciamento(void);
		~Gerenciamento(void);

		//Método do menu.
		void menu(void);
		//Método usado Para administrar a leitura dos arquivos de Animal e Funcionários.
		void lerDados(void);
		//Método que lê os dados do arquivo de Animal e armazena no map da classe.
		void lerAnimal(std::ifstream &_dadosAnimais);
		//Método que lê os dados do arquivo de Funcionário e Armazena no map da classe.
		void lerFuncionario(std::ifstream &_dadosFuncionarios);
		//Método usado para administrar o armazenamento dos dados em arquivos de Animal e Funcionários.
		void escreverDados(void);
		//Método que pega os dados do map da classe e armazena em arquivo de Animal.
		void escreverAnimal(std::ofstream &_arqAnim);
		//Método que pega os dados do map da classe e armazena em arquivo de Funcionário.
		void escreverFuncionario(std::ofstream &_arqFunc);
		//Método para cadastrar animal.
		void cadastrarAnimal(std::string _classe);
		//Método para cadastrar funcionário.
		void cadastrarFuncionario(std::string _classe);
		//Método para alterar animal.
		void alterarAnimal(int _ID_Animal);
		//Método para alterar funcionário.
		void alterarFuncionario(int _ID_Funcionario);
};

#endif
