/**
* @file bebida.h
* @brief Definição das funções implementadas no bebida.cpp
*/

#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"

class Bebida : public Produto
{
public:
	Bebida();
	Bebida(std::string _codigo, std::string _descricao, short _preco, 
			float _teor);
	~Bebida();
private:
	float m_teor;
public:
	/**
	* @brief Getters
	*/

	float getTeor();
	
	/**
	* @brief Setters
	*/

	void setTeor(float _teor);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif