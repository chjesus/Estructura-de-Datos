#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string.h>

#include "Pilas_dinamicas.h"
using namespace std;
class Archivo{
	Pilas_dinamicas<char> pila;
	string palabra;
	string aux;
	string auxPalindromo;
	fstream fichero;
	int cont;
	public:
		Archivo(){}
		void leerArchivo();
};

void Archivo::leerArchivo(){
	cont = 0;
	fichero.open("Archivo",ios::in);
	if(fichero.fail()){
		cout<<"Error al abrir el Archivo."<<endl;
	}else{
		while(getline(fichero,palabra)){
			auxPalindromo = "";
			aux = strtok(&palabra[0],"\n");
				for(int i=0;i<aux.length();i++){
					pila.Anadir(aux[i]);
				}
				while(!pila.isVacia()){
					auxPalindromo+=pila.Leer();
				}
				if(aux == auxPalindromo){
					cout<<aux<<" | Si es Palindromo!"<<endl;
				}else{
					cout<<aux<<" | No es Palindromo!"<<endl;
				}
				cont +=(auxPalindromo==aux)?1:0;
				pila.~Pilas_dinamicas();
		}
	}
	fichero.close();
	cout<<endl<<"Total de palabras palindromos: "<<cont;
}
#endif
