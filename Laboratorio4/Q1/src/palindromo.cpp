/**
* @file palindromo.cpp
* @brief Arquivo que implementa as funçoes do arquivo palindromo.h
*/

#include "palindromo.h"

void RemoverEspacosePontuacao(string& frase){
	for(unsigned int i = 0; i < frase.size();){
		/**
		* @brief pra cada caracter da frase vai checar se é um espaço ou pontuação
		*/
		if(isblank(frase[i]) or ispunct(frase[i]))
			frase.erase(i, 1); //Apaga o espaço em branco/pontuação na posição i
		else
			++i; //incrementa o i se não for nem espaço em branco nem pontuação
	}
}

void RemoverCaracteresEspeciais(string& frase){
	/**
	* @brief vetor contendo os caracteres especiais para serem trocados para caracter normal
	*/
	vector<string> caracter_especial = {
		"ä","á","â","à","ã",
		"é","ê","ë","è",
		"í","î","ï","ì",
		"ö","ó","ô","ò","õ",
		"ü","ú","û","ù",
		"ç"
	};

	/**
	* @brief vetor contendo os caracteres normais para serem trocados para manipulação do palindromo
	*/
	vector<string> caracter_normal = {
		"a","a","a","a","a",
		"e","e","e","e",
		"i","i","i","i",
		"o","o","o","o","o",
		"u","u","u","u",
		"c"
	};
	/**
	* @brief Função que irá transformar cada caracter em minusculo.
	*/
	std::locale loc;
	for (std::string::size_type i=0; i<frase.length(); ++i)
    	frase[i] = std::tolower(frase[i],loc);

    /**
	* @brief tento aqui trocar o caracter especial para normal, mas não consigo.
    */
	for(unsigned int i = 0; i < frase.size(); ++i ){
		for(unsigned int j = 0; j < caracter_normal.size(); ++j){
			if(frase[i]==caracter_especial[j][0]){
				frase[i] = caracter_normal[j][0];
			}
		}	
	}
}

bool ChecaPalindromo(string& frase){
	Pilha<char> pilha(frase.size());
	int meio;
	/**
	* @brief empilha a metade da string.
	*/
	if(frase.size()%2 == 0){
		meio = frase.size()/2;
	}
	else{
		meio = (frase.size()/2)+1;
	}
	for(int i =0; i < meio; ++ i){
		pilha.push(frase[i]);
	}

	/**
	* @brief Aqui checo se a continuação da string é igual ao topo da pilha criada e então dando pop na pilha.
	*/
	for( unsigned int i = frase.size() % 2 == 0 ? meio : meio - 1; i < frase.size(); ++i){
		if(frase[i] == pilha.top()){
			pilha.pop();	
		}
	}
	/**
	* @brief Se a pilha foi totalmente desempilhada, ela é um palindromo.
	*/
	return pilha.size() == 0;
}