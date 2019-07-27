#ifndef ANIMAL_H
#define ANIMAL_H

#include "funcionario.h"

//Classe criada para representar o objeto Animal.
class Animal{
	//Atributos protegidos da classe (podem ser acessados pela classe e pelas classes derivadas).
	protected:
		int ani_ID;
		std::string ani_Classe;
		std::string ani_NomeComum;
		std::string ani_NomeCientifico;
		char ani_Sexo;
		double ani_Tamanho;
		std::string ani_Dieta;
		int ani_Veterinario;
		int ani_Tratador;
		std::string ani_NomeBatismo;

	public:
		//Construtor parametrizado.
		Animal(int _ani_ID, std::string _ani_Classe, std::string _ani_NomeComum, std::string _ani_NomeCientifico, char _ani_Sexo,
			   double _ani_Tamanho, std::string _ani_Dieta, int _ani_Veterinario, int _ani_Tratador, std::string _ani_NomeBatismo);
		//Construtor padrão.
		Animal(void);		
		//Destrutor.
		~Animal(void);
		
		//Métodos virtuais puros para serem implementados pelas classes derivadas.
		virtual int getID(void);
		virtual std::string getClasse(void);
		virtual std::string getNomeComum(void) = 0;
		virtual std::string getNomeCientifico(void) = 0;
		virtual char getSexo(void) = 0;
		virtual double getTamanho(void) = 0;
		virtual std::string getDieta(void) = 0;
		virtual int getVeterinarioID(void) = 0;
		virtual int getTratadorID(void) = 0;
		virtual std::string getNomeBatismo(void) = 0;
};

#endif