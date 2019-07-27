#include "gerenciamento.h"

Gerenciamento::Gerenciamento(void){
	//Construtor Padrão.
}

Gerenciamento::~Gerenciamento(void){
	//Destrutor.
}

void Gerenciamento::menu(void){
	bool menuInicial = true;
	int opcaoInicial, opcaoCadastro, _aux;
	std::string _auxClass;
	lerDados();

	while(menuInicial){
		opcaoCadastro = 2;
		std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
		std::cout << "║               Loja de Animais Silvestres PetFera               ║" << std::endl;
		std::cout << "║                                                                ║" << std::endl;
		std::cout << "╠ 1 - Cadastrar um Novo Animal                                   ║" << std::endl;
		std::cout << "╠ 2 - Remover um Animal Cadastrado                               ║" << std::endl;
		std::cout << "╠ 3 - Alterar Dados de um Animal Já Cadastrado                   ║" << std::endl;
		std::cout << "╠ 4 - Consultar Dados de um Animal ou Classe de Animais          ║" << std::endl;
		std::cout << "╠ 5 - Consultar Animais Pelo Veterinário ou Tratador Responsável ║" << std::endl;
		std::cout << "╠ 6 - Cadastrar um Novo Funcionário                              ║" << std::endl;
		std::cout << "╠ 7 - Alterar Dados de um Funcionário                            ║" << std::endl;
		std::cout << "╠ 8 - Remover um Funcionário Cadastrado                          ║" << std::endl;
		std::cout << "╠ 9 - Consultar os Funcionários Cadastrados                      ║" << std::endl;
		std::cout << "╠ 0 - Encerrar o Sistema                                         ║" << std::endl;
		std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
		std::cout << "Sua Opção: ";
		std::cin >> opcaoInicial;
		std::cout << std::endl;
		std::cin.ignore(20, '\n');

		switch(opcaoInicial){
			case 1:
				while(menuInicial){
					std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
					std::cout << "║                        Cadastrar Animal                        ║" << std::endl;
					std::cout << "║                                                                ║" << std::endl;
					std::cout << "╠ 1 - Anfíbio Exótico                                            ║" << std::endl;
					std::cout << "╠ 2 - Anfíbio Nativo                                             ║" << std::endl;
					std::cout << "╠ 3 - Ave Exótica                                                ║" << std::endl;
					std::cout << "╠ 4 - Ave Nativa                                                 ║" << std::endl;
					std::cout << "╠ 5 - Mamífero Exótico                                           ║" << std::endl;
					std::cout << "╠ 6 - Mamífero Nativo                                            ║" << std::endl;
					std::cout << "╠ 7 - Réptil Exótico                                             ║" << std::endl;
					std::cout << "╠ 8 - Réptil Nativo                                              ║" << std::endl;
					std::cout << "╠ 9 - Voltar                                                     ║" << std::endl;
					std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
					std::cout << "Sua Opção: ";
					std::cin >> opcaoCadastro;
					std::cout << std::endl;
					std::cin.ignore(20, '\n');
					switch(opcaoCadastro){
						case 1:
							cadastrarAnimal("Anfibio Exotico");
							break;
						case 2:
							cadastrarAnimal("Anfibio Nativo");
							break;
						case 3:
							cadastrarAnimal("Ave Exotica");
							break;
						case 4:
							cadastrarAnimal("Ave Nativa");
							break;
						case 5:
							cadastrarAnimal("Mamifero Exotico");
							break;
						case 6:
							cadastrarAnimal("Mamifero Nativo");
							break;
						case 7:
							cadastrarAnimal("Reptil Exotico");
							break;
						case 8:
							cadastrarAnimal("Reptil Nativo");
							break;
						case 9:
							menuInicial = false;
							break;
						default:
							std::cout << "A Opção Digitada Não Está Disponível." << std::endl;
					}
				}
				menuInicial = true;
				break;
			case 2:
				while(opcaoCadastro != 0){
					std::cout << "Digite o ID do Animal que Quer Excluir. Digite 0 Para Voltar." << std::endl;
					std::cin >> _aux;
					std::cin.ignore(20, '\n');
					if(_aux == 0){
						opcaoCadastro = 0;
					}else{
						acoesAnimais.remocao(gerencAnimal, _aux);
					}
					break;
				}
			case 3:
				while(opcaoCadastro != 0){
					std::cout << "Qual o ID do Animal que Você Quer Alterar? Digite 0 Para Voltar." << std::endl;
					std::cin >> _aux;
					std::cout << std::endl;
					std::cin.ignore(10, '\n');
					if(_aux == 0){
						opcaoCadastro = 0;
					}else{
						alterarAnimal(_aux);
					}
				}
				break;
			case 4:
				while(opcaoCadastro != 0){
                    std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
                    std::cout << "║       Consultar Animais pelo ID do animal ou por classe        ║" << std::endl;
                    std::cout << "║                                                                ║" << std::endl;
                    std::cout << "╠ 1 - ID                                                         ║" << std::endl;
                    std::cout << "╠ 2 - Classe                                                     ║" << std::endl;
                    std::cout << "╠ 3 - Voltar                                                     ║" << std::endl;
                    std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
                    std::cout << "Sua Opção: ";
                    std::cin >> opcaoCadastro;
                    std::cout << std::endl;
                    std::cin.ignore(20, '\n');

                    switch(opcaoCadastro){
                        case 1:
                            std::cout << "Digite o ID do animal" << std::endl;
                            std::cin >> _aux;
                            std::cin.ignore(20, '\n');
                            acoesAnimais.consulta(gerencAnimal, _aux);
                            break;
                        case 2:
                        	opcaoInicial = 2;
                        	while(opcaoInicial != 0){
	                            std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
								std::cout << "║                  Consultar Animais Por Classe                  ║" << std::endl;
								std::cout << "║                                                                ║" << std::endl;
								std::cout << "╠ 1 - Anfíbio                                                    ║" << std::endl;
								std::cout << "╠ 2 - Ave                                                        ║" << std::endl;
								std::cout << "╠ 3 - Mamífero                                                   ║" << std::endl;
								std::cout << "╠ 4 - Réptil                                                     ║" << std::endl;
								std::cout << "╠ 5 - Voltar                                                     ║" << std::endl;
								std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
								std::cout << "Sua Opção: ";
	                            std::cin >> _aux;
	                            std::cin.ignore(10, '\n');
	                            switch(_aux){
	                            	case 1:
	                            		acoesAnimais.consulta(gerencAnimal, "Amphibia");
	                            		break;
	                            	case 2:
	                            		acoesAnimais.consulta(gerencAnimal, "Aves");
	                            		break;
	                            	case 3:
	                            		acoesAnimais.consulta(gerencAnimal, "Mammalia");
	                            		break;
	                            	case 4:
	                            		acoesAnimais.consulta(gerencAnimal, "Reptilia");
	                            		break;
	                            	case 5:
	                            		opcaoInicial = 0;
	                            		break;
	                            	default:
	                            		std::cout << "A Opção Digitada Não Está Dentro das Opções Disponíveis." << std::endl << std::endl;
	                            }
	                        }
                            break;
                        case 3:
                            opcaoCadastro = 0;
                            break;
                        default:
                            std::cout << "A Opção Digitada Não Está Disponível." << std::endl;
                    }
                }
                break;
			case 5:
				while(opcaoCadastro != 0){
					std::cout << "Digite o ID do Funcionário. Digite 0 Para Voltar." << std::endl;
					std::cin >> _aux;
					std::cin.ignore(20, '\n');
					if(_aux == 0){
						opcaoCadastro = 0;
					}else{
						acoesAnimais.consultaWithFunID(gerencAnimal, _aux);
					}
				}
				break;
			case 6:
				while(opcaoCadastro != 0){
					std::cout << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
					std::cout << "║                    Cadastro de Funcionários                    ║" << std::endl;
					std::cout << "║                                                                ║" << std::endl;
					std::cout << "╠ 1 - Veterinário                                                ║" << std::endl;
					std::cout << "╠ 2 - Tratador                                                   ║" << std::endl;
					std::cout << "╠ 3 - Voltar                                                     ║" << std::endl;
					std::cout << "╚════════════════════════════════════════════════════════════════╝" << std::endl;
					std::cout << "Sua Opção: ";
					std::cin >> opcaoCadastro;
					std::cout << std::endl;
					std::cin.ignore(20, '\n');
					switch(opcaoCadastro){
						case 1:
							cadastrarFuncionario("Veterinario");
							break;
						case 2:
							cadastrarFuncionario("Tratador");
							break;
						case 3:
							opcaoCadastro = 0;
							break;
						default:
							std::cout << "A Opção Digitada Não Está Disponível." << std::endl;
					}
				}
				break;
			case 7:
				std::cout << "Qual o ID do Funcionário que Você Quer Alterar? Digite 0 Para Voltar." << std::endl;
					std::cin >> _aux;
					std::cout << std::endl;
					std::cin.ignore(10, '\n');
					if(_aux == 0){
						opcaoCadastro = 0;
					}else{
						alterarFuncionario(_aux);
					}
                break;
			case 8:
				std::cout << "Digite o ID do Funcionario que Quer Excluir." << std::endl;
				std::cin >> _aux;
				std::cin.ignore(20, '\n');
				acoesFuncionarios.remocao(gerencFunc, _aux);
				break;
			case 9:
				acoesFuncionarios.mostrarFuncionarios(gerencFunc);
				break;
			case 0:
				menuInicial = false;
				break;
			default:
				std::cout << std::endl << "A Opção Digitada Não Corresponde a Nenhuma das Opções Disponíveis." << std::endl;
				std::cout << "Entre com a Opção Novamente." << std::endl << std::endl;
		}
	}
	escreverDados();
}

