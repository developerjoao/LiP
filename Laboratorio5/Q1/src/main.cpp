/**
* @file main.cpp
* @brief implementação do arquivo principal da questão 1
*/

#include "palindromo.h"


int main(int argc, char** argv){
    string frase;
    getline(cin,frase);
    RemoverEspacosePontuacao(frase);
    RemoverCaracteresEspeciais(frase);
    if(ChecaPalindromo(frase)){
        cout<<"É palindromo"<<endl;
    }
    else{
        cout<<"Não é palindromo"<<endl;
    }

	return 0;
}