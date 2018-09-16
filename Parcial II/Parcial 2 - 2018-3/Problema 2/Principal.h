#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <fstream>
#include <stdlib.h>
#include <conio.h>

#include "Genero.h"
#include "Canciones.h"

using namespace std;
class Principal{
	fstream genero,canciones;
	ListDinSimple<Genero> listaGen;
	
	string cadena;
	char *auxCadena;
	
	public:
	void Main();
	void separarGenero();
	void separarDatos();
	void imprimirListado();
	void imprimirListadoPorGenero();
	void agregarCancion();
	void consultarInformacionCancion();
	void eliminarCancion();
	
	void mostrarMensajeError();
};

void Principal::Main(){
	bool band = true;
	char tecla;
	
		Principal::separarGenero();
		Principal::separarDatos();
	do{
		cout<<"1) Imprimir Catalogo General por Genero."<<endl;
		cout<<"2) Imprimir Listado de canciones por Genero."<<endl;
		cout<<"3) Agregar una Cancion"<<endl;
		cout<<"4) Consultar Informacion de una Cancion."<<endl;
		cout<<"5) Eliminar una Cancion."<<endl;
		cout<<"6) Salir y Actualizar Archivo";
		
		tecla = getch();
		switch(tecla){
			case '1':
				system("cls");
				Principal::imprimirListado();
				cout<<endl;
				system("PAUSE");
				system("cls");
				break;
			case '2':
				system("cls");
				Principal::imprimirListadoPorGenero();
				system("PAUSE");
				system("cls");
				break;
			case '3':
				system("cls");
				Principal::agregarCancion();
				system("PAUSE");
				system("cls");
				break;
			case '4':
				system("cls");
				Principal::consultarInformacionCancion();
				system("PAUSE");
				system("cls");
				break;
			case '5':
				system("cls");
				Principal::eliminarCancion();
				system("PAUSE");
				system("cls");
				break;
			case '6':
				system("cls");
				cout<<"Fin del Programa."<<endl<<endl;
				band = false;
//				listaGen.imprimir();
				system("PAUSE");
				system("cls");
				break;
			default: 
				system("cls");
				cout<<"OPCION INVALIDA!"<<endl<<endl;
				system("PAUSE");
				system("cls");
		}
		
	}while(band);
}

void Principal::separarGenero(){
	char nombre[40]="mp3.txt";
	genero.open(nombre,ios::in);
		if(genero.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(genero,cadena)){
				auxCadena = strtok(&cadena[0],",");
				char auxTitulo[40];
				strcpy(auxTitulo,auxCadena);
				
				auxCadena = strtok(NULL,",");
				char auxAutor[40];
				strcpy(auxAutor,auxCadena);
				
				auxCadena = strtok(NULL,",");
				int auxTamKb = atoi(auxCadena);
								
				auxCadena = strtok(NULL,",");
				char auxAlbum[40];
				strcpy(auxAlbum,auxCadena);
							
				auxCadena = strtok(NULL,"\n");
				char auxGenero[40];
				strcpy(auxGenero,auxCadena);
					
//				cout<<"Titulo: "<<auxTitulo<<" Auto: "<<auxAutor<<" Tamaño: "<<auxTamKb<< " Album: "<<auxAlbum<<" Genero: "<<auxGenero<<endl;
				Genero u(auxGenero);
				if(listaGen.buscar(u)!=1) listaGen.agregar(u);
			}
		}
	genero.close();
}

void Principal::separarDatos(){
	char nombre[40]="mp3.txt";
	canciones.open(nombre,ios::in);
		if(canciones.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(canciones,cadena)){
				auxCadena = strtok(&cadena[0],",");
				char auxTitulo[30];
				strcpy(auxTitulo,auxCadena);
				
				auxCadena = strtok(NULL,",");
				char auxAutor[30];
				strcpy(auxAutor,auxCadena);
				
				auxCadena = strtok(NULL,",");
				int auxTamKb = atoi(auxCadena);
								
				auxCadena = strtok(NULL,",");
				char auxAlbum[30];
				strcpy(auxAlbum,auxCadena);
							
				auxCadena = strtok(NULL,"\n");
				char auxGenero[30];
				strcpy(auxGenero,auxCadena);
					
//				cout<<"Titulo: "<<auxTitulo<<" Auto: "<<auxAutor<<" Tamaño: "<<auxTamKb<< " Album: "<<auxAlbum<<" Genero: "<<auxGenero<<endl;
				Canciones can(auxTitulo,auxAutor,auxTamKb,auxAlbum,auxGenero);
				Genero buscar(auxGenero);
					if(listaGen.buscar(buscar)==1){
						buscar.agregarCancion(can);
					}
				
			}
		}
	canciones.close();
}

void Principal::imprimirListado(){
	Nodo<Genero> *Gen;
	Gen = listaGen.getCab();
	cout<<"Listado por Genero."<<endl;
		while(Gen!=NULL){
			Gen->getInfo().imprimir(true);
			Gen = Gen->getSig();
		}
}

