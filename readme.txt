Projeto Final

Data: 30/05/2019
Componentes: Fábio Leonardo Brito de Sousa 
			 Clenilson Jose Silva de Sousa
			 Vanessa Sayuri Uchida


******************************************************************* Dificuldades do Projeto *******************************************************************
No início foi difícil encontrar uma forma para organizar todos os dados em apenas dois MAPS, mas foi resolvido com o uso de ponteiros inteligentes.
O maior problema, com toda certeza, foi eu (Clenilson) ter feito 90% do projeto sozinho, já que meus colegas sempre davam desculpas para começar a fazer
e não queria confiar neles para fazer de última hora e acabar ficando com uma nota baixa por isso. Além disso, eles apresentaram pouco conhecimento do conteúdo
da disciplina (a Vanessa principalmente), havendo momentos em que eles estavam completamente perdidos no desenvolvimento do projeto.


******************************************************************** Objetivo e Instruções ********************************************************************
O programa tem como objetivo realizar o cadastro de animais da loja PetFera.

Instruções para executar:

- Abra o terminal
- Dentro da pasta Projeto Final, há um arquivo com o nome MAKEFILE. Para compilar o programa digite o comando "make" no terminal. Esse comando irá compilar e
  linkar os objetos, criando o programa Projeto Final.
- Em seguida digite "make run" no terminal

Opções disponíveis para o usuário:


1 - Cadastro de Animal                                
2 - Remover Animal                                      
3 - Alterar Dados de um Animal Já Cadastrado             
4 - Consultar Dados de um Animal ou Classe de Animais     
5 - Consultar Animais Pelo Veterinário ou Tratador Responsável
6 - Cadastro de Funcionários                               
7 - Alterar Dados de um Funcionário                          
8 - Remoção de um Funcionário
9 - Mostra Todos os Funcionários Cadastrados
0 - Encerrar o Sistema         


_________________________________________________________________________________________
OPÇÃO 1 - CADASTRO DE ANIMAL - Realiza o cadastro de um animal.
	
O usuário deverá escolher dentre esses tipos de animais que deseja cadastrar:

	- Anfibio Exótico: escolha esta opção se deseja cadastrar um anfíbio do tipo exótico;

	- Anfíbio Nativo: escolha esta opção se deseja cadastrar um anfíbio do tipo nativo;

	- Ave Exótica: escolha esta opção se deseja cadastrar uma ave do tipo exótica;

	- Ave Nativa: escolha esta opção se deseja cadastrar uma ave do tipo nativa;

	- Mamífero Exótico: escolha esta opção se deseja cadastrar um mamífero do tipo exótico;

	- Mamífero Nativo: escolha esta opção se deseja cadastrar um mamífero do tipo nativo;

	- Réptil Exótico: escolha esta opção se deseja cadastrar um réptil do tipo exótico;

	- Réptil Nativo: escolha esta opção se deseja cadastrar um réptil do tipo nativo;

	- Voltar: retorna ao menu anterior

	Após escolher o tipo de animal serão solicitados dados comuns a todos os animais:
	-ID do animal: digite a ID do animal (somente números)
	-Nome comum do animal: digite o nome comum do animal
	-Nome Científico do Animal: digite o nome científico do animal
	-Nome de Batismo do Animal: digite o nome de batismo do animal
	-Sexo do animal: digite F para fêmea ou M para macho (em caixa alta)
	-Tamanho do animal em metros: digite o tamanho do animal em metros (somente números)
	-Dieta predominante do animal: digite qual o tipo de alimento ingerido pelo animal
	-ID do veterinário: digite a ID do veterinário associado ao animal (somente números). Se o animal não tiver nenhum veterinário digite 0
	-ID do tratador: digite a ID do tratador associado ao animal (somente números). Se o animal não tiver nenhum tratador digite 0
	-Código de autorização do IBAMA: digite o código de autorização (somente números)	


	Para cada tipo de animal será solicitado dados específicos:
AVE
-Tamanho do bico do animal: digite o tamanho do bico do animal em metros
-Tamanho da envergadura do animal: digite o tamanho da envergadura do animal em metros

ANFÍBIO
-Quantidade de mudas realizadas: digite a quantidade de mudas de pele que o animal teve até o momento do cadastro
-Data da última troca de pele: digite a data em que houve a última troca de pele do animal

MAMÍFERO
-Cor do pelo do animal: digite a cor do pelo do animal

RÉPTIL
-Animal Venenoso? digite S para sim ou N para não (em caixa alta)
-Tipo do veneno: digite o tipo de veneno do animal


	Para animais do tipo EXÓTICO, serão solicitados também:
	
	País de origem do animal: digite o país ao qual o animal é originário
	

	Para animais do tipo NATIVO, serão solicitados também:
	
	Estado de Origem do Animal: digite a sigla do estado ao qual o animal é originário
	Licença de transporte do animal: digite a licença do animal (somente números)

__________________________________________________________________________________________
OPÇÃO 2 - REMOVER ANIMAL: realiza a remoção de um animal que se encontra cadastrado no programa, através do ID cadastrado;

__________________________________________________________________________________________
OPÇÃO 3 - ALTERAR DADOS DE UM ANIMAL JÁ CADASTRADO: realiza a alteração de dados de um animal que se encontra cadastrado no programa;

__________________________________________________________________________________________
OPÇÃO 4 - CONSULTA DADOS DE UM ANIMAL OU CLASSE DE ANIMAIS: realiza a consulta de dados de um animal que se encontra cadastrado no programa;

Nesta opção o usuário poderá escolher se quer realizar a consulta fornecendo: o ID do animal ou a Classe do animal

__________________________________________________________________________________________
OPÇÃO 5 - CONSULTAR ANIMAIS PELO VETERINÁRIO OU TRATADOR RESPONSÁVEL: realiza a consulta de animais através do funcionário que está associado ao animal;

Nesta opção o usuário poderá escolher se quer realizar a consulta fornecendo: o ID do veterinário ou o ID do tratador

__________________________________________________________________________________________
OPÇÃO 6 - CADASTRO DE FUNCIONÁRIOS: realiza o cadastro de funcionarios (veterinário ou tratador) da empresa PET FERA

O usuário deverá escolher uma das opções:
 - Veterinário: realiza o cadastro de um veterinário
 - Tratador: realiza o cadastro de um tratador
 - Voltar: Retorna ao menu anterior

Serão solicitados os seguintes dados:

	-ID: digite a ID do funcionário
	-Idade: digite a idade do funcionário
	-Nome: digite o nome do funcionário
	-CPF: digite o CPF do funcionário (composto por 11 números)
	-Tipo sanguíneo: digite o tipo sanguíneo do funcionário (A, B, AB ou O)
	-Fator RH: digite o fator RH do sangue do funcionário (- ou +)
	-Especialidade: digite a especialidade do funcionário
	-Código CRMV: opção disponível apenas para veterinários. Deve ser digitado no formato UF - 000000 (onde UF representa a sigla regional e 000000, a quantidade de números que devem ser digitados)
	-Nível de segurança: opção disponível apenas para tratador. Deve ser digitado apenas números:
	0 - indica que o tratador só pode tratar aves;
	1 - indica que o tratador só pode tratar aves, mamíferos e répteis
	2 - indica que o tratador possui experiência na manipulaçao de animais venenosos ou perigosos


__________________________________________________________________________________________
OPÇÃO 7 - ALTERAR DADOS DE UM FUNCIONÁRIO: realiza a alteração de dados cadastrados de um funcionário;


__________________________________________________________________________________________
OPÇÃO 8 - REMOÇÃO DE UM FUNCIONÁRIO: realiza a remoção de um funcionário cadastrado, através do ID cadastrado do funcionário.

__________________________________________________________________________________________
OPÇÃO 9 - ENCERRAR O SISTEMA: Finaliza e fecha o programa.



******************************************************************* Funções no Makefile *******************************************************************
-GDB:
	Para usar, digite "make gdb" e o gdb será aberto já com o programa;

-Clean:
	Para usar, digite "make clean" e as pastas contendo os objetos, a biblioteca e o programa serão excluídas.