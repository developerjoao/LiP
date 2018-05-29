/**
* @file roupa.h
* @brief Declaração das funções utilizadas no roupa.cpp
*/

#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, short _preco, 
			std::string _marca, char _sexo, short _tamanho);
	~Roupa();
private:
	std::string m_marca;
	char m_sexo;
	short m_tamanho;
public:
	/**
	* @brief Getters
	*/

	std::string getMarca();
	char getSexo();
	short getTamanho();
	
	/**
	* @brief Setters
	*/
	
	void setMarca(std::string _marca);
	void setSexo(char _sexo);
	void setTamanho(short _tamanho);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif