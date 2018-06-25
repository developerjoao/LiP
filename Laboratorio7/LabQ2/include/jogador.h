/**
* @file jogo.cpp
* @brief Declaração dos metodos do jogador da questão 2
* @author Joao Victor Fernandes Cabral
*/

#ifndef JOGADOR
#define JOGADOR

#include<string>

using namespace std;

class Jogador
{
private:
	static int valorLimite;
	string nome;
	bool estourou = false;
	int valorAcumulado = 0;
  	bool venceu = false;
  	bool parou = false;
public:
	Jogador();
	~Jogador();
	
	static void setValorLimite(int);

	string getNome();
	void setNome(string);
	bool getEstourou();
  	bool getVenceu();
  	int getValorAcumulado();
  	bool getParou();
  	void setVenceu(bool);
	void vezDeJogar();
	void jogarDados();
};

#endif