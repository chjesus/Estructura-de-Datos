#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>

#include "Genero.h"
#include "Artista.h"
#include "Album.h"
#include "Cancion.h"

template <class T>
class Archivo{
	fstream ficheroTexto;
	string cadena;
	string auxCadena;
	char nombre[40];
	
	public:
		Archivo(){}
		Archivo(char *nom){strcpy(nombre,nom);}
	
		void abrirFichero();
		void cerrarFichero();
		void separarCadena(vector<T> &lista);
};

template <class T>
void Archivo<T>::abrirFichero(){
	ficheroTexto.open(nombre,ios::in | ios::binary);
}

template <class T>
void Archivo<T>::cerrarFichero(){
	ficheroTexto.close();
}

template <class T>
void Archivo<T>::separarCadena(vector<T> &lista){
	if(ficheroTexto.fail()){
		cout<<"Error al Abrir el Archivo"<<endl;
	}else{
		while(getline(ficheroTexto,cadena)){
			auxCadena = strtok(&cadena[0]," ");
			string genero = auxCadena;
			
			auxCadena = strtok(NULL," ");
			string album = auxCadena;
			
			auxCadena = strtok(NULL," ");
			string artista = auxCadena;
			
			auxCadena = strtok(NULL," ");
			string cancion = auxCadena;
			
			auxCadena = strtok(NULL,"\n");
			string tam = auxCadena;
			
			T u(genero,album,artista,cancion,tam);
			lista.push_back(u);
		}
	}
}
#endif