void Principal::agregarCancion(){
	char titulo[30];
	char autor[30];
	int tama;
	char album[30];
	char genero[30];
	
	cout<<"Agregar Cancion."<<endl<<endl;
	
	cout<<"Ingrese un Titulo: ";
	cin>>titulo;
	cout<<endl<<"Ingrese un Autor: ";
	cin>>autor;
	cout<<endl<<"Ingrese Tamaño de la cancion: ";
	cin>>tama;
	cout<<endl<<"Ingrese el Album: ";
	cin>>album;
	cout<<endl<<"Ingrese el genero: ";
	cin>>genero;
	
	Genero consultar(genero);
	Canciones can(titulo,autor,tama,album,genero);
		if(listaGen.buscar(consultar)==1){
			if(consultar.buscarCancion(can)==1){
				consultar.agregarCancion(can);
				cout<<endl<<"Se Agrego Sastifactoriamente."<<endl<<endl;
			}else cout<<endl<<"Dato Existente."<<endl<<endl;
		}else{
			listaGen.agregar(consultar);
				if(listaGen.buscar(consultar)==1){
					if(consultar.buscarCancion(can)!=1) consultar.agregarCancion(can);
					cout<<endl<<"Se Agrego los Datos Sastifactoriamente."<<endl;
				}
			cout<<"Genero agregado Sastifactoriamente."<<endl<<endl;
		}
}

void Principal::consultarInformacionCancion(){
	char nombre[40]="mp3.txt";
	char genero[30];
	char cancion[30];
	char letra;
	bool invert = true;
	cout<<"Ingrese la cancion que deseas consultar: ";
	cin>>cancion;
	
	canciones.open(nombre,ios::in);
		if(canciones.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(canciones,cadena)){
				auxCadena = strtok(&cadena[0],",");
				char auxTitulo[30];
				strcpy(auxTitulo,auxCadena);
				
				auxCadena = strtok(NULL,",");
				char auxAutor[30];
				strcpy(auxAutor,auxCadena);
				
				auxCadena = strtok(NULL,",");
				int auxTamKb = atoi(auxCadena);
								
				auxCadena = strtok(NULL,",");
				char auxAlbum[30];
				strcpy(auxAlbum,auxCadena);
							
				auxCadena = strtok(NULL,"\n");
				char auxGenero[30];
				strcpy(auxGenero,auxCadena);
					
				if(strcmpi(cancion,auxTitulo)==0){
					strcpy(genero,auxGenero);
				}
			}
		}
	canciones.close();
	
	Genero consultar(genero);
	Canciones can(cancion,"",0,"","");
		if(listaGen.buscar(consultar)==1){
			if(consultar.buscarCancion(can)==1){
				letra = cancion[0];
				if((letra >= 'A' && letra<='I') || (letra>='a' && letra<='i')){
					if(invert){
						cout<<"Existe cancion"<<endl;
						consultar.imprimir(true);
					}else{
						cout<<"Existe cancion"<<endl;
						consultar.invertListaCanciones();
						consultar.imprimir(true);
						invert = true;
					}
				}else if((letra >= 'J' && letra<='Z') || (letra>='j' && letra<='z')){
					if(invert){
						cout<<"Existe cancion"<<endl;
						consultar.invertListaCanciones();
						consultar.imprimir(true);
						invert = false;
					}else{
						cout<<"Existe cancion"<<endl;
						consultar.imprimir(true);
					}
				}
			}else cout<<endl<<"La cancion no se Elimino, xq No Existe."<<endl;
		}else cout<<endl<<"El Genero no Existe."<<endl;
}

void Principal::eliminarCancion(){
	char nombre[40]="mp3.txt";
	char genero[30];
	char cancion[30];

	cout<<"Ingrese la cancion que deseas consultar: ";
	cin>>cancion;
	canciones.open(nombre,ios::in);
		if(canciones.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(canciones,cadena)){
				auxCadena = strtok(&cadena[0],",");
				char auxTitulo[30];
				strcpy(auxTitulo,auxCadena);
				
				auxCadena = strtok(NULL,",");
				char auxAutor[30];
				strcpy(auxAutor,auxCadena);
				
				auxCadena = strtok(NULL,",");
				int auxTamKb = atoi(auxCadena);
								
				auxCadena = strtok(NULL,",");
				char auxAlbum[30];
				strcpy(auxAlbum,auxCadena);
							
				auxCadena = strtok(NULL,"\n");
				char auxGenero[30];
				strcpy(auxGenero,auxCadena);
					
				if(strcmpi(cancion,auxTitulo)==0){
					strcpy(genero,auxGenero);
				}
			}
		}
	canciones.close();
	
	Genero consultar(genero);
	Canciones can(cancion,"",0,"","");
		if(listaGen.buscar(consultar)==1){
			if(consultar.buscarCancion(can)==1){
				consultar.eliminarCancion(can);
				cout<<endl<<"Se Elimino Sastifactoriamente."<<endl;
			}else cout<<endl<<"La cancion no Existe."<<endl;
		}else cout<<endl<<"El Genero no Existe."<<endl;
}

void Principal::imprimirListadoPorGenero(){
	char genero[30];
	
	cout<<" Ingrese el Genero a Consultar: ";
	cin>>genero;
	Genero consultar(genero);
		if(listaGen.buscar(consultar)==1) consultar.imprimir(true);
	
}

void Principal::mostrarMensajeError(){
	system("cls");
	cout<<"Error - Debes Crear el Sistema."<<endl<<endl;
	system("PAUSE");
	system("cls");
}
#endif
