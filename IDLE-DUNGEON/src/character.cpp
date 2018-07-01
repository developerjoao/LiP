/**
* @file  character.cpp
* @brief Implementação dos prototipos da classe base do personagem.
*/

#include "../include/character.h"
#include "../include/func.h"

/**
* @details   Construtor parametrizado.
* @param name Nome do personagem.
* @param hp Vida do personagem.
* @param str Força do personagem.
* @param dex Destreza do personagem.
* @param wis Sabedoria do personagem.
* @param exp Experiência do personagem.
* @param lvl Nível do personagem.
* @param next_lvl O que falta para o próximo nível do personagem.
* @param money Dinheiro do personagem.
*/
    Character::Character(std::string name,int hp,int str,int dex,int wis,int exp, int lvl,int next_lvl,int money){
          this->name = name;
          this->hp = hp;
          this->str = str;
          this->dex = dex;
          this->wis = wis;
          this->exp = exp;
          this->lvl = lvl;
          this->next_lvl = next_lvl;
          this->money = money;
    }

/**
* @details   Construtor padrão.
*/
    Character::Character() = default;
/**
* @details   Destrutor padrão.
*/
    Character::~Character() = default;
  
//Getters
/**
* @details Método de acesso ao atributo identificador da classe do personagem.
*/
  int const& Character::getLabel() const{
    return this->getLabel();
  }
/**
* @details Método de acesso ao nome do personagem.
*/
  std::string const& Character::getName() const{
    return this->name;
  }
/**
* @details Método de acesso à vida do personagem.
*/
  int const& Character::getHp() const{
    return this->hp;
  }
/**
* @details Método de acesso à força do personagem.
*/
  int const& Character::getStr() const{
    return this->str;
  }
/**
* @details Método de acesso à destreza do personagem.
*/
  int const& Character::getDex() const{
    return this->dex;
  }
/**
* @details Método de acesso à sabedoria do personagem.
*/
  int const& Character::getWis() const{
    return this->wis;
  }
/**
* @details Método de acesso à experiência do personagem.
*/
  int const& Character::getExp() const{
    return this->exp;  
  }
/**
* @details Método de acesso ao nível do personagem.
*/
  int const& Character::getLvl() const{
    return this->lvl;
  }

  int const& Character::getNext_lvl() const{
    return this->next_lvl;    
  }
/**
* @details Método de acesso ao dinheiro do personagem.
*/
  int const& Character::getMoney() const{
    return this->money;    
  }
  
  //Setters
/**
* @details Método de escrita da vida do personagem.
*/
  void Character::setHp(int hp){
    this->hp = hp;
  }
/**
* @details Método de escrita da força do personagem.
*/
  void Character::setStr(int str){
    this->str = str;
  }
/**
* @details Método de escrita da destreza do personagem.
*/
  void Character::setDex(int dex){
    this->dex = dex;
  }
/**
* @details Método de escrita da sabedoria do personagem.
*/
  void Character::setWis(int wis){
    this->wis = wis;
  }
/**
* @details Método de escrita da experiência do personagem.
*/
  void Character::setExp(int exp){
    this->exp = exp;
  }
/**
* @details Método de escrita do nível do personagem.
*/
  void Character::setLvl(int lvl){
    this->lvl = lvl;
  }
/**
* @details Método de escrita do próxima nível do personagem.
*/
  void Character::setNext_lvl(int next_lvl){
    this->next_lvl = next_lvl;
  }
/**
* @details Método de escrita do dinheiro do personagem.
*/
  void Character::setMoney(int money){
    this->money = money;
  }

  //Functions
/**
* @details Método usado para informar ao jogador o status atual do personagem. Imprime em tela todos os atributos.
*/
  void Character::showStatus(){
    string opcao;
    cout<<"Nome: "<<this->getName()<<endl;
    cout<<"Lvl: "<<this->getLvl()<<endl;
    cout<<"Hp: "<<this->getHp()<<endl;
    cout<<"Strengh: "<<this->getStr()<<endl;
    cout<<"Dexterity: "<<this->getDex()<<endl;
    cout<<"Wisdom: "<<this->getWis()<<endl;
    cout<<"Exp: "<<this->getExp()<<endl;
    cout<<"Money: "<<this->getMoney()<<endl;
    cout<<"Para voltar a cidade entre qualquer tecla:";
    cin>>opcao;
    system("clear");
  }
/**
* @details Método virtual de crescimento de nível.
*/
  void Character::lvl_up(){
  }
/**
* @details Método virtual de ataque.
*/
  int Character::attack(){
    return this->attack();
  }
/**
* @details Método virtual para equipar parametrizado.
*/
  void Character::equip(Equip){

  }
/**
* @details Método virtual para equipar vazio.
*/
  void Character::equip(){

  }
/**
* @details Método virtual para pegar o preço do equipamento a equipar.
*/
  int Character::equipPrice(){
    return this->equipPrice();
  }
/**
* @details Método batalha.
*/
  void Character::battle() {
  srand(time(NULL));
  string opcao;
  Monster monstroAndar;
  monstroAndar.ranMonster(monstroAndar); 
  int HpJogador = getHp();
  int HpOponente = monstroAndar.getMonHp();
  cout<<"Voce encontrou um "<<monstroAndar.getMonName()<<"!"<<endl;
  cout<<endl;
  while(1){
    bool proximo = false;
    srand(time(NULL));
    usleep(1000*1000);
    cout<<"HP jogador:"<<HpJogador<<endl;
    cout<<"HP " <<monstroAndar.getMonName()<<":"<<HpOponente<<endl;
    cout<<endl;
    if((rand() % 20 + 1) + getDex() >= monstroAndar.getMonDef()){ 
      int dano = attack();
      cout << "Voce acertou o "<<monstroAndar.getMonName()<<", causando " << dano << " pontos de dano!"<<endl;
      HpOponente -= dano;
      }else{
      cout << "Voce errou seu ataque."<<endl;
    }
    if(HpOponente <= 0){
      setExp(getExp()+monstroAndar.getMonExp());
      cout << "Voce venceu o combate!"<<endl;
      cout << "Exp atual:"<<this->getExp()<<endl;
      setMoney(getMoney()+monstroAndar.getMonLoot());
      cout<<endl;
      if(this->getExp()>=this->getNext_lvl()){
        this->lvl_up();
        cout<<"Parabéns, você subiu para o nivel "<<this->getLvl()<<"!"<<endl;
        cout<<"Deseja voltar a cidade?(s/n)";
        cin>>opcao;
        if(opcao == "s" or opcao == "S"){
          system("clear");
          return;
        }
      }
      monstroAndar.ranMonster(monstroAndar); 
      cout << "Você encontrou um "<<monstroAndar.getMonName()<<"!"<<endl;
      HpOponente = monstroAndar.getMonHp();
      cout<<endl;
      proximo = true;
    }
    usleep(1000*1000);
    if(!(HpOponente <= 0) and !proximo){
      cout << monstroAndar.getMonName() << " acertou um ataque em voce, causando " << monstroAndar.getMonAtk() << " de dano."<<endl;
      cout<<endl;
      HpJogador -= monstroAndar.getMonAtk();
    }
    if(HpJogador <= 0){
      system("clear");
      cout << "Voce foi derrotado!"<<endl;
      return;
    }
  }
}