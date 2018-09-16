#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ListaCircularSimple.h"

using namespace std;
class Principal{
	string c,n;
	char cedula[40];
	char nombre[40];
	ListaCircularSimple<int> listC;
	ListaCircularSimple<char> listN;
	public:
		Principal(){}
		void inicio();
		int validar(char *n);
		void resultado();
};

void Principal::inicio(){
	int val,aux;
	
	cout<<"Ingrese una Cedula: ";
	cin>>cedula;
	fflush(stdin);
	cout<<"Ingrese un Nombre: ";
	cin.getline(nombre,40);
	
	val = validar(cedula);
		if(val == 0){
			for(int i=0;i<strlen(cedula);i++){
				c = cedula[i];
				aux = atoi(c.c_str());
				if(listC.Buscar(aux)==0) listC.agregar(aux,true);
			}
			for(int i=0;i<strlen(nombre);i++){
				n = nombre[i];
				if(n != " ") listN.agregar(nombre[i]);
			}
			listC.imprimir();
			cout<<endl<<endl;
			listN.imprimir();
			cout<<endl<<endl;
			cout<<"Codigo: ";
			resultado();
		}else{
			cout<<"salir";
		}
}

void Principal::resultado(){
	int asci,cont = 0,Pasos;
	char c;
	
	do{
		asci = listN.getActual();
		Pasos = asci%listC.getSize();
		cont++;
		listC.moverNpasos(Pasos);
		cout<<listC.getActual();
		listN.moverNpasos(1);
	}while(cont<listN.getSize());	
}

int Principal::validar(char *n){
	int tam,i=0,valid=0;
	tam = strlen(n);
		while(i<tam && valid==0){
			if(isdigit(n[i])!=0){
				i++;
			}else{
				valid=1;
			}
		}
	return valid;
}
#endif
