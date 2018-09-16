#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <fstream>
#include <string.h>
#include <stdlib.h>

#include "Personas.h"
#include "PersonaPos.h"
#include "ArbolAVL.h"

using namespace std;
class Principal{
	fstream ficheroTexto;
	fstream ficheroBinario;
	string cadena;
	Personas leer;
	ArbolAVL<PersonaPos> arbol;
	char *auxCadena;
	char *aux;
	public:
		void Main();
		void separar();
		void LLenarArbol();
		void imprimirArbol();
		void buscarDato();
		void buscarEnArchivo(int cedula);
};

void Principal::Main(){
	Principal::separar();
	Principal::LLenarArbol();
	Principal::imprimirArbol();
	Principal::buscarDato();
}

void Principal::separar(){
	char nombre[40]="Personas.txt";
	string auxCad;

	ficheroBinario.open("Personas.dat",ios::binary | ios::out);
		ficheroTexto.open(nombre,ios::in);
		if(ficheroTexto.fail()){
			cout<<"Error al Abrir El Archivo";
		}else{
			while(getline(ficheroTexto,cadena)){
				
				for(int i=0;i<cadena.size();i++){
					auxCad+=cadena[i];
					if(cadena[i]==59 && cadena[i+1]==59){
						auxCad+="x";
					}
				}
				
				cadena = auxCad;
				
				auxCadena = strtok(&cadena[0],";");
				int auxCedula = atoi(auxCadena);
					
				auxCadena = strtok(NULL,";");
				char auxApellido1[40];
				strcpy(auxApellido1,auxCadena);
	
				auxCadena = strtok(NULL,";");
				char auxApellido2[40];
				strcpy(auxApellido2,auxCadena);
	
				auxCadena = strtok(NULL,";");
				char auxNombre1[40];
				strcpy(auxNombre1,auxCadena);
		
				auxCadena = strtok(NULL,";");
				char auxNombre2[40];
				strcpy(auxNombre2,auxCadena);
				
				auxCadena = strtok(NULL,";");
				int auxCodigo = atoi(auxCadena);
			
				auxCadena = strtok(NULL,";");
				char vacio[40];
				strcpy(vacio,auxCadena);
				
				Personas u(auxCedula,auxApellido1,auxApellido2,auxNombre1,auxNombre2,auxCodigo,vacio);
				ficheroBinario.write(reinterpret_cast<char*>(&u),sizeof(Personas));
//				cout<<"Cedula: "<<auxCedula<<" Apellido 1: "<<auxApellido1<< " Apellido 2: "<<auxApellido2<<" Nombre 1:"<<auxNombre1<<" Nombre 2:"<<auxNombre2<<" Codigo: "<<auxCodigo<<endl;		
				auxCad = "";
			}
		}
		ficheroTexto.close();
	ficheroBinario.close();
}

void Principal::LLenarArbol(){
	int posCont=0;
	ficheroBinario.open("Personas.dat",ios::binary | ios::in);
		while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(&leer),sizeof(Personas))){
			PersonaPos aux(leer.getCedula(),posCont);
			posCont++;
			arbol.Anadir(aux);
//			cout<<leer;
		}
	ficheroBinario.close();
}

void Principal::imprimirArbol(){
	arbol.imprimir(2);
	cout<<endl<<endl;
}

void Principal::buscarDato(){
	bool band = true;
	int cedula;
	char tecla;
	
	do{
		cout<<"1) Hacer Busqueda."<<endl;
		cout<<"2) Salir.";
		tecla = getch();
		switch(tecla){
			case '1':
				system("cls");
				cout<<"Ingrese cedula a Buscar: ";
				cin>>cedula;
				Principal::buscarEnArchivo(cedula);
				system("PAUSE");
				system("cls");
				break;
			case '2':
				system("cls");
				cout<<"Fin del Programa.";
				band = false;
				break;
			default:
				system("cls");
				cout<<"OPCION INVALIDA"<<endl;
				system("PAUSE");
				system("cls");			
		}
	}while(band);
}

void Principal::buscarEnArchivo(int cedula){
	PersonaPos buscar(cedula,0);
	Personas leer;
	int pos;
	bool band = false;
	
	if(arbol.Buscar(buscar)){
		buscar = arbol.ValorActual();
		cout<<"Dato Encontrado!"<<endl<<"Informacion: "<<buscar<<endl<<endl;
		pos = buscar.getPosicion();
		band = true;
	}else cout<<"El Dato No Existe!"<<endl<<endl;
	
	
	if(band){
		cout<<"Archivo Binario!"<<endl;
		
		ficheroBinario.open("Personas.dat",ios::binary | ios::in);
		ficheroBinario.seekg(pos*sizeof(Personas),ios::cur);
		ficheroBinario.read(reinterpret_cast<char*>(&leer),sizeof(Personas));
		cout<<leer;
		ficheroBinario.close();
	}
	
	
}
#endif
