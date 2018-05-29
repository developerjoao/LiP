/**
* @file corrente.cpp
* @brief Implementacao das funcoes declaradas no corrente.h
*/

#include "corrente.h"

Corrente::Corrente() {}

Corrente::Corrente(int _agencia, int _num_corrente, int _saldo, int _limite, bool _especial, bool _limitada = false)
{
	m_agencia = _agencia;
	m_num_corrente = _num_corrente;
	m_saldo = _saldo;
	m_limite = _limite;
	m_especial = _especial;
	m_limitada = _limitada;
}

Corrente::~Corrente() {}


void Corrente::setAgencia(int _agencia)
{
	m_agencia = _agencia;
}

void Corrente::setNumCorrente(int _num_corrente)
{
	m_num_corrente = _num_corrente;
}

void Corrente::setSaldo(int _saldo)
{
	m_saldo = _saldo;
}

void Corrente::setLimite(int _limite)
{
	m_limite = _limite;
}

void Corrente::setEspecial(bool _especial)
{
	m_especial = _especial;
}

void Corrente::setLimitada(bool _limitada)
{
	m_limitada = _limitada;
}


int Corrente::getAgencia()
{
	return m_agencia;
}

int Corrente::getNumCorrente()
{
	return m_num_corrente;
}

int Corrente::getSaldo()
{
	return m_saldo;
}

int Corrente::getLimite()
{
	return m_limite;
}

bool Corrente::getEspecial()
{
	return m_especial;
}

bool Corrente::getLimitada()
{
	return m_limitada;
}

/**
* @brief operador << sobrecarregado para imprimir todas as movimentacoes de uma conta x.
*/
std::ostream& operator<< (std::ostream &o, Corrente const &t){
	for (auto i = t.m_movimentacoes.begin(); i != t.m_movimentacoes.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}
	return o;
}
