/**
* @file calculadora.h
* @brief Declaração das funções que serão implementadas no calculadora.cpp
*/

#ifndef CALCULADORA_H
#define CALCULADORA_H

#include<iostream>
#include<stack>
#include<queue>
#include<string>


class Calculadora
{
private:
    std::stack<int> m_valores;
    std::queue<std::string> m_entrada;
    bool ehNumero(std::string &str);
    bool ehOperador(std::string &str);
    void opera(std::string &str);
    /**
	* @brief Somente para debug
    */
    void mostraEntrada(); 
public:

    void calcula();

    friend void recebeDados(Calculadora& calculadora);
    friend std::istream& operator>> (std::istream& is,Calculadora& calculadora);
};

#endif // CALCULADORA_H
