#include "geometria.h"

Geometria::Geometria(){

}

Geometria::~Geometria(){


}

void Geometria::showInstrucoes(){
	cout<<"Bem vindo ao app de geometria!"<<endl;
	cout<<"Os valores a ser inseridos são na linha de comando ao rodar o executável."<<endl;
	cout<<"Para saber a área e perimetro de uma figura plana basta digitar o nome da figura e os valores respectivos."<<endl;
	cout<<"Para quadrado, se dá apenas o valor do lado."<<endl;
	cout<<"Para o circulo, se dá o raio do circulo."<<endl;
	cout<<"Para o retangulo, se dá o valor da base e do lado."<<endl;
	cout<<"Para o triangulo, se dá o valor do lado do triangulo."<<endl;
	cout<<"Para saber a área e o volume de uma figura espacial basta digitar o nome da figura e os valores respectivos."<<endl;
	cout<<"Para o cubo, se dá o valor do lado do cubo."<<endl;
	cout<<"Para a piramide, se dá o valor dá o valor do lado da base e algo mais."<<endl;
	cout<<"Para a o paralelepipedo, se dá o valor dos dois lados da base e da altura."<<endl;
	cout<<"Para a esfera, se dá o valor do raio."<<endl;
}

void Geometria::getAreaQuadrado(float argumentos[]){
	cout<< "Área do quadrado: "<< 2*argumentos[0]<<endl; 
}

void Geometria::getPerimetroQuadrado(float argumentos[]){
	cout<< "Perimetro do quadrado: "<< 4 * argumentos[0]<<endl;
}

void Geometria::getAreaCirculo(float argumentos[]){
	cout<< "Área do circulo: "<< 3.1415 * pow(argumentos[0],2.0)<<endl; 
}

void Geometria::getPerimetroCirculo(float argumentos[]){
	cout<< "Perimetro do circulo: "<< 2*3.1415*argumentos[0]<<endl;
}

void Geometria::getAreaRetangulo(float argumentos[]){
	cout<< "Área do retângulo: "<< argumentos[0]*argumentos[1]<<endl;
}

void Geometria::getPerimetroRetangulo(float argumentos[]){
	cout<<"Perimetro do retângulo: "<< 2 * (argumentos[0]+argumentos[1])<<endl;
}

void Geometria::getAreaTriangulo(float argumentos[]){
	cout<< "Área do triangulo: "<< argumentos[0]*pow((argumentos[0]/2.0),1.0/3.0)<<endl;
}

void Geometria::getPerimetroTriangulo(float argumentos[]){
	cout<< "Perimetro do triangulo: "<< 3*argumentos[0]<<endl;
}

void Geometria::getAreaPiramide(float argumentos[]){
	cout<< "Área da piramide: "<< (2.0*argumentos[0])*(4.0*(argumentos[1]*pow((argumentos[1]/2.0),1.0/3.0)))<<endl;
}

void Geometria::getVolumePiramide(float argumentos[]){
	cout<< "Volume da piramide: "<< (1.0/3.0)*(argumentos[0]*2)*pow((argumentos[0]/2.0),1.0/3.0)<<endl;
}

void Geometria::getAreaCubo(float argumentos[]){
	cout<< "Área do cubo: "<< 6* pow(argumentos[0],2.0)<<endl;
}

void Geometria::getVolumeCubo(float argumentos[]){
	cout<< "Volume do cubo: "<< pow(argumentos[0],3.0)<<endl;
}

void Geometria::getAreaParalelepipedo(float argumentos[]){
	cout<< "Área do paralelepipedo: "<< (2*argumentos[0]*argumentos[1])+(2*argumentos[0]*argumentos[2])+(2*argumentos[1]*argumentos[2])<<endl;
}

void Geometria::getVolumeParalelepipedo(float argumentos[]){
	cout<< "Volume do paralelepipedo: "<< 	argumentos[0]*argumentos[1]*argumentos[2]<<endl;
}

void Geometria::getAreaEsfera(float argumentos[]){
	cout<< "Área da esfera: "<< 4*3.1415*pow(argumentos[0],2.0)<<endl;
}

void Geometria::getVolumeEsfera(float argumentos[]){
	cout<< "Volume da esfera: "<< 4*3.1415*pow(argumentos[0],3.0) <<endl;
}

void Geometria::getFigura(string nome, float argumentos[]){
	if(nome == "quadrado"){
		getAreaQuadrado(argumentos);
		getPerimetroQuadrado(argumentos);
	}
	else if(nome == "circulo"){
		getAreaCirculo(argumentos);
		getPerimetroCirculo(argumentos);
	}
	else if(nome == "retangulo"){
		getAreaRetangulo(argumentos);
		getPerimetroRetangulo(argumentos);
	}
	else if(nome == "triangulo"){
		getAreaTriangulo(argumentos);
		getPerimetroTriangulo(argumentos);
	}
	else if(nome == "piramide"){
		getAreaPiramide(argumentos);
		getVolumePiramide(argumentos);
	}
	else if(nome == "cubo"){
		getAreaCubo(argumentos);
		getVolumeCubo(argumentos);
	}
	else if(nome == "paralelepipedo"){
		getAreaParalelepipedo(argumentos);
		getVolumeParalelepipedo(argumentos);
	}
	else if(nome == "esfera"){
		getAreaEsfera(argumentos);
		getVolumeEsfera(argumentos);
	}
}