/**
* @file corrente.h
* @brief Desclaracao das funcoes que serao utilizadas no corrente.cpp
*/

#ifndef _CORRENTE_H_
#define _CORRENTE_H_

#include <iostream>

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

using namespace std;


class
Corrente{
private:
		int m_agencia;
		int m_num_corrente;
		int m_saldo;
		bool m_especial;
		int m_limite;
		vector<shared_ptr<Corrente>> m_movimentacoes;
		bool m_limitada;


	public:
		Corrente();
		Corrente(int _agencia, int _num_corrente, int _saldo, int _limite, bool _especial, bool _limitada);
		~Corrente();

	public:
		/**
		* @brief setters.
		*/
		void setAgencia(int _agencia);
		void setNumCorrente(int _num_xorrente);
		void setSaldo(int _saldo);
		void setLimite(int _limite);
		void setEspecial(bool _especial);
		void setLimitada(bool _limitada);
		/**
		* @brief getters.
		*/
		int getAgencia();
		int getNumCorrente();
		int getSaldo();
		int getLimite();
		bool getEspecial();
		bool getLimitada();
		friend std::ostream& operator<< (std::ostream &o, Corrente const &t);
};


#endif