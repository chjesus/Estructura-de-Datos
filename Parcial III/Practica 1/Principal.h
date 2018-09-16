#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <fstream>

#include "ArbolAVL.h"
#include "Palabra.h"
using namespace std;
class Principal{
	fstream archivoTexto;
	ArbolAVL<Palabra> arbol;
	string cadena;
	char *auxCadena;
	public:
	Principal(){}
	void Main();
};

void Principal::Main(){
	archivoTexto.open("text",ios::in);
	if(archivoTexto.fail()){
		cout<<"Error al Abrir el Archivo.";
	}else{
		while(getline(archivoTexto,cadena)){
			auxCadena = strtok(&cadena[0],"\n");
			char auxPalabra[40];
			strcpy(auxPalabra,auxCadena);
			Palabra u(auxPalabra,0);
			arbol.Anadir(u);
		}
	}
	archivoTexto.close();
	
	arbol.InOrden();
}
#endif
