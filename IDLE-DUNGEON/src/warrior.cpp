/**
* @file  warrior.cpp
* @brief Implementação dos prototipos da classe guerreiro.
*/

#include "../include/warrior.h"

    //constructors and destructors.
/**
* @details   Construtor parametrizado.
* @param name Nome do guerreiro.
* @param hp Vida do guerreiro.
* @param str Força do guerreiro.
* @param dex Destreza do guerreiro.
* @param wis Sabedoria do guerreiro.
* @param exp Experiência do guerreiro.
* @param lvl Nível do guerreiro.
* @param next_lvl O que falta para o próximo nível do guerreiro.
* @param money Dinheiro do guerreiro.
*/
    Warrior::Warrior(std::string nome,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money, Equip equiped,std::list<Equip> inventory)
      :Character(nome, hp, str, dex, wis, exp, lvl, next_lvl, money){
      this->equiped = equiped;
      this->inventory = inventory;
    }
/**
* @details   Construtor padrão.
*/
    Warrior::Warrior() = default;
/**
* @details   Destrutor padrão.
*/
    Warrior::~Warrior() = default;

    //Getters
/**
* @details Método de acesso ao atributo identificador da classe do guerreiro.
*/
    int const& Warrior::getLabel() const{
      return this->label;
    }

    //Functions
/**
* @details Método de crescimento de nível.
*/
    void Warrior::lvl_up(){
      this->setExp(this->getExp()-this->getNext_lvl());
      this->setLvl(this->getLvl()+1);
      this->setNext_lvl(2*this->getNext_lvl());
      this->setStr(this->getStr()+this->getLvl()*1);
      this->setHp(this->getHp()+this->getLvl()*5);
    }
/**
* @details Método de ataque.
*/
    int Warrior::attack(){
      if (rand()%100>=95){
        std::cout << "CRITICAL HIT!!!" << std::endl;
        return (getStr())*1.5;
      }else{
        return getStr();
      }
    }
/**
* @details Método de equipar parametrizado.
*/
    void Warrior::equip(Equip equip_){
      if(equip_.getType().compare("espada") == 0){
        this->equiped = equip_;
        if(this->equiped.getName() == "Vazio"){
          system("clear");
          return;
        }else if(this->equiped.getName()!= "Vazio" and this->equipPrice()<this->getMoney()){
          system("clear");
          this->setStr(this->getStr()+equiped.getAtk());
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
  void Warrior::equip(){
    Equip vazio;
    this->equiped = vazio;
  }

/**
* @details Método que dá o preço do equipamento.
*/
  int Warrior::equipPrice(){
    return this->equiped.getPreco();
  }

/**
* @details Método virtual para auxiliar a sobrecarga de operador
*/
  std::ostream& Warrior::print(std::ostream &o){
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