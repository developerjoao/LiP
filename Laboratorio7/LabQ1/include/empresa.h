/**
* @file empresa.h
* @brief Declaração dos metodos das empresas da questão 1
* @author Joao Victor Fernandes Cabral
*/
#ifndef EMPRESA
#define EMPRESA

#define MAX 300

#include "funcionario.h"
#include <vector>

using namespace std;

class Empresa
{
private:
	string nome;
	int cnpj;
	Funcionario lista[MAX];
	int funcionariosEmpresa = 0;
public:
	Empresa();
	~Empresa();
	
	static int totalEmpresas;
	string getNome();
	void setNome(string);
	int getCnpj();
	void setCnpj(int);
	int getFuncionariosEmpresa();
	void addFuncionario(Funcionario);
	void aumentoGeral(float);
	int getTotalEpresas();
	int getEmpresaID();
	void listaExperiencia(Empresa);
	friend istream &operator>>(istream&, Empresa&);
	friend ostream &operator<<(ostream& o, Empresa empresa);
};

#endif
