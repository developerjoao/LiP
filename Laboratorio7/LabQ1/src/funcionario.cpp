/**
* @file funcionario.cpp
* @brief implementação dos metodos do funcionario da questão 1
* @author Joao Victor Fernandes Cabral
*/

#include "funcionario.h"
#include <iostream>

using namespace std;

Funcionario::Funcionario(){
}

Funcionario::~Funcionario(){
	
}

string Funcionario::getNome()
{
	return nome;
}

float Funcionario::getSalario()
{
	return salario;
}

data Funcionario::getData(){
	return dataAdmissao;
}

void Funcionario::imprimeData(){
	cout<<"Data:"<< dataAdmissao.dia<<endl;
	cout<<"Mes:"<< dataAdmissao.mes<<endl;
	cout<<"Ano:"<< dataAdmissao.ano<<endl;
}

void Funcionario::setNome(string novoNome){
	nome = novoNome;
}

void Funcionario::setSalario(float novoSalario){
	salario = novoSalario;
}

void Funcionario::setData(int novoDia,int novoMes, int novoAno){
	dataAdmissao.dia = novoDia;
	dataAdmissao.mes = novoMes;
	dataAdmissao.ano = novoAno;
}

int Funcionario::tempoServico(int diaAtual,int mesAtual, int anoAtual){
	int diasTotal        = diaAtual*1         + mesAtual*30         + anoAtual*365;
	int diasFuncionario  = dataAdmissao.dia*1 + dataAdmissao.mes*30 + dataAdmissao.ano*365;
	return diasTotal - diasFuncionario;
}

bool operator== (Funcionario &A,Funcionario &B)
{
    return A.nome == B.nome;
}

istream &operator>>(istream &i, Funcionario &funcionario){
	cin.ignore();
	cout<<"Nome:";
	getline(i,funcionario.nome);
	cout<<"Salario:";
	i >> funcionario.salario;
	cout<<"Data de admissao:"<<endl;
	cout<<"Dia:";
	i >> funcionario.dataAdmissao.dia;
	cout<<"Mes:";
	i >> funcionario.dataAdmissao.mes;
	cout<<"Ano:";
	i >> funcionario.dataAdmissao.ano;
	return i;
}

ostream &operator<<(ostream &o, Funcionario const funcionario){
	cout<<"Nome:"<<funcionario.nome<<endl;
	cout<<"salario:"<<funcionario.salario<<endl;
	cout<<"Data de admissao:"<<endl;
	cout<<"Dia:"<< funcionario.dataAdmissao.dia<<endl;
	cout<<"Mes:"<< funcionario.dataAdmissao.mes<<endl;
	cout<<"Ano:"<< funcionario.dataAdmissao.ano<<endl;
	return o;
}