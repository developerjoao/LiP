/**
* @file  warlock.cpp
* @brief Implementação dos prototipos da classe mago.
*/

#include "../include/warlock.h"

    //constructors and destructors.
/**
* @details   Construtor parametrizado.
* @param name Nome do mago.
* @param hp Vida do mago.
* @param str Força do mago.
* @param dex Destreza do mago.
* @param wis Sabedoria do mago.
* @param exp Experiência do mago.
* @param lvl Nível do mago.
* @param next_lvl O que falta para o próximo nível do mago.
* @param money Dinheiro do mago.
*/
    Warlock::Warlock(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, Equip equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }
/**
* @details   Destrutor padrão.
*/
    Warlock::~Warlock() = default;
    
    //Getters
/**
* @details Método de acesso ao atributo identificador da classe do mago.
*/
    int const& Warlock::getLabel() const{
      return this->label;
    }

    //Functions
/**
* @details Método de crescimento de nível.
*/
    void Warlock::lvl_up(){
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setNext_lvl(2*this->getNext_lvl());
      this->setWis(this->getWis()+this->getLvl()*pow(1.1,this->getLvl()));
      this->setHp(this->getHp()+this->getLvl()*1);
    }
/**
* @details Método de ataque.
*/
    int Warlock::attack(){
      return (getWis()/2);
    }
/**
* @details Método de equipar parametrizado.
*/
  void Warlock::equip(Equip equip_){
    if(equip_.getType().compare("cajado") == 0){
      this->equiped = equip_;
      if(this->equiped.getName() == "Vazio"){
        system("clear");
        return;
      }else if(this->equiped.getName()!= "Vazio" and this->equipPrice()<this->getMoney()){
        system("clear");
        this->setWis(this->getWis()+equiped.getAtk());
        std::cout << this->equiped.getName() << " foi equipado(a)!" << std::endl;
        this->setMoney(this->getMoney() - this->equipPrice());
      }else{
        system("clear");
        std::cout << "Nao tem dinheiro? Devolva a minha arma e saia da minha loja!" << std::endl;
      }
    } else {
      std::cout << "Nao e possivel equipar!" << std::endl;
    }
  }
/**
* @details Método de equipar vazio.
*/
  void Warlock::equip(){
    Equip vazio;
    this->equiped = vazio;
  }

/**
* @details Método que dá o preço do equipamento.
*/
  int Warlock::equipPrice(){
    return this->equiped.getPreco();
  }

/**
* @details Método virtual para auxiliar a sobrecarga de operador
*/
  std::ostream& Warlock::print(std::ostream &o){
    int opcao;
    o<<"Nome: "<<this->getName()<<std::endl
    <<"Lvl: "<<this->getLvl()<<std::endl
    <<"Hp: "<<this->getHp()<<std::endl
    <<"Strengh: "<<this->getStr()<<std::endl
    <<"Dexterity: "<<this->getDex()<<std::endl
    <<"Wisdom: "<<this->getWis()<<std::endl
    <<"Exp: "<<this->getExp()<<std::endl
    <<"Money: "<<this->getMoney()<<std::endl
    <<"Para voltar a cidade entre qualquer tecla:";
    std::cin>>opcao;
    system("clear");
    return o;
  }