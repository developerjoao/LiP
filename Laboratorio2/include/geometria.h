
#ifndef GEOMETRIA
#define GEMOTERIA

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Geometria{
private:
	//char figura;
	//int qtargumentos;
	//float *argumentos;
public:
	Geometria();
	~Geometria();

	void showInstrucoes();
	void getAreaQuadrado(float[]);
	void getAreaCirculo(float[]);
	void getAreaRetangulo(float[]);
	void getAreaTriangulo(float[]);
	void getAreaPiramide(float[]);
	void getAreaCubo(float[]);
	void getAreaParalelepipedo(float[]);
	void getAreaEsfera(float[]);
	void getPerimetroQuadrado(float[]);
	void getPerimetroCirculo(float[]);
	void getPerimetroRetangulo(float[]);
	void getPerimetroTriangulo(float[]);
	void getVolumePiramide(float[]);
	void getVolumeCubo(float[]);
	void getVolumeParalelepipedo(float[]);
	void getVolumeEsfera(float[]);
	void getFigura(string, float[]);
	//friend ostream &operator <<(&ostream o, string figura);
};

#endif