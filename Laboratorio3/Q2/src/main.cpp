/**
* @file main.cpp
* @brief Execucao da implementacao de corrente.cpp e movimentacao.cpp. Falta a adicao de fazer movimentacoes.
*/

#include "corrente.h"
#include "movimentacao.h"

int main(int argc, char const *argv[])
{	
	std::vector<shared_ptr<Corrente>> agencia;
	Movimentacao aux;
	/**
	* @brief Adicionando elementos na agencia.
	*/
	agencia.push_back(make_shared<Corrente>(1234,1,4000,4000,false, false));
	agencia.push_back(make_shared<Corrente>(1235,2,5000,9000,false, false));
	agencia.push_back(make_shared<Corrente>(1236,3,6000,8000,true, false));
	agencia.push_back(make_shared<Corrente>(1237,4,7000,10000,false, true));

	/**
	* @brief Imprimindo a movimentacao das contas da agencia.
	*/
	for (auto i = agencia.begin(); i != agencia.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}

	return 0;
}