#include <iostream>

#include "Grafo.h"
int main(int argc, char** argv) {
	char nombre[30]="datos.txt";
	Grafo grafo(nombre,true,true);
	grafo.Imprimir();
//	grafo.Warshall(4);
//	grafo.FloyD();
	return 0;
}
