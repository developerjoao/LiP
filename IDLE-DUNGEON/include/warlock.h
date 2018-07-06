/**
* @file  warlock.h
* @brief Definicao de prototipos da classe mago.
*/
#ifndef __WARLOCK__
#define __WARLOCK__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"
#include <cmath>

/** 
* @class   Warlock warlock.h
* @brief   Classe que representa um mago.
*/
class Warlock : public Character{
  public:

    //constructors and destructors.
    Warlock(std::string,int,int,int,int,int,int,int,int,Equip,std::list<Equip>);
    // Warlock();
    ~Warlock();
    
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
    int const label = 1;
};

#endif /* WARLOCK */