//Método responsável por verificar se os arquivos abriram e o passar para as funções de leitura correspondente.
void Gerenciamento::lerDados(void){
	std::ifstream arqLerAnimal(pathArqAnimal);
	std::ifstream arqLerFuncionario(pathArqFuncionario);

	try{
		if(!arqLerFuncionario){
			std::ofstream teste(pathArqAnimal);
			if(!teste) throw ErroArquivo();
			teste.close();
		}
	}catch(ErroArquivo &erro){
		std::cerr << erro.what() << std::endl;
		exit(1);
	}

	try{
		if(!arqLerFuncionario){
			std::ofstream teste(pathArqFuncionario);
			if(!teste) throw ErroArquivo();
			teste.close();
		} 
	}catch(ErroArquivo &erro){
		std::cerr << erro.what() << std::endl;
		exit(1);
	}

	lerAnimal(arqLerAnimal);
	lerFuncionario(arqLerFuncionario);

	
	arqLerFuncionario.close();
	arqLerAnimal.close();
}

//Método usado para ler os dados dos animais de um arquivo.
void Gerenciamento::lerAnimal(std::ifstream &_dadosAnimal){
	std::stringstream line;
	std::string ler_Classe, ler_NomeComum, ler_NomeCientifico, ler_Dieta, ler_NomeBatismo, ler_aux, ler_IBAMA, ler_Origem,
				ler_Licen = "-";
	int ler_AnimalID, ler_Veterinario, ler_Tratador;
	char ler_Sexo;
	double ler_Tamanho;

	bool ler_Venenoso;
	std::string ler_UltimaMuda, ler_CorPelo, ler_TipoVeneno;
	int ler_TotalMudas;
	double ler_TamanhoBico, ler_EnvergaduraAsas;

	while(std::getline(_dadosAnimal, ler_aux)){
		line << ler_aux;

		std::getline(line, ler_aux, delimit);
		ler_AnimalID = std::stoi(ler_aux);
		std::getline(line, ler_Classe, delimit);
		std::getline(line, ler_NomeComum, delimit);
		std::getline(line, ler_NomeCientifico, delimit);
		std::getline(line, ler_NomeBatismo, delimit);
		std::getline(line, ler_aux, delimit);
		ler_Sexo = ler_aux[0];
		std::getline(line, ler_aux, delimit);
		ler_Tamanho = std::stod(ler_aux);
		std::getline(line, ler_Dieta, delimit);
		std::getline(line, ler_aux, delimit);
		ler_Veterinario = std::stoi(ler_aux);
		std::getline(line, ler_aux, delimit);
		ler_Tratador = std::stoi(ler_aux);

		if(ler_Classe.compare("Amphibia") == 0){
			std::getline(line, ler_aux, delimit);
			ler_TotalMudas = std::stoi(ler_aux);
			std::getline(line, ler_UltimaMuda, delimit);
		}else if(ler_Classe.compare("Aves") == 0){
			std::getline(line, ler_aux, delimit);
			ler_TamanhoBico = std::stod(ler_aux);
			std::getline(line, ler_aux, delimit);
			ler_EnvergaduraAsas = std::stod(ler_aux);
		}else if(ler_Classe.compare("Mammalia") == 0){
			std::getline(line, ler_CorPelo, delimit);
		}else{
			std::getline(line, ler_aux, delimit);
			std::getline(line, ler_TipoVeneno, delimit);

			if(ler_aux.compare("1") == 0){
				ler_Venenoso = true;
			}else{
				ler_Venenoso = false;
			}			
		}

		std::getline(line, ler_IBAMA, delimit);
		std::getline(line, ler_Origem, delimit);
		std::getline(line, ler_Licen, delimit);

		//Condicionais usados para identificar a classe correta do animal, criar o ponteiro inteligente e adicionar ao MAP.
		if(ler_Classe.compare("Amphibia") == 0){
			if(ler_Licen.compare("-") == 0){
				std::shared_ptr <Animal> novoAnfEx = std::make_shared <AnfibioExotico> (ler_AnimalID, "AnfibioExotico", ler_NomeComum,
										   			 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario,
													 ler_Tratador, ler_NomeBatismo, ler_TotalMudas, ler_UltimaMuda, ler_IBAMA,
													 ler_Origem);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novoAnfEx));
			}else{
				std::shared_ptr <Animal> novoAnfNa = std::make_shared <AnfibioNativo> (ler_AnimalID, "AnfibioNativo", ler_NomeComum,
													 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario, 
													 ler_Tratador, ler_NomeBatismo, ler_TotalMudas, ler_UltimaMuda, ler_IBAMA,
													 ler_Origem, ler_Licen);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novoAnfNa));
			}
		}else if(ler_Classe.compare("Aves") == 0){
			if(ler_Licen.compare("-") == 0){
				std::shared_ptr <Animal> novaAveEx = std::make_shared <AveExotica> (ler_AnimalID, "AveExotica", ler_NomeComum,
										   			 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario,
										   			 ler_Tratador, ler_NomeBatismo, ler_TamanhoBico, ler_EnvergaduraAsas,
										   			 ler_IBAMA, ler_Origem);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novaAveEx));
			}else{
				std::shared_ptr <Animal> novaAveNa = std::make_shared <AveNativa> (ler_AnimalID, "AveNativa", ler_NomeComum,
													 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario, 
													 ler_Tratador, ler_NomeBatismo, ler_TamanhoBico, ler_EnvergaduraAsas,
													 ler_IBAMA, ler_Origem, ler_Licen);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novaAveNa));
			}
		}else if(ler_Classe.compare("Mammalia") == 0){
			if(ler_Licen.compare("-") == 0){
				std::shared_ptr <Animal> novoMamEx = std::make_shared <MamiferoExotico> (ler_AnimalID, "MamiferoExotico", ler_NomeComum,
										   			 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario,
										  			 ler_Tratador, ler_NomeBatismo, ler_CorPelo, ler_IBAMA, ler_Origem);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novoMamEx));
			}else{
				std::shared_ptr <Animal> novoMamNa = std::make_shared <MamiferoNativo> (ler_AnimalID, "MamiferoNativo", ler_NomeComum,
													 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario, 
													 ler_Tratador, ler_NomeBatismo, ler_CorPelo, ler_IBAMA, ler_Origem, ler_Licen);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novoMamNa));
			}
		}else{
			if(ler_Licen.compare("-") == 0){
				std::shared_ptr <Animal> novoRepEx = std::make_shared <ReptilExotico> (ler_AnimalID, "ReptilExotico", ler_NomeComum,
										   ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario,
										   ler_Tratador, ler_NomeBatismo, ler_Venenoso, ler_TipoVeneno, ler_IBAMA, ler_Origem);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novoRepEx));
			}else{
				std::shared_ptr <Animal> novoRepNa = std::make_shared <ReptilNativo> (ler_AnimalID, "ReptilNativo", ler_NomeComum,
													 ler_NomeCientifico, ler_Sexo, ler_Tamanho, ler_Dieta, ler_Veterinario, 
													 ler_Tratador, ler_NomeBatismo, ler_Venenoso, ler_TipoVeneno, ler_IBAMA,
													 ler_Origem, ler_Licen);
				gerencAnimal.insert(std::pair <int, std::shared_ptr<Animal>> (ler_AnimalID, novoRepNa));
			}
		}
	}
}

	//Método usado para ler os dados dos animais de um arquivo.
