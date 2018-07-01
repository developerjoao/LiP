/**
* @file  monster.cpp
* @brief Implementação dos prototipos dos monstros.
*/

#include "../include/monster.h"

//Constructors and Destructor
/**
* @details   Construtor padrão.
*/
Monster::Monster() = default;

/**
* @details   Construtor parametrizado.
* @param name Nome do monstro.
* @param hp Vida do monstro.
* @param atk Ataque do monstro.
* @param def Defesa do monstro.
* @param exp Experiência do monstro.
* @param loot Recompensa do monstro.
*/
Monster::Monster(std::string name, int hp, int atk, int def, int exp, int loot){
  this->name = name;
  this->hp = hp;
  this->atk = atk;
  this->def = def;
  this->exp = exp;
  this->loot = loot;
}

/**
* @details   Destrutor padrão.
*/
Monster::~Monster() = default;

//Getters
/**
* @details Método de acesso ao nome do monstro.
*/
  std::string const& Monster::getMonName() const{
  return this->name;
  }
/**
* @details Método de acesso à vida do monstro.
*/
  int const& Monster::getMonHp() const{
    return this->hp;
  }
/**
* @details Método de acesso ao ataque do monstro.
*/
  int const& Monster::getMonAtk() const{
    return this->atk;
  }
/**
* @details Método de acesso à defesa do monstro.
*/
  int const& Monster::getMonDef() const{
    return this->def;
  }
/**
* @details Método de acesso à experiência do monstro.
*/
  int const& Monster::getMonExp() const{
    return this->exp;
  }
/**
* @details Método de acesso à recompensa do monstro.
*/
  int const& Monster::getMonLoot() const{
    return this->loot;
  }
  
//Setters
/**
* @details Método de escrita do nome do monstro.
*/
  void Monster::setMonName(string name, Monster &current){
    current.name = name;
  }
/**
* @details Método de escrita da vida do monstro.
*/
  void Monster::setMonHp(int hp, Monster &current){
    current.hp = hp;
  }
/**
* @details Método de escrita do ataque do monstro.
*/
  void Monster::setMonAtk(int atk, Monster &current){
    current.atk = atk;
  }
/**
* @details Método de escrita da defesa do monstro.
*/
  void Monster::setMonDef(int def, Monster &current){
    current.def = def;
  }
/**
* @details Método de escrita da experiência do monstro.
*/
  void Monster::setMonExp(int exp, Monster &current){
    current.exp = exp;
  }
/**
* @details Método de escrita da recompensa do monstro.
*/
  void Monster::setMonLoot(int loot, Monster &current){
    current.loot = loot;
  }
/**
* @details Método de assimilar o nome do monstro.
*/
  void Monster::assignMonName(string infoType,int contador,Monster& current){
    if(contador == 0)
      this->setMonName(infoType, current);
    else{
      cout<<"Dado invalido";
    }
  }
/**
* @details Método de assimilar os atributos do monstro.
*/
  void Monster::assignMon(int infoType,int contador,Monster& current){
    if(contador == 1)
      this->setMonHp(infoType, current);
    if(contador == 2)
      this->setMonAtk(infoType, current);
    if(contador == 3)
      this->setMonDef(infoType, current);
    if(contador == 4)
      this->setMonExp(infoType, current);
    if(contador == 5)
      this->setMonLoot(infoType, current);
  }

/**
* @details Método de carregamento do banco de dados dos monstros.
* @param monsters Vector do tipo Monster para armazenar os monstros do banco da dados para a memória.
* @return vector<Monster>
*/
  vector<Monster> Monster::loadMonster(vector<Monster> &monsters){
    Monster currentMonster;
    string atributo;
    int contador=0, atributoInt;
    ifstream monsterFile("data/monster_database.txt");
    if(monsterFile){
      while(getline(monsterFile, atributo, ';')){
        if(!monsterFile.eof()){
          if(contador == 0)
            assignMonName(atributo, contador, currentMonster);
          atributoInt = atoi(atributo.c_str());
          assignMon(atributoInt, contador, currentMonster);

          if(contador==5){
            atributoInt = atoi(atributo.c_str());
            assignMon(atributoInt, contador, currentMonster);
            monsters.push_back(currentMonster);
            contador = 0;
          }
          else
            contador++;
        }
      }
    }
    monsterFile.close();
    return monsters;
  }

/**
* @details Método para deixar o surgimento de monstros aleatório.
*/
  void Monster::ranMonster(Monster &aleatorio){
    srand(time(NULL));
    Monster* carregador = new Monster();
    vector<Monster> allMonsters;
    allMonsters = carregador->loadMonster(allMonsters);
    aleatorio = allMonsters[rand()%allMonsters.size()];
  }