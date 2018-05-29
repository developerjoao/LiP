/**
* @file calculadora.cpp
* @brief Implementa��o das fun��es que foram declaradas no calculadora.h
*/

#include "calculadora.h"


/**
* @brief Extra�do de https://bit.ly/2GUDvGc
*/
bool Calculadora::ehNumero(std::string &str)
{
    /**
    * @brief procura por algo que n�o seja numero e retorna um bool
    */
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool Calculadora::ehOperador(std::string &str)
{
    /**
    * @brief procura por algo que n�o seja operador e verifica se o tamanho da substring � maior que 1 ("+=-*" n�o � operador)
    */
    return (str.find_first_not_of("+-/*=") == std::string::npos)&&(str.size()==1);
}


/**
* @brief fun��o de debug, repete o que o usu�rio digitou
*/
void Calculadora::mostraEntrada()
{

    while(!m_entrada.empty()){
        std::cout<<m_entrada.front();
        m_entrada.pop();
    }
}

void Calculadora::opera(std::string &str)
{
    int operando1;
    int operando2;
    /**
    * @brief operadores binarios checam se existe pelo menos 2 elementos para operar (= s� precisa de 1, por isso a exce��o)
    */
    if(str!="="){
        if(m_valores.empty()){
            std::cout<<"Erro de sintaxe"<<std::endl;
        }
        operando1 = m_valores.top();
        m_valores.pop();
        if(m_valores.empty()){
            std::cout<<"Erro de sintaxe"<<std::endl;
        }
        operando2 = m_valores.top();
        m_valores.pop();
    }
    /**
    * @brief Teste e execu��o para cada opera��o
    */
    if(str=="+"){
        m_valores.push(operando1 + operando2);
        return;
    }
    if(str=="-"){
        m_valores.push(operando1 - operando2);
        return;
    }
    if(str=="/"){
        m_valores.push(operando1 / operando2);
        return;
    }
    if(str=="*"){
        m_valores.push(operando1 * operando2);
        return;
    }
    /**
    * @brief se houver mais do que 1 numero na pilha no '=' houve erro de sintaxe
    */
    if(str=="="){
        if(m_valores.size()==1)return;
        std::cout<<"Erro de sintaxe"<<std::endl;
        return;
    }
}




void Calculadora::calcula()
{
    /**
    * @brief convers�o de string para int fonte: http://www.cplusplus.com/reference/string/stoi/
    */
    std::string::size_type sz;   
    int aux;

    /**
    * @brief se for n�mero vai para a pilha
    */
    while(!m_entrada.empty()){
        if(ehNumero(m_entrada.front( ))){
            aux = std::stoi(m_entrada.front( ), &sz);
            m_valores.push(aux);
            m_entrada.pop();
        }else if(ehOperador(m_entrada.front( ))){
                opera(m_entrada.front( ));
                m_entrada.pop();
        }
        /**
        * @brief se n�o � nem numero nem operador retorna um erro
        */
        else{
            std::cout<<"Erro de sintaxe";
            return;
        }
    }
    /**
    * @brief mostra o resultado final da opera��o
    */
    std::cout<<m_valores.top()<<std::endl;
    return;
}


/**
* @brief l� uma entrada no formato "2 2 5 + * ="
*/
void recebeDados(Calculadora& calculadora) 
{
    std::string aux;
    /**
    * @brief s� para a leitura quando chega em um caractere =
    */
    do{
        std::cin>>calculadora;   
    }while (calculadora.m_entrada.back()!="=");
}

/**
* @brief sobrecarga do operador para pegar linhas inteiras
*/
std::istream& operator>> (std::istream& in, Calculadora& calculadora)
{
    std::string textoUsuario;
    in>>textoUsuario;
    calculadora.m_entrada.push(textoUsuario);
    return in;
}
