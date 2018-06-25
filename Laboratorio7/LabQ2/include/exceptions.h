/**
* @file jogo.cpp
* @brief Declaração do tratamento de exceções da questão 2
* @author Joao Victor Fernandes Cabral
*/
#include <stdexcept>
using std::invalid_argument;


class ValorInvalido : public invalid_argument {
public:
	ValorInvalido() : invalid_argument("Operacao invalida: Valor maior que o esperado.") {}
};
