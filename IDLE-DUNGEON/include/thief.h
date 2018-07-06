/**
* @file  thief.h
* @brief Definicao de prototipos da classe ladino.
*/
#ifndef __THIEF__
#define __THIEF__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"
#include "../include/character.h"

/** 
* @class   Thief thief.h
* @brief   Classe que representa um ladino.
*/
class Thief : public Character{
  public:    
    //constructors and destructors.
    Thief(std::string,int,int,int,int,int,int,int,int,Equip,std::list<Equip>);
    // Warlock();
    ~Thief();
    
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
    int const label = 2;
};

#endif /* THIEF */