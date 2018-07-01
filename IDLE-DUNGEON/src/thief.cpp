/**
* @file  thief.cpp
* @brief Implementação dos prototipos da classe ladino.
*/

#include "../include/thief.h"   

    //constructors and destructors.
/**
* @details   Construtor parametrizado.
* @param name Nome do ladino.
* @param hp Vida do ladino.
* @param str Força do ladino.
* @param dex Destreza do ladino.
* @param wis Sabedoria do ladino.
* @param exp Experiência do ladino.
* @param lvl Nível do ladino.
* @param next_lvl O que falta para o próximo nível do ladino.
* @param money Dinheiro do ladino.
*/
    Thief::Thief(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, Equip equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }
/**
* @details   Destrutor padrão.
*/
    Thief::~Thief() = default;
     //Getters
/**
* @details Método de acesso ao atributo identificador da classe do guerreiro.
*/
     int const& Thief::getLabel() const{
        return this->label;
     }

    //Functions
/**
* @details Método de crescimento de nível.
*/
  void Thief::lvl_up(){
    this->setExp(this->getExp()-this->getNext_lvl());
    this->setLvl(this->getLvl()+1);
    this->setNext_lvl(2*this->getNext_lvl());   
    this->setDex(this->getDex()+this->getLvl()*1);
    this->setHp(this->getHp()+this->getLvl()*2);
  }
/**
* @details Método de ataque.
*/
  int Thief::attack(){
  srand(time(NULL));
      if (rand()%100>=70){
        std::cout << "CRITICAL HIT!!!" << std::endl;
        return (this->getDex())*2.5;
      }
      else{
        return this->getDex();
      }
    }
/**
* @details Método de equipar parametrizado.
*/
  void Thief::equip(Equip equip_){
    if(equip_.getType().compare("adaga") == 0){
      this->equiped = equip_;
      if(this->equiped.getName() == "Vazio"){
        system("clear");
        return;
      }else if(this->equiped.getName()!= "Vazio" and this->equipPrice()<this->getMoney()){
        system("clear");
        this->setDex(this->getDex()+equiped.getAtk());
        std::cout << this->equiped.getName() << " foi equipado(a)!" << std::endl;
        this->setMoney(this->getMoney() - this->equipPrice());
      }
      else{
        system("clear");
        std::cout << "Nao tem dinheiro? Devolva a minha arma e saia da minha loja!" << std::endl;
      }
    }
    else {
      std::cout << "Nao e possivel equipar!" << std::endl; 
    }
  }
/**
* @details Método de equipar vazio.
*/
  void Thief::equip(){
    Equip vazio;
    this->equiped = vazio;
  }
/**
* @details Método que dá o preço do equipamento.
*/
  int Thief::equipPrice(){
    return this->equiped.getPreco();
  }