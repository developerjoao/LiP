/**
* @file  func.cpp
* @brief Implementação dos prototipos das funções.
*/


#include "../include/func.h"

/**
* @details Função que exibe a logo do jogo. Muda de cor a cada invocação diferente.
*/
void display(){
	srand(time(NULL));
	int num = (rand() % 2) + 1;
	if(num == 1){
		cout <<"\033[91m";
	} else if(num ==2){
		cout <<"\033[92m";
	}
	cout <<"▄█ ██▄   █     ▄███▄       ██▄     ▄      ▄     ▄▀  ▄███▄   ████▄    ▄" << endl;
	cout <<"██ █  █  █     █▀   ▀      █  █     █      █  ▄▀    █▀   ▀  █   █     █ " << endl;
	cout <<"██ █   █ █     ██▄▄        █   █ █   █ ██   █ █ ▀▄  ██▄▄    █   █ ██   █" << endl; 
	cout <<"▐█ █  █  ███▄  █▄   ▄▀     █  █  █   █ █ █  █ █   █ █▄   ▄▀ ▀████ █ █  █" << endl; 
	cout <<" ▐ ███▀      ▀ ▀███▀       ███▀  █▄ ▄█ █  █ █  ███  ▀███▀         █  █ █" << endl; 
	cout <<"                                  ▀▀▀  █   ██                     █   ██\033[39m" << endl;
	cout <<endl;
}

/**
* @details Função para carregar um personagem salvo no banco de dados.
* @param savefile Fluxo de entrada.
* @return vector<string> Armazena tudo em um vector de string.
*/
vector<string> Load(ifstream& savefile){
    vector<string> personagem;
    string atributo;
    if(savefile){
      while(getline(savefile, atributo, ';')){
        if(!savefile.eof()){
            personagem.push_back(atributo);
          }
        }
    }
    personagem.push_back(atributo);
    return personagem;
}

/**
* @details Função do menu principal que dá acesso a todos as outras opções do jogo.
*/
void intro(){
	string username, aux, option;
	vector<string> personagem;
	int num;
	bool laco = true;
	Character* player;
	
	display();
	cout << "Bem vindo! digite o seu apelido(Se nao existir alguem com este apelido, um novo personagem sera criado): ";
	
	cin >> username;
	
	aux = "data/Save/" + username + ".txt";

	ifstream savefile(aux, ifstream::in);
	
	if(savefile.is_open()){
		system("clear");
		personagem = Load(savefile);
		//Novo personagem
		Equip new_equip;
		list<Equip> new_list;
		if(stoi(personagem[0]) == 0){
			player = new Warrior(personagem[1],stoi(personagem[2]),stoi(personagem[3]),stoi(personagem[4]),stoi(personagem[5]),stoi(personagem[6]),stoi(personagem[7]),stoi(personagem[8]),stoi(personagem[9]), new_equip,new_list);
			laco = false;
		} else if(stoi(personagem[0]) == 1){
			player = new Warlock(personagem[1],stoi(personagem[2]),stoi(personagem[3]),stoi(personagem[4]),stoi(personagem[5]),stoi(personagem[6]),stoi(personagem[7]),stoi(personagem[8]),stoi(personagem[9]), new_equip,new_list);
			laco = false;
		} else {
			player = new Thief(personagem[1],stoi(personagem[2]),stoi(personagem[3]),stoi(personagem[4]),stoi(personagem[5]),stoi(personagem[6]),stoi(personagem[7]),stoi(personagem[8]),stoi(personagem[9]), new_equip,new_list);
			laco = false;
		}		
		savefile.close();
	}else{
		while(laco){
		cout << "Esse personagem não existe! deseja cria-lo? (y/n)" << endl;
		cin >> option;
			
			if(option.compare("y") == 0 or option.compare("Y") == 0){
				cout << "Escolha a sua classe:" << endl;
				cout << "[1] Guerreiro" << endl;
				cout << "[2] Mago" << endl;
				cout << "[3] Ladino" << endl;
				
				cin >> num;
				
				if(num > 3 or num < 1){
					cout << "\033[91mOpcao invalida!\033[39m" << endl;
					
				} else {
					//Novo personagem
					Equip new_equip;
					list<Equip> new_list;
					if(num == 1){
						player = new Warrior(username,150,30,8,10,0,1,100,0,new_equip,new_list);
						laco = false;
					} else if(num == 2){
						player = new Warlock(username,80,20,10,17,0,1,100,0,new_equip,new_list);
						laco = false;
					} else {
						player = new Thief(username,100,15,15,10,0,1,100,0,new_equip,new_list);
						laco = false;
					}
					system("clear");
				}
				
			} else if(option.compare("n") == 0 or option.compare("N") == 0){
				cout << "Fim de jogo!" << endl;
				player->setHp(-999999);
				laco = false;
				
			} else {
				system("clear");
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				
			}
		}
	}
	if(player->getHp() != -999999)
	game(player);
	
}

