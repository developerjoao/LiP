/**
* @file empresa.h
* @brief Declaração do tratamento de exceções da questão 1
* @author Joao Victor Fernandes Cabral
*/
#include <stdexcept>
using std::invalid_argument;


class IndiceInvalido : public invalid_argument {
public:
	IndiceInvalido() : invalid_argument("Operacao invalida: Indice maior ou menor do que os esperados ou inexistente") {}
};
