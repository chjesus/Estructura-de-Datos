#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string.h>
#include <vector>

#include "Alumnos.h"
using namespace std;

template <class T>
class Archivo{
	fstream fic;
	T leer;
	public:
		Archivo(){}
		void llenarVector(char *nom,vector<T> &listaAlum);
		void imprimirArchivo(char *nom);
		bool busquedaSecuencial(T &buscar);
		bool busquedaBinaria(T &buscar,int N);
		bool busquedaSecuencialTel(T &buscar);
};

template <class T>
void Archivo<T>::llenarVector(char *nom,vector<T> &listaAlum){
	Alumnos *leer = new Alumnos();
//	Alumnos v[] = {	Alumnos(542547782,"Ana",42462356,8.0,"Informatica"),
//					Alumnos(123671126,"Carlos",41465267,5.8,"Industrial"),
//					Alumnos(512356247,"Pedro",4562662,5.1,"Civil"),
//					Alumnos(632721457,"Juan",462626734,6.1,"Civil"),
//					Alumnos(978036874,"Maria",47216862,6.5,"Mecanica"),
//					Alumnos(953523787,"Luisa",48478632,4.5,"Electronica"),
//					Alumnos(856526676,"Alberto",47834362,5.6,"Informatica"),
//					Alumnos(985922945,"Luis",484526,7.0,"Ambiental"),
//					Alumnos(167783789,"Alexandra",7393783,4.4,"Civil"),
//					Alumnos(425662457,"Pablo",484428366,7.8,"Industrial"),
//					};
//	fic.open(nom,ios::binary | ios::out);
//	fic.write(reinterpret_cast<char*>(&v),sizeof(Alumnos)*10);
//	fic.close();

	fic.open(nom,ios::binary | ios::in);
	while(!fic.eof() && fic.read(reinterpret_cast<char*>(leer),sizeof(Alumnos))){
		listaAlum.push_back(*leer);
	}
	fic.close();
}

template <class T>
void Archivo<T>::imprimirArchivo(char *nom){
	Alumnos *leer = new Alumnos();
	fic.open(nom,ios::binary | ios::in);
	while(!fic.eof() && fic.read(reinterpret_cast<char*>(leer),sizeof(Alumnos))){
		leer->imprimir();
	}
	fic.close();
}

template <class T>
bool Archivo<T>::busquedaSecuencial(T &buscar){
	bool band = false;
	fic.open("Alumno.dat",ios::binary | ios::in);
	while(!band && !fic.eof() && fic.read(reinterpret_cast<char*>(&leer),sizeof(T))){
		if(buscar.getCedula()==leer.getCedula()){
			band = true;
			buscar = leer;
		}
	} 
	fic.close();
	return band;
}

template <class T>
bool Archivo<T>::busquedaSecuencialTel(T &buscar){
	bool band = false;
	fic.open("Alumno.dat",ios::binary | ios::in);
	while(!band && !fic.eof() && fic.read(reinterpret_cast<char*>(&leer),sizeof(T))){
		if(buscar.getCelular()==leer.getCelular()){
			band = true;
			buscar = leer;
		}
	} 
	fic.close();
	return band;
}
template <class T>
bool Archivo<T>::busquedaBinaria(T &buscar,int N){
	bool band=false;
    int lInferior=0, lSuperior=N-1,centro;

	fic.open("Alumno.dat",ios::binary | ios::in);
	    while (!band && lInferior<=lSuperior){
	        centro = (lInferior+lSuperior)/2;
	        fic.seekg((centro*sizeof(T)), ios::beg ); 
	        fic.read (reinterpret_cast<char*>(&leer),sizeof(T));
	        if(strcmp(buscar.getNombre(),leer.getNombre())==0){
	            band=true;
	            buscar=leer;
	        }else if (strcmp(buscar.getNombre(),leer.getNombre())<0){
	        	 lSuperior = centro - 1;
			}else lInferior = centro + 1;
	    }
	fic.close();
    return band;
}
#endif
