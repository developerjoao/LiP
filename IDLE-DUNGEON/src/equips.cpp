/**
* @file  equips.cpp
* @brief Implementação dos prototipos da classe dos equipamentos.
*/


#include "../include/equips.h"

//Constructors and Destructor
/**
* @details Construtor padrão.
*/
Equip::Equip() = default;
/**
* @details    Construtor parametrizado.
* @param name Nome do equipameto.
* @param atk  Modificador de ataque.
* @param def  Modificador de defesa.
*/
Equip::Equip(std::string name,std::string type,int atk, int preco){
  this->name = name;
  this->type = type;
  this->atk = atk;
  this->preco = preco;
}
/**
* @details   Destrutor padrão.
*/
Equip::~Equip() = default;
  
//Getters
/**
* @details Método de leitura do nome do equipamento.
*/
std::string const& Equip::getName() const{
  return this->name;
}
/**
* @details Método de leitura do tipo do equipamento.
*/
std::string const& Equip::getType() const{
  return this->type;
}
/**
* @details Método de leitura do valor de ataque do equipamento.
*/
int const& Equip::getAtk() const{
  return this->atk;
}
/**
* @details Método de leitura do preço do equipamento.
*/
int const& Equip::getPreco() const{
  return this->preco;
}

//Setters
/**
* @details Método de escrita do nome do equipamento.
*/
void Equip::setName(std::string name){
  this->name = name;
}
/**
* @details Método de escrita do valor de ataque do equipamento.
*/
void Equip::setAtk(int atk){
  this->atk = atk;
}