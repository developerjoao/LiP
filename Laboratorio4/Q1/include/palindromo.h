/**
* @file palindromo.h
* @brief implementação das funções necessárias para manipulação do palindromo
*/
#ifndef _PALINDROMO_H_
#define _PALINDROMO_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>
#include <vector>
#include <locale>
#include "pilha.h"

using namespace std;

/**
* @brief Função que irá remover os espaços entre as palavras para manipulação da string
*/
void RemoverEspacosePontuacao(string&);

/**
* @brief Função que irá remover os caracteres especiais para manipulação da string
*/
void RemoverCaracteresEspeciais(string&);

/**
* @brief Função que irá checar se a string é palindroma depois de tratados os espaços em branco e os caracteres especiais
*/
bool ChecaPalindromo(string&);

#endif 