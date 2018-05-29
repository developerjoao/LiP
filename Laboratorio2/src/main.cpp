#include "geometria.h"

int main(int argc, char** argv){
	Geometria figura;
	if(argc == 1){
		figura.showInstrucoes();
		return 0;
	}
    int auxiliar;
    float *argumentos = new float[argc-2];
    for (int i = 2; i < argc; ++i) {
    	auxiliar = i-2;
        argumentos[auxiliar] = stof(argv[i]);
    }
    figura.getFigura(argv[1], argumentos);
    delete[] argumentos;
	return 0;
}