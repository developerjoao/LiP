/**
* @file jogo.cpp
* @brief implementação do jogador da questão 2
* @author Joao Victor Fernandes Cabral
*/

#include "jogador.h"
#include "exceptions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>  

using namespace std;

Jogador::Jogador(){}
Jogador::~Jogador(){}

void Jogador::setNome(string novoNome){
	nome = novoNome;
}

void Jogador::setValorLimite(int valor){
	valorLimite = valor;
}

string Jogador::getNome(){
	return nome;
}

bool Jogador::getParou(){
  	return parou;
}

bool Jogador::getEstourou(){
	return estourou;
}

int Jogador::getValorAcumulado(){
	return valorAcumulado;
}

void Jogador::setVenceu(bool _venceu){
	venceu = _venceu;
}

bool Jogador::getVenceu(){
	return venceu;
}

void Jogador::jogarDados(){
	srand(time(NULL));
	int dado1 = (rand()%6) +1;
	valorAcumulado += dado1;
	int dado2 = (rand()%6) +1;
	valorAcumulado += dado2;
	cout << "Você tirou " << dado1 << " no primeiro dado ";
	cout << "e " << dado2 << " no segundo dado "<< endl;
	cout << "Agora você está com " <<valorAcumulado << " pontos"<<endl<<endl;
}

/**
* @brief Define se o jogador vai jogar ou não e as aplicações de tal.
*/
void Jogador::vezDeJogar(){
  	parou = false;
	cout<< "vez do(a) " << nome << " jogar"<<endl;
	char opt;
	cout<<"deseja jogar nesta rodada? (s/n)"<<endl;
	cin>>opt;
	try{
		if (opt != 'n' && opt != 's') throw ValorInvalido();
		else{
			if (opt == 'n'){ 
				cout<< "Você escolheu não jogar essa rodada!"<<endl;
				cout<< nome <<" tem "<< valorAcumulado <<" pontos"<<endl<<endl;
		      	parou = true;
				return;
			}

			if(opt == 's'){
				cout<<"Você escolheu jogar essa rodada!"<<endl;
				jogarDados();
			}	
		
			if(valorAcumulado > valorLimite){
				estourou = true;
				valorAcumulado = 0;
				cout << "Você passou do valor limite "<< endl;
				cout << "Você foi eliminado"<<endl<<endl;
				return;
			}else if( valorAcumulado == valorLimite){
				cout << "Sua pontuação é exatamente igual ao limite"<< endl;
				cout << "Parabéns, você ganhou!"<<endl;//TRANSFERIR PARA JOGO
		      	venceu = true;
				return;
			}
		}
	} catch(ValorInvalido &ex){
		cout<<ex.what()<<endl;
		while(opt != 'n' && opt != 's'){
			cout<<"Valor invalido. Digite novamente: ";
			cin>>opt;
		}
		if (opt == 'n'){ 
				cout<< "Você escolheu não jogar essa rodada!"<<endl;
				cout<< nome <<" tem "<< valorAcumulado <<" pontos"<<endl<<endl;
		      	parou = true;
				return;
			}

			if(opt == 's'){
				cout<<"Você escolheu jogar essa rodada!"<<endl;
				jogarDados();
			}	
		
			if(valorAcumulado > valorLimite){
				estourou = true;
				valorAcumulado = 0;
				cout << "Você passou do valor limite "<< endl;
				cout << "Você foi eliminado"<<endl<<endl;
				return;
			}else if( valorAcumulado == valorLimite){
				cout << "Sua pontuação é exatamente igual ao limite"<< endl;
				cout << "Parabéns, você ganhou!"<<endl;//TRANSFERIR PARA JOGO
		      	venceu = true;
				return;
			}
	} catch(...){
		cout<<"Erro inesperado.";
	}
}