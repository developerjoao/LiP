/**
* @file empresa.h
* @brief Declaração dos metodos do funcionario da questão 1
* @author Joao Victor Fernandes Cabral
*/
#ifndef FUNCIONARIO
#define FUNCIONARIO

#include <string>
using namespace std;

struct data
{
	int dia;
	int mes;
	int ano;	
};

class Funcionario
{
private:
	string nome;
	float salario;
	data dataAdmissao;
public:
	Funcionario();
	~Funcionario();
	
	static int totalFuncionarios;
	string getNome();
	void setNome(string);
	float getSalario();
	void setSalario(float);
	void setData(int,int, int);
	data getData();
	void imprimeData();
	int getTotalFuncionarios();
	int tempoServico(int,int,int);
	friend bool operator==(Funcionario &,Funcionario &);
	friend istream &operator>>(istream&, Funcionario&);
	friend ostream &operator<<(ostream& o, Funcionario const funcionario);
};

#endif
