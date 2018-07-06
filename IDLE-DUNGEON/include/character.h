/**
 * @file  character.h
 * @brief Definicao de prototipos da classe base do personagem.
 */
#ifndef __CHARACTER__
#define __CHARACTER__

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/equips.h"

/** 
* @class   Character character.h
* @brief   Classe que representa um personagem.
* @details Usada como para para uma das três classes derivadas em que o jogador poderá escolher.
*/
class Character {
  public:
  
  //Constructors and Destructor
  Character(std::string,int,int,int,int,int,int,int,int);
  Character();
  virtual ~Character();
  
  //Getters
  virtual int const& getLabel() const;
  std::string const& getName() const;
  int const& getHp() const;
  int const& getStr() const;
  int const& getDex() const;
  int const& getWis() const;
  int const& getExp() const;
  int const& getLvl() const;
  int const& getNext_lvl() const;
  int const& getMoney() const;
  
  //Setters
  void setHp(int);
  void setStr(int);
  void setDex(int);
  void setWis(int);
  void setExp(int);
  void setLvl(int);
  void setNext_lvl(int);
  void setMoney(int);

  //Functions
  void showStatus();
  void battle();
  virtual std::ostream& print(std::ostream&);
  friend std::ostream& operator << (std::ostream &o, Character player);
  virtual void lvl_up();
  virtual int attack();
  virtual void equip(Equip);
  virtual void equip();
  virtual int equipPrice();
  
  private:
    std::string name;
    int hp,
        str,
        dex,
        wis,
        agi,
        exp,
        lvl,
        next_lvl,
        money;
};

#endif /* CHARACTER */