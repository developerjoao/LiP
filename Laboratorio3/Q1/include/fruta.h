/**
* @file fruta.h
* @brief Declaração das funções utilizadas no fruta.cpp
*/

#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

class Fruta : public Produto
{
public:
	Fruta();
	Fruta(std::string _codigo, std::string _descricao, short _preco, 
			std::string _data, short _validade);
	~Fruta();
private:
	std::string m_data_lote;
	short m_validade;
public:
	/**
	* @brief Getters
	*/
	
	std::string getDataLote();
	short getValidade();
	
	/**
	* @brief Setters
	*/

	void setDataLote(std::string _data);
	void setValidade(short _validade);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif