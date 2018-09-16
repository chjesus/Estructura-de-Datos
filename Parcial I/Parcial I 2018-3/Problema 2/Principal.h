#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <vector>
#include <fstream>

#include "Encuesta.h"
#include "Materia.h"
#include "Docente.h"
#include "Facilita.h"
using namespace std;

template <class E, class M,class D, class F>
class Principal{
	fstream ficheroBinario;
	E e;
	M m;
	D d;
	F f;
	vector<E> vecEncuesta;
	vector<M> vecMateria;
	vector<D> vecDocente;
	vector<F> vecFacilita;
	
	public:
		Principal(){}
		void inicio();
		void leerEncuesta();
		void leerMateria();
		void leerDocente();
		void leerFacilita();

		void reporteAsignatura();
		
		void imprimir();
};

template <class E, class M,class D, class F>
void Principal<E,M,D,F>::inicio(){
	Principal::leerEncuesta();
	Principal::leerMateria();
	Principal::leerDocente();
	Principal::leerFacilita();
	Principal::reporteAsignatura();
	//Principal::imprimir();
}

template <class E, class M,class D, class F>
void Principal<E,M,D,F>::leerEncuesta(){
	int tam;
	ficheroBinario.open("encuesta.dat",ios::binary | ios::in);
	while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(&e),sizeof(E))){
		vecEncuesta.push_back(e);
	}
	ficheroBinario.close();

}

template <class E, class M,class D, class F>
void Principal<E,M,D,F>::leerMateria(){
	ficheroBinario.open("Materia.dat",ios::binary | ios::in);
	while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(&m),sizeof(M))){
		vecMateria.push_back(m);
	}
	ficheroBinario.close();
}

template <class E, class M,class D, class F>
void Principal<E,M,D,F>::leerDocente(){
	ficheroBinario.open("docente.dat",ios::binary | ios::in);
	while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(&d),sizeof(D))){
		vecDocente.push_back(d);
	}
	ficheroBinario.close();
}

template <class E, class M,class D, class F>
void Principal<E,M,D,F>::leerFacilita(){
	ficheroBinario.open("facilita.dat",ios::binary | ios::in);
	while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(&f),sizeof(F))){
		vecFacilita.push_back(f);
	}
	ficheroBinario.close();
}

template <class E,class M,class D,class F>
void Principal<E,M,D,F>::reporteAsignatura(){
	int contM = 0,contF = 0; 
	float cont = 0;
	float menor = 999.999;
	float mayor = -999.999; 
	float porc = 0.0;
	float contSolicitantes = 0;
	string nombre;
	bool band;
	for(int i=0;i<vecMateria.size();i++){
		contM = 0; contF = 0;cont = 0; porc = 0.0; contSolicitantes = 0; mayor = -999.999; menor = 999.999;
		band = false;
		for(int j=0;j<vecEncuesta.size();j++){
			if(vecMateria[i].getCodigo()==vecEncuesta[j].getCodigo()){
				contSolicitantes++;
				if(vecEncuesta[j].getSexo()=='F'){
					contF++;
				}else contM++;
				
				if(vecEncuesta[j].getCondicion()==0){
					cont++;
				}
				if(vecEncuesta[j].getIndice()<menor){
					menor = vecEncuesta[j].getIndice();
				}
				if(vecEncuesta[j].getIndice()>mayor){
					mayor = vecEncuesta[j].getIndice();
				}
			}
		}

		porc = (cont/contSolicitantes)*100;

		if(contSolicitantes>= 8 && porc >= 25){
			cout<<endl<<"Materia Seleccionada: "<<vecMateria[i].getDescripcion()<<endl;
			for(int k=0;k<vecFacilita.size();k++){
				if(vecMateria[i].getCodigo()==vecFacilita[k].getCodigo()){
					for(int l=0;l<vecDocente.size();l++){
						if(vecFacilita[k].getCedula()==vecDocente[l].getCedula()){
							nombre = vecDocente[l].getNombre();
							band=true;
							cout<<"Docente: "<<nombre<<endl;
						}
					}
				}
			}
			if(band){
				cout<<"Cantidad Estudiantes Femeninos: "<<contF<< " Cantidad Estudiantes Masculinos: "<<contM<<endl;
				cout<<"Rango de Indices: "<<menor<<" - "<<mayor<<endl;
			}
		}
	}
}

template <class E, class M,class D, class F>
void Principal<E,M,D,F>::imprimir(){
	cout<<"Datos de Encuesta"<<endl;
	for(int i=0;i<vecEncuesta.size();i++){
		cout<<vecEncuesta[i];
	}
	cout<<endl<<"Datos de Materia"<<endl;
	for(int i=0;i<vecMateria.size();i++){
		cout<<vecMateria[i];
	}
	cout<<endl<<"Datos de Docentes"<<endl;
	for(int i=0;i<vecDocente.size();i++){
		cout<<vecDocente[i];
	}
	cout<<endl<<"Datos de Facilita"<<endl;
	for(int i=0;i<vecFacilita.size();i++){
		cout<<vecFacilita[i];
	}
}
#endif
