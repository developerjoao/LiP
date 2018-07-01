/** @mainpage Projeto Final - LP1
@section purpose IDLE DUNGEON/Overview
Implementação do algoritmo de um jogo IDLE infinito.
@section functions Function Descriptions
Todas as funções são descritas detalhadamente na página de documentação das classes.
@section ui User Interface
A única interface utilizada é o terminal, acessível através de comandos pelo teclado.

 * @file	main.cpp
 * @brief	Cógido fonte princial do IDLE Dungeon
 * @author	João Victor Fernandes Cabral
 * @sa		character.h
 * @sa		equips.h
 * @sa		func.h
 * @sa		monster.h
 * @sa		thief.h
 * @sa		warlock.h
 * @sa		warrior.h

*/

#include "../include/monster.h"
#include "../include/character.h"
#include "../include/equips.h"
#include "../include/warrior.h"
#include "../include/warlock.h"
#include "../include/thief.h"
#include "../include/func.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
* @details Chama a função de inicialização do jogo e todas as demais opções são chamadas através dela.
*/
int main(){
	system("clear");
	intro();
}