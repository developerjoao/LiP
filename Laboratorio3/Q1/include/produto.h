/**
* @file produto.h
* @brief Descrição das funções da classe pai, produto.
*/

#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>

class Produto
{
public:
	Produto();
	Produto(std::string _codigo, std::string _descricao, short _preco);
	/**
	* @brief como o destrutor eh virtual, cada classe filha vai ser "destruida" da forma apropriada da classe.
	*/
	virtual ~Produto();
protected:
	std::string m_cod_barras;
	std::string m_descricao;
	double m_preco;		
public:
	/**
	* @brief Getters
	*/

	std::string getCodBarras();
	std::string getDescricao();
	double getPreco();
	
	/**
	* @brief Setters
	*/

	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	
	/**
	* @brief Como a sobrecarga de operador está na classe "pai" e eh um metodo publico, todos os filhos vao poder tambem usar este metodo.
	*/
	friend std::ostream& operator<< (std::ostream &o, Produto const &t);  

	/**
	* @brief sobrecarga de operador de igualdade para retornar se um produto tem o mesmo codigo de barra que o outro.
	*/
	friend bool operator==(Produto const &produto1, Produto const &produto2);
private:
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
