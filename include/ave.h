#ifndef AVE_H
#define AVE_H
#include "animal.h"

//Classe criada para representar o objeto Ave.
class Ave: public Animal{
	//Atributos protegidos da classe (podem ser acessados pela própria classe e pelas classes derivadas).
	protected:
		double av_TamanhoBico;
		double av_EnvergaduraAsas;
	public:
		//Construtor parametrizado.
		Ave(int _av_ID, std::string _av_Classe, std::string _av_NomeComum, std::string _av_NomeCientifico, char _av_Sexo,
			double _av_Tamanho, std::string _av_Dieta, int _av_Veterinario, int _av_Tratador, std::string _av_NomeBatismo,
			double _av_TamanhoBico, double _av_EnvergaduraAsas);
		//Construtor padrão.
		Ave(void);
		//Destrutor.
		~Ave(void);

		//Métodos virtuais puros para serem implementados pelas classes derivadas.
		virtual double getTamanhoBico(void) = 0;
		virtual double getEnvergadura(void) = 0;
};

#endif