/**
* @details Função que salva o personagem no estado atual para o banco de dados.
* @param player Objeto do tipo Character que terá seus atributos desmembrados e salvos em um arquivo txt.
*/
void save_game(Character* player){
	
	string aux = "data/Save/" + player->getName() + ".txt", save;
	save = to_string(player->getLabel())+";" +player->getName()+ ";" +to_string(player->getHp())+ ";" +to_string(player->getStr())+ ";" +to_string(player->getDex())+ ";" +to_string(player->getWis())+ ";" +to_string(player->getExp())+ ";" +to_string(player->getLvl())+ ";" +to_string(player->getNext_lvl())+ ";" +to_string(player->getMoney())+ ";";
	ofstream outfile;
	outfile.open(aux);
	if(outfile.is_open()){
		outfile << save;
	}
	
	outfile.close();
}

/**
* @details Função de acesso à loja do jogo, levando em consideração a classe do jogador.
* @param label 
* @return Equip Retorna o equipamento que vai ou não ser equipado no jogador.
*/
Equip loja(int label){
	string aux2;
	bool loja = true;
	while(loja){
		if(label == 0){
			cout << "[1] Espada de bronze - 100G" << endl;
			cout << "[2] Espada de prata - 1000G" << endl;
			cout << "[3] Espada de ouro - 10000G" << endl;
			cout << "[4] Retornar a cidade." << endl;
			cin >> aux2;
			if(aux2.compare("1")== 0){
				return Equip("Espada de bronze", "espada", 1,100);
			} else if(aux2.compare("2") == 0){
				return Equip("Espada de prata", "espada", 15,1000);
			} else if(aux2.compare("3") == 0){
				return Equip("Espada de ouro", "espada", 200,10000);
			} else if(aux2.compare("4") == 0){
				return Equip("Vazio", "espada", 0, 0);
			} else{
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				cout << endl;
			}
		} else if(label == 1){
			cout << "[1] Cajado de bronze - 100G" << endl;
			cout << "[2] Cajado de prata - 1000G" << endl;
			cout << "[3] Cajado de ouro - 10000G" << endl;
			cout << "[4] Retornar a cidade." << endl;
			cin >> aux2;
			if(aux2.compare("1") == 0){
				return Equip("Cajado de bronze", "cajado", 1,100);
			} else if(aux2.compare("2") == 0){
				return Equip("Cajado de prata", "cajado", 15,1000);
			} else if(aux2.compare("3") == 0){
				return Equip("Cajado de ouro", "cajado", 200,10000);
			} else if(aux2.compare("4") == 0){
				return Equip("Vazio", "cajado", 0, 0);
			} else {
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				cout << endl;
			}
		} else if(label == 2){
			cout << "[1] Adaga de bronze - 100G" << endl;
			cout << "[2] Adaga de prata - 1000G" << endl;
			cout << "[3] Adaga de ouro - 10000G" << endl;
			cout << "[4] Retornar a cidade." << endl;
			cin >> aux2;
			if(aux2.compare("1") == 0){
				return Equip("Adaga de bronze", "adaga", 1,100);
			} else if(aux2.compare("2") == 0){
				return Equip("Adaga de prata", "adaga", 15,1000);
			} else if(aux2.compare("3") == 0){
				return Equip("Adaga de ouro", "adaga", 200,10000);
			} else if(aux2.compare("4") == 0){
				return Equip("Vazio", "adaga", 0, 0);
			} else {
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				cout << endl;
			}
		} else {
			system("clear");
			cout << "\033[91mOpcao invalida!\033[39m" << endl;
			cout << endl;
		}
	}
	return Equip();
}

/**
* @details Função de acesso ao menu de ações dentro do jogo.
* @param player 
* @return bool O retorno é um bool apenas para facilitar o laço.
*/
bool game(Character* player){
	int num;
	bool laco = true;
	
	while(laco){
		cout << "Bem vindo, "<<player->getName()<<", a cidade de Crystal Water! Lar da dungeon infinita!" << endl;
		cout << "[1] Enfrentar a dungeon." << endl;
		cout << "[2] Ver status." << endl;
		cout << "[3] Ir a loja." << endl;
		cout << "[4] Salvar o jogo." << endl;
		cout << "[5] Voltar ao menu inicial." << endl;
		cout << "[6] Sair do jogo." << endl;
		cout << "O que voce deseja fazer?" << endl;
		cin >> num;
		
		try{
			if( num > 6 or num < 1) throw IndiceInvalido();
			else{
				if(num == 1){
				system("clear");
				cout<<"Exp:"<<player->getExp()<<endl;
				player->battle();
			
				} else if(num == 2){
					system("clear");
					player->showStatus();
				
				} else if(num == 3){
					system("clear");
					player->equip(loja(player->getLabel()));
				} else if(num == 4){
					save_game(player);
					system("clear");
					cout << "O seu jogo foi salvo!" << endl;
					cout << endl;
				
				} else if(num == 5){
					system("clear");
					intro();
				
				} else if(num == 6){
					system("clear");
					cout << "Obrigado por visitar nossa cidade aventureiro!!!" << endl;
					delete player;
					return false;
				}
			}
		} catch (IndiceInvalido &ex){
			system("clear");
			cout << ex.what() << endl;
			return false;
		} catch (...){
			cout << "\033[91mOcorreu um erro inesperado!!!" << endl;
		}
	}
	return false;
}