/**
* @file funcionario.cpp
* @brief implementação dos metodos das empresas da questão 1
* @author Joao Victor Fernandes Cabral
*/
#include "empresa.h"
#include <iostream>

using namespace std;

Empresa::Empresa(){
}
Empresa::~Empresa(){}

string Empresa::getNome(){
	return nome;
}

int Empresa::getCnpj(){
	return cnpj;
}

int Empresa::getFuncionariosEmpresa(){
	return funcionariosEmpresa;
}

void Empresa::setCnpj(int novoCnpj){
	cnpj = novoCnpj;
}

void Empresa::setNome(string novoNome){
	nome = novoNome;
}

void Empresa::addFuncionario(Funcionario novoFuncionario){
	for(int i=0;i<=funcionariosEmpresa;i++){
		if(i == MAX){
			cout<<"Maximo de vagas preenchidas";
			return;
		}
		else if(novoFuncionario==lista[i]){
			cout<<"ERRO: funcionário já cadastrado no sistema"<<endl;
			return;
		}
		else if(i==funcionariosEmpresa){
			lista[i] = novoFuncionario;
			funcionariosEmpresa++;
			cout<<"adicionado com sucesso"<<endl;
			return;
		}
	}
}

void Empresa::listaExperiencia(Empresa empresa){
	int dia, mes, ano;
	cout<<"Digite o dia de hoje:"<<endl;
	cout<<"Dia:";
	cin>>dia;
	cout<<"Mes:";
	cin>>mes;
	cout<<"Ano:";
	cin>>ano;
	cout<<"Listando os funcionários em período de experiência:"<<endl;
	for(int i= 0;i<empresa.funcionariosEmpresa;i++){
		if(empresa.lista[i].tempoServico(dia,mes,ano)<90){
			cout<<"Nome:"<<empresa.lista[i].getNome()<<endl;
			cout<<"salario:"<<empresa.lista[i].getSalario()<<endl;
			empresa.lista[i].imprimeData();
		}
	}
}

void Empresa::aumentoGeral(float percentual){
	if(percentual<0){
		cout<<"valor inválido"<<endl;
		return;
	}else{
		float incremento;
		float novoSalario;
		for(int i=0;i<=funcionariosEmpresa;i++){
			novoSalario  = lista[i].getSalario();
			incremento   = novoSalario;
			incremento  *= percentual;
			novoSalario += incremento;

			lista[i].setSalario(novoSalario);
		}
	}
}

istream &operator>>(istream &i, Empresa &empresa){
	cin.ignore();
	cout<<"Nome:";
	getline(i,empresa.nome);
	cout<<"CNPJ:";
	i >> empresa.cnpj;
	return i;
}

ostream &operator<<(ostream &o, Empresa empresa){
	for(int i= 0;i<empresa.funcionariosEmpresa;i++){
		cout<<"Nome:"<<empresa.lista[i].getNome()<<endl;
		cout<<"salario:"<<empresa.lista[i].getSalario()<<endl;
		empresa.lista[i].imprimeData();
	}
	return o;
}


