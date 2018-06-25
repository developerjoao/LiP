/**
* @file main.cpp
* @brief implementação do arquivo principal da questão 2
* @author Joao Victor Fernandes Cabral
*/
#include "jogo.h"

int Jogador::valorLimite =0;

int main(){
	Jogo jogo;
	jogo.adicionaJogador();
	while(!jogo.getAcabou()){
		jogo.rodada();
	}
	jogo.rodada();//Esta chama da função serve para imprimir o vencedor.
	return 0;
}