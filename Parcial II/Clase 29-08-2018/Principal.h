#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "ListaDobCircular.h"

using namespace std;
class Principal{
	ListaDobCircular<int> listaDobC;
	int cantidad;
	public:
		Principal(){}
		void cantidadDatos();
		void jugar();
};

void Principal::cantidadDatos(){
	int valor;
	bool band = true;
	srand(time(NULL));
	
	cantidad = rand()%10+5;
	cout<<cantidad<<endl<<endl;
	
	for(int i=0;i<cantidad;i++){
		valor = rand()%89+10;
			do{
				if(listaDobC.Buscar(valor)==1) band = false;
				else listaDobC.AgregarSinOrden(valor); band = true;
			}while(!band);
	}
	Principal::jugar();
//	listaDobC.Imprimir(0);
}

void Principal::jugar(){
	srand(time(NULL));
	int posicion;
	int aleatorio;
	int eliminar = 10;
	
	do{
		listaDobC.Imprimir(0);
		posicion = cantidad*3; 	
		aleatorio = rand()%2;

		listaDobC.Mover(posicion,aleatorio);
		eliminar = listaDobC.GetActual();
		cout<<endl<<endl<<"Posicion: "<<posicion<<" Direccion: "<<aleatorio<<" Valor: "<<eliminar<<endl;
		listaDobC.EliminarEle(eliminar);
		cantidad--;
		cin.get();
		cout<<endl<<endl<<"Dato eliminado: "<<eliminar<<endl<<endl;
	}while(listaDobC.getTam()!=1);
	cout<<"Gano: "<<endl;
	listaDobC.Imprimir();
	

}
#endif