void Gerenciamento::lerFuncionario(std::ifstream &_dadosFuncionarios){
	int ler_FuncionarioID, ler_Idade, ler_TratSeguranca;
	std::string ler_Funcao, ler_Nome, ler_CPF, ler_TipoSanguineo, ler_Especialidade, ler_aux, ler_VetCRMV;
	char ler_FatorRH;
	std::stringstream line;

	while(std::getline(_dadosFuncionarios, ler_aux)){
		line << ler_aux;

		std::getline(line, ler_aux, delimit);
		ler_FuncionarioID = std::stoi(ler_aux);
		std::getline(line, ler_Funcao, delimit);
		std::getline(line, ler_Nome, delimit);
		std::getline(line, ler_CPF, delimit);
		std::getline(line, ler_aux, delimit);
		ler_Idade = std::stoi(ler_aux);
		std::getline(line, ler_TipoSanguineo, delimit);
		std::getline(line, ler_aux, delimit);
		ler_FatorRH = ler_aux[0];
		std::getline(line, ler_Especialidade, delimit);
		
		//Condicionais usados para identificar a classe correta do funcionário, criar o ponteiro inteligente e adicionar ao MAP.
		if(ler_Funcao.compare("Veterinario") == 0){
			std::getline(line, ler_VetCRMV, delimit);

			std::shared_ptr <Funcionario> funcVet = std::make_shared <Veterinario> (ler_FuncionarioID, ler_Funcao, ler_Nome, ler_CPF,
													ler_Idade, ler_TipoSanguineo, ler_FatorRH, ler_Especialidade, ler_VetCRMV);
			gerencFunc.insert(std::pair <int, std::shared_ptr <Funcionario>> (ler_FuncionarioID, funcVet));
		}else{
			std::getline(line, ler_aux, delimit);
			ler_TratSeguranca = std::stoi(ler_aux);

			std::shared_ptr <Funcionario> funcTrat = std::make_shared <Tratador> (ler_FuncionarioID, ler_Funcao, ler_Nome, ler_CPF,
													 ler_Idade, ler_TipoSanguineo, ler_FatorRH, ler_Especialidade, ler_TratSeguranca);
			gerencFunc.insert(std::pair <int, std::shared_ptr <Funcionario>> (ler_FuncionarioID, funcTrat));
		}
	}
}

