/**
* @file movimentacao.cpp
* @brief Implementacao das funcoes declaradas em movimentacao.h
*/

#include "movimentacao.h"

Movimentacao::Movimentacao() {}

Movimentacao::Movimentacao(string _descricao, int _valor, string _tipo)
{
	m_descricao = _descricao;
	m_valor = _valor;
	m_tipo = _tipo;
}

Movimentacao::~Movimentacao() {}

void Movimentacao::setDescricao(string _descricao)
{
	m_descricao = _descricao;
}

void Movimentacao::setValor(int _valor)
{
	m_valor = _valor;
}

void Movimentacao::setTipo(int _tipo)
{
	m_tipo = _tipo;
}


string Movimentacao::getDescricao()
{
	return m_descricao;
}

int Movimentacao::getValor()
{
	return m_valor;
}

string Movimentacao::getTipo()
{
	return m_tipo;
}