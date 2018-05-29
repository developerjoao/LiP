/**
* @file bebida.cpp
* @brief Implementação das funções utilizadas no bebida.h
*/


#include <iomanip>
#include "bebida.h"

Bebida::Bebida() {}

Bebida::Bebida(std::string _codigo, std::string _descricao, short _preco, 
			 float _teor):
	Produto(_codigo, _descricao, _preco), m_teor(_teor) {}

Bebida::~Bebida() {}

float
Bebida::getTeor() {
	return m_teor;
}


void 
Bebida::setTeor(float _teor){
	while(_teor>100.0){
		std::cout<<"insira um teor alcoolico válido:";
		std::cin>>_teor;
	}
	m_teor = _teor;
}
 
std::ostream& 
Bebida::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (10) << m_teor;
	return o;
}
