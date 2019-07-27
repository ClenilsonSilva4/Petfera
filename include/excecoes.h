#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>

//Classes criadas para serem usadas pela aplicação para disparar exceções e evitar que a execução pare por um dado inserido errado.
class ErroArquivo: public std::invalid_argument{
    public:
        ErroArquivo(void): std::invalid_argument("Não foi possível abrir o arquivo. \nVerifique se o arquivo existe.\n") {}
};

class ErroCadastro: public std::invalid_argument{
    public:
        ErroCadastro(void): std::invalid_argument("Este Campo É Obrigatório. \nEntre Com o Dado de Acordo com o Comando.\n") {}
};

class ErroBusca: public std::invalid_argument{
	public:
		ErroBusca(void): std::invalid_argument("O Dado Não Foi Encontrado na Base de Dados.\n"){}
};

#endif