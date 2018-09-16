#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

#include "Colas_dinamicas.h"
#include "ListaEnlazada.h"
#include "Vehiculo.h"
#include "Personal.h"

using namespace std;
class Principal{
	Colas_dinamicas<Vehiculo> cola;
	Colas_dinamicas<Vehiculo> listaV;
	
	ListaEnlazada<Personal> lista;
	Colas_dinamicas<Personal> colaP;
	fstream ficheroTexto;
	
	int tam,total,facturar;
	public:
		Principal(){}
		void main();
		void llenarCola();
		void llenarLista();
		void Menu();
		void iniciar(int id);
		void Final();
};

void Principal::main(){
	Principal::llenarCola();
//	cola.Imprimir();
	Principal::llenarLista();
//	lista.Imprimir();
	Principal::Menu();
}

void Principal::Menu(){
	bool band = true;
	char tecla;
	int id;
	
	do{
		cout<<"a) Iniciar Servicio de lavado de un vehiculo."<<endl;
		cout<<"b) Finalizar Servicio de lavado de un vehiculo."<<endl;
		cout<<"c) Consultar datos administrativos."<<endl;
		cout<<"d) Salir.";
		tecla = getch();
		switch(tecla){
			case 'a':
				system("cls");
				cout<<"/-------------------Seleciona algun Personal-------------------/"<<endl<<endl;
				lista.Imprimir();
				cout<<endl<<"Ingrese el id del Personal: ";
				cin>>id;
				iniciar(id);
				system("PAUSE");
				system("cls");
				break;
			case 'b':
				system("cls");
				cout<<"/-------------------Finalizar Lavado de vehiculo-------------------/"<<endl<<endl;
				cout<<"* Vehiculos."<<endl;
				if(listaV.isVacia()){
					cout<<endl<<"No ahi Vehiculos para Procesar.";
				}else listaV.Imprimir();
				cout<<endl<<endl<<"* Lista Personal Ocupado."<<endl;
				Final();
				listaV.Eliminar();
				if(facturar>0){
					cout<<endl<<"Factura: "<<facturar<<endl;
					facturar = 0;
				}
				system("PAUSE");
				system("cls");
				break;
			case 'c':
				system("cls");
				cout<<"/-------------------Consulta de los datos Administrativos-------------------/"<<endl;
//				cout<<"Vehiculos"<<endl;
//				if(listaV.isVacia()){
//					cout<<"No ahi Registros de Lavados."<<endl;
//				}else listaV.Imprimir();
				cout<<endl<<"* Personal"<<endl;
				lista.Imprimir();
				if(total>0){
					cout<<endl<<endl<<"Total Recaudado: "<<total<<endl<<endl;
				}
				system("PAUSE");
				system("cls");
				break;
			case 'd':
				system("cls");
				cout<<"Fin del Programa.";
				band = false;
				break;
			default:
				system("cls");
				cout<<"Error Erroneo"<<endl;
				system("PAUSE");
				system("cls");
		}
	}while(band);
}

void Principal::iniciar(int id){

	Personal b(id,"",true,0);
	Personal aux;
	Vehiculo auxV;
	if(lista.Buscar(b)==1){
		cout<<"Personal Seleccionado"<<endl<<endl;
		aux = lista.Leer(b);
		if(aux.getActivo()==true){
			lista.Eliminar(b);
			aux.setActivo(false);
			lista.Anadir(aux);
			colaP.Anadir(aux);
			
			auxV = cola.Eliminar();
			auxV.setActivo(false);
			listaV.Anadir(auxV);
		}else{
			cout<<endl<<"El Personal que deseas Seleccionar no esta Disponible."<<endl<<endl;
		}
	}else{
		cout<<endl<<"El Personal que deseas Seleccionar no esta Disponible."<<endl<<endl;
	}
}

void Principal::Final(){
	facturar = 0;
	colaP.Imprimir();
	Personal aux;
	aux = colaP.Eliminar();
	if(lista.Buscar(aux)==1){
		if(aux.getActivo()==false){
			lista.Eliminar(aux);
			aux.setPrecio(1500*0.10);
			aux.setActivo(true);
			lista.Anadir(aux);
			total +=1500;
			
			facturar = 1500+(1500*0.10);
		}else{
			cout<<endl<<"No ahi registros de lavado para Finalizar!.";
		}
	}else{
		cout<<endl<<"No ahi registros de lavado para Finalizar!."<<endl<<endl;
	}
}

void Principal::llenarCola(){
	char nombreV[40] = "Vehiculo.txt";
	string cadena;
	char *auxCadena;
	
	ficheroTexto.open(nombreV,ios::in);
		if(ficheroTexto.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(ficheroTexto,cadena)){
				auxCadena = strtok(&cadena[0]," ");
				char auxPlaca[40];
				strcpy(auxPlaca,auxCadena);
				
				auxCadena = strtok(NULL,"\n");
				char auxMarca[40];
				strcpy(auxMarca,auxCadena);
					
				Vehiculo u(auxPlaca,auxMarca,true);
				cola.Anadir(u);
			}
		}
	ficheroTexto.close();
}

void Principal::llenarLista(){
	char nombreP[40] = "Personal.txt";
	string cadena;
	char *auxCadena;
	
	tam = 0;
	ficheroTexto.open(nombreP,ios::in);
		if(ficheroTexto.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(ficheroTexto,cadena)){
				auxCadena = strtok(&cadena[0]," ");
				int auxId = atoi(auxCadena);
				
				auxCadena = strtok(NULL,"\n");
				char auxNombre[40];
				strcpy(auxNombre,auxCadena);
					
				Personal u(auxId,auxNombre,true,0);
				lista.Anadir(u);
				tam++;
			}
		}
	ficheroTexto.close();
}
#endif
