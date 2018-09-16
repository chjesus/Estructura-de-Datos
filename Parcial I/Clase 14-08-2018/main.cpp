#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

#include "Archivo.h"

/**
	Escriba un programa para leer un archivo de texto los datos de archivo mp3 descargados desde iTunes:
	genero,album,artista,cancion y tamaño, separados por espacio en blanco. Cargas los datos en un vector y ordenar de acuerdo a:
		*primera clave: genero
		*segunda clave: artista
		*tercera clave: album
		*cuarta clave: cancion
	
	Nota: usar el metodo ShakerSort
*/
template <class T>
void ShakerSort(vector<T> &v,int n);

template <class T>
void inter(T &A, T &B);

template <class T>
void imprimir(vector<T> &v,string nombre);

using namespace std;
int main(int argc, char** argv) {
	vector<Genero> lista;
	vector<Artista> listaArt;
	vector<Album> listaAlb;
	vector<Cancion> listaCanc;
	
	imprimir(lista,"Genero");
	imprimir(listaArt,"Artista");
	imprimir(listaAlb,"Album");
	imprimir(listaCanc,"Cancion");
	
	return 0;
}

template <class T>
void ShakerSort(vector<T> &v,int n){
	int inicio = 0,final = n-1;
	int band;
	
	do{
		band=0;
		for(int i=inicio;i<final;i++){
			if(v[i]>v[i+1]){
				inter(v[i],v[i+1]);
				band=1;
			}
		}
		if(band==1){
			for(int i=final-1,band=0;i>inicio;i--){
				if(v[i]<v[i-1]){
					inter(v[i],v[i-1]);
					band=1;
				}
			}
		}
		inicio++;
		final--;
	}while(inicio<final && band==1);
}
template <class T>
void inter(T &A, T &B){
	T aux = A;
	A = B;
	B = aux;
}

template <class T>
void imprimir(vector<T> &v,string nombre){
	char nombreArchivo[40] = "mp3.txt";
	Archivo<T> *leer = new Archivo<T>(nombreArchivo);
	
	leer->abrirFichero();
	leer->separarCadena(v);
	leer->cerrarFichero();	
	
	ShakerSort(v,v.size());
	cout<<"Ordenado por "<<nombre<<"!"<<endl<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
}
