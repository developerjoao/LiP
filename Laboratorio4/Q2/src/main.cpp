/**
* @file main.cpp
* @brief Aplicação da calculadora implementada.
*/

#include <iostream>
#include "calculadora.h"

int main()
{
    Calculadora teste;
    std::cout<<"Digite a expressao no formato RPN [4 2 2 + / =] ->[(2 + 2) / 4 =] que deseja calcular, lembre de colocar o \"=\" no final"<<std::endl;
    recebeDados(teste);
    std::cout<<"Resultado: ";
    teste.calcula();

    return 0;
}
