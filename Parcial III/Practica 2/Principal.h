#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "Grafo.h"
using namespace std;
class Principal{
//	char nombre[30]="datos.txt";
	char nombre[30]="laberinto.txt";
	public:
		void main();
};

void Principal::main(){
	Grafo grafo(nombre,false,true);
	grafo.Imprimir();
//	grafo.Warshall(4);
	grafo.FloyD();
	grafo.imprimirRuta();
}
#endif
