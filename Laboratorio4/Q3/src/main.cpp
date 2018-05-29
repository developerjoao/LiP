#include <iostream>
#include "pilha.h"
#include "lista.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    /*
	cout << "Testando a lista..." << endl;

	ListaLigada<int> lista1;
	cout << "Tamanho: " << lista1.size() << endl;
	lista1.InsereNoFinal(2);
	lista1.InsereNoFinal(3);
	lista1.InsereNoFinal(4);
	lista1.InsereNaPosicao(0,1);
	lista1.InsereNoFinal(6);
	lista1.InsereNaPosicao(4,5);
	lista1.InsereNoFinal(7);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNaPosicao(3);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoInicio();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoFinal();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	*/
	cout << "Testando a lista..." << endl;

	ListaCircular<int> lista1;
	cout << "Tamanho: " << lista1.size() << endl;
	lista1.InsereNoInicio(7);
	lista1.InsereNoInicio(8);
	lista1.InsereNoInicio(9);
	cout << "Tamanho: " << lista1.size() << endl;


	return 0;
}
