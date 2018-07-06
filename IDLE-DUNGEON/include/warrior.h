/**
* @file  warrior.h
* @brief Definicao de prototipos da classe guerreiro.
*/
#ifndef __WARRIOR__
#define __WARRIOR__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"

/** 
* @class   Warrior warrior.h
* @brief   Classe que representa um guerreiro.
*/
class Warrior : public Character{
  public:    
    //constructors and destructors.
    Warrior(std::string,int,int,int,int,int,int,int,int,Equip,std::list<Equip>);
    Warrior();
    ~Warrior();
    
    //Getters
   int const& getLabel() const override;

    //Functions
    void lvl_up();
    int attack();
    void equip(Equip);
    void equip();
    int equipPrice();
    std::ostream& print(std::ostream& o);
  
  private:
    Equip equiped;
    std::list<Equip> inventory;
    int const label = 0;
};

#endif /* WARRIOR */