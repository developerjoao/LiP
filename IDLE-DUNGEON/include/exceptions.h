/**
* @file exceptions.h
* @brief Declaração do tratamento de exceções para as opções de menu.
*/
#include <stdexcept>
using std::invalid_argument;


class IndiceInvalido : public invalid_argument {
public:
	IndiceInvalido() : invalid_argument("Operacao invalida: Indice maior ou menor do que os esperado.") {}
};
