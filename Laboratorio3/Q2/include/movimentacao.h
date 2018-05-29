/**
* @file movimentacao.h
* @brief Desclaracao das funcoes que serao utilizadas no movimentacao.cpp
*/

#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include "corrente.h"

class Movimentacao : public Corrente
{
	private:
		string m_descricao;
		int m_valor;
		string m_tipo;
	
	public:
		Movimentacao();
		Movimentacao(string _descricao, int _valor, string _tipo);
		~Movimentacao();

		/**
		* @brief setters.
		*/
		void setDescricao(string _descricao);
		void setValor(int _valor);
		void setTipo(int _tipo);
		/**
		* @brief getters.
		*/
		string getDescricao();
		int getValor();
		string getTipo();
};


#endif