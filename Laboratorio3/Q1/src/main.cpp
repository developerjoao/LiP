/**
* @file main.cpp
* @brief Execução da implementação dos produtos e classes derivadas de produtos.
* @brief Não compreendi o pedido de implementação da sobrecarga do + e -. Tentei implementar a sobregarga do == mas não deu certo.
*/

#include <iostream>
#include <vector>
#include <memory>
#include "produto.h"
#include "fruta.h"
#include "roupa.h"
#include "bebida.h"

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<shared_ptr<Produto>> lista;
	
	lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	lista.push_back(make_shared<Fruta>("001002003-45","Laranja",4.75,"23/09/2017",15));
	lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
    lista.push_back(make_shared<Roupa>("001002006-00","camiseta",10.00,"GAP ",'M',30));
    lista.push_back(make_shared<Bebida>("001002007-00","Jack Daniels",90.00,50.0));

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}
    bool teste = false;
    teste = lista[0] == lista[1];
    cout<<"Tentando saber se o codigo de barra é igual,(falho):"<<teste<<endl;
	return 0;
}