//Método responsável por verificar se o arquivo abriu corretamente e o manda para as funções correspondentes.
void Gerenciamento::escreverDados(void){
	std::ofstream arqEscAnimal(pathArqAnimal);
	std::ofstream arqEscFuncionario(pathArqFuncionario);

	try{
		if(!arqEscAnimal) throw ErroArquivo();
	}catch(ErroArquivo &erro){
		std::cerr << erro.what() << std::endl;
		exit(1);
	}

	try{
		if(!arqEscFuncionario) throw ErroArquivo();
	}catch(ErroArquivo &erro){
		std::cerr << erro.what() << std::endl;
		exit(1);
	}

	escreverAnimal(arqEscAnimal);
	escreverFuncionario(arqEscFuncionario);

	arqEscAnimal.close();
	arqEscFuncionario.close();
}

//Método responsável por pegar os dados dos animais no MAP e salvar em arquivo recebido por referência.
void Gerenciamento::escreverAnimal(std::ofstream &_arqAnim){
	for(auto i = gerencAnimal.begin(); i != gerencAnimal.end(); i++){
		//Condicionais para verificar a classe correta do animal e salvar os dados no arquivo corretamente.
		if((i->second)->getClasse().compare("AnfibioExotico") == 0){
			std::shared_ptr <AnfibioExotico> aux = std::static_pointer_cast <AnfibioExotico> (i->second);

			_arqAnim << aux->getID() << delimit << "Amphibia" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getTotalMudas() << delimit <<
						aux->getDataUltimaMuda() << delimit << aux->getAutorIBAMA() << delimit << aux->getPaisOrigem() <<
						delimit << "-" << delimit << std::endl;
		}else if((i->second)->getClasse().compare("AnfibioNativo") == 0){
			std::shared_ptr <AnfibioNativo> aux = std::static_pointer_cast <AnfibioNativo> (i->second);

			_arqAnim << aux->getID() << delimit << "Amphibia" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getTotalMudas() << delimit <<
						aux->getDataUltimaMuda() << delimit << aux->getAutorIBAMA() << delimit << aux->getUF_Origem() <<
						delimit << aux->getLicenTrans() << delimit << std::endl;
		}else if((i->second)->getClasse().compare("AveExotica") == 0){
			std::shared_ptr <AveExotica> aux = std::static_pointer_cast <AveExotica> (i->second);

			_arqAnim << aux->getID() << delimit << "Aves" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getTamanhoBico() << delimit <<
						aux->getEnvergadura() << delimit << aux->getAutorIBAMA() << delimit << aux->getPaisOrigem() <<
						delimit << "-" << delimit << std::endl;
		}else if((i->second)->getClasse().compare("AveNativa") == 0){
			std::shared_ptr <AveNativa> aux = std::static_pointer_cast <AveNativa> (i->second);

			_arqAnim << aux->getID() << delimit << "Aves" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getTamanhoBico() << delimit <<
						aux->getEnvergadura() << delimit << aux->getAutorIBAMA() << delimit << aux->getUF_Origem() <<
						delimit << aux->getLicenTrans() << delimit << std::endl;
		}else if((i->second)->getClasse().compare("MamiferoExotico") == 0){
			std::shared_ptr <MamiferoExotico> aux = std::static_pointer_cast <MamiferoExotico> (i->second);

			_arqAnim << aux->getID() << delimit << "Mammalia" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getCorPelo() << delimit <<
						aux->getAutorIBAMA() << delimit << aux->getPaisOrigem() << delimit << "-" << delimit << std::endl;
		}else if((i->second)->getClasse().compare("MamiferoNativo") == 0){
			std::shared_ptr <MamiferoNativo> aux = std::static_pointer_cast <MamiferoNativo> (i->second);

			_arqAnim << aux->getID() << delimit << "Mammalia" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getCorPelo() << delimit <<
						aux->getAutorIBAMA() << delimit << aux->getUF_Origem() << delimit << aux->getLicenTrans() << delimit << std::endl;
		}else if((i->second)->getClasse().compare("ReptilExotico") == 0){
			std::shared_ptr <ReptilExotico> aux = std::static_pointer_cast <ReptilExotico> (i->second);

			_arqAnim << aux->getID() << delimit << "Reptilia" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getVenenoso() << delimit <<
						aux->getTipoVeneno() << delimit << aux->getAutorIBAMA() << delimit << aux->getPaisOrigem() <<
						delimit << "-" << delimit << std::endl;
		}else{
			std::shared_ptr <ReptilNativo> aux = std::static_pointer_cast <ReptilNativo> (i->second);

			_arqAnim << aux->getID() << delimit << "Reptilia" << delimit << aux->getNomeComum() << delimit <<
						aux->getNomeCientifico() << delimit << aux->getNomeBatismo() << delimit << aux->getSexo() <<
						delimit << aux->getTamanho() << delimit << aux->getDieta() << delimit << aux->getVeterinarioID() <<
						delimit << aux->getTratadorID() << delimit << aux->getVenenoso() << delimit <<
						aux->getTipoVeneno() << delimit << aux->getAutorIBAMA() << delimit << aux->getUF_Origem() <<
						delimit << aux->getLicenTrans() << delimit << std::endl;
		}
	}
}

//Método responsável por pegar os dados dos animais no MAP e salvar em arquivo recebido por referência.
void Gerenciamento::escreverFuncionario(std::ofstream &_arqFunc){
	for(auto i = gerencFunc.begin(); i != gerencFunc.end(); i++){
	//Condicionais para verificar a classe correta do animal e salvar os dados no arquivo corretamente.
		if((i->second)->getFuncao().compare("Veterinario") == 0){
			std::shared_ptr <Veterinario> aux = std::static_pointer_cast <Veterinario> (i->second);
			_arqFunc << aux->getID() << delimit << aux->getFuncao() << delimit << aux->getNome() << delimit << aux->getCPF() << delimit
					 << aux->getIdade() << delimit << aux->getTipoSanguineo() << delimit << aux->getFatorRH() << delimit << aux->getEspecialidade()
					 << delimit << aux->getCRMV() << delimit << std::endl;
		}else{
			std::shared_ptr <Tratador> aux = std::static_pointer_cast <Tratador> (i->second);
			_arqFunc << aux->getID() << delimit << aux->getFuncao() << delimit << aux->getNome() << delimit << aux->getCPF() << delimit
					 << aux->getIdade() << delimit << aux->getTipoSanguineo() << delimit << aux->getFatorRH() << delimit << aux->getEspecialidade()
					 << delimit << aux->getNivelSeguranca() << delimit << std::endl;
		}
	}
}

//Método para realizar o cadastro de um animal a partir do template de classes.
void Gerenciamento::cadastrarAnimal(std::string _classe){
	int aux = 1;

	//Laço para ver o primeiro ID disponível para ser usado no cadastro e o usa automaticamente no cadastro do animal.
	for(auto i = gerencAnimal.begin(); i != gerencAnimal.end(); i++, aux++);
	acoesAnimais.cadastro(gerencAnimal, _classe, aux);

	auto i = gerencAnimal.end();
	i--;

	//Condicionais para verificar se o Tratador e o Veterinário já estão cadastrados no sistema.
	aux = i->second->getTratadorID();
	if(gerencFunc.find(aux) == gerencFunc.end()){
		std::cout << std::endl << "O ID do Tratador Não Foi Encontrado no Sistema." << std::endl <<
					 "Chamando Função de Cadastro do Tratador..." << std::endl << std::endl;
		acoesFuncionarios.cadastro(gerencFunc, "Tratador", i->second->getTratadorID());
	}
	aux = i->second->getVeterinarioID();
	if(gerencFunc.find(aux) == gerencFunc.end()){
		std::cout << std::endl << "O ID do Veterinário Não Foi Encontrado no Sistema." << std::endl <<
					 "Chamando Função de Cadastro do Veterinário..." << std::endl << std::endl;
		acoesFuncionarios.cadastro(gerencFunc, "Veterinario", i->second->getVeterinarioID());
	}
	std::cout << "Animal Cadastrado Com Sucesso." << std::endl << std::endl;
}

void Gerenciamento::cadastrarFuncionario(std::string _classe){
	int aux = 1;

	//Laço para ver o primeiro ID disponível para ser usado no cadastro e o usa automaticamente no cadastro do funcionário.
	for(auto i = gerencFunc.begin(); i != gerencFunc.end(); i++, aux++);
	acoesFuncionarios.cadastro(gerencFunc, _classe, aux);
}

void Gerenciamento::alterarAnimal(int _ID_Animal){
	int aux;
	//Verificação para ver se o animal está realmente cadastrado.
	auto i = gerencAnimal.find(_ID_Animal);
	acoesAnimais.alteracao(i->second);

	//Condicionais para verificar se, em caso de alteração, o Tratador e o Veterinário já estão cadastrados no sistema.
	aux = i->second->getTratadorID();
	if(gerencFunc.find(aux) == gerencFunc.end()){
		std::cout << std::endl << "O ID do Tratador Não Foi Encontrado no Sistema." << std::endl <<
					 "Chamando Função de Cadastro do Tratador..." << std::endl << std::endl;
		acoesFuncionarios.cadastro(gerencFunc, "Tratador", i->second->getTratadorID());
	}

	aux = i->second->getVeterinarioID();
	if(gerencFunc.find(aux) == gerencFunc.end()){
		std::cout << std::endl << "O ID do Veterinário Não Foi Encontrado no Sistema." << std::endl <<
					 "Chamando Função de Cadastro do Veterinário..." << std::endl << std::endl;
		acoesFuncionarios.cadastro(gerencFunc, "Veterinario", i->second->getVeterinarioID());
	}
}

void Gerenciamento::alterarFuncionario(int _ID_Funcionario){
	//Verificação para ver se o funcionário está realmente cadastrado.
	auto i = gerencFunc.find(_ID_Funcionario);
	acoesFuncionarios.alteracao(i->second);
}