#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string.h>

#include "Mp3.h"
#include "Colas_dinamicas.h"

using namespace std;
class Principal{
	Colas_dinamicas<Mp3> colaMusica;
	fstream ficheroTexto;
	string cadena;
	char *auxCadena;
	public:
		Principal(){}
		void Main();
		void cargarMusica();
		void inicioReproducion(char tecla);
};

void Principal::Main(){
	bool band = true;
	bool bandera = false;
	char tecla;
	
	do{
		cout<<"R) Reproducir Cancion."<<endl;
		cout<<"C) Cargar Musica."<<endl;
		cout<<"A) Salir.";
		tecla = getch();
		switch(tecla){
			case 'r':
				system("cls");
				if(bandera){
					Principal::inicioReproducion(tecla);
				}else{
					cout<<"No se ha cargado la lista de Musica!"<<endl;
				}
				system("PAUSE");
				system("cls");
				break;
			case 'c':
				system("cls");
				Principal::cargarMusica();
				bandera = true;
				cout<<"Musica Cargada Sastifactoriamente!"<<endl;
				system("PAUSE");
				system("cls");
				break;
			case 'a':
				system("cls");
				band = false;
				system("PAUSE");
				system("cls");
				break;
			default:
				system("cls");
				cout<<"OPCION INVALIDA.!"<<endl<<endl;
				system("PAUSE");
				system("cls"); 
		}		
	}while(band);
}

void Principal::cargarMusica(){
	char nombre[40]="mp3.txt";
	ficheroTexto.open(nombre,ios::in);
		if(ficheroTexto.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(ficheroTexto,cadena)){
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
				Mp3 u(auxTitulo,auxAutor,auxTamKb,auxAlbum,auxGenero);
				colaMusica.Anadir(u);
			}
		}
	ficheroTexto.close();
}
void Principal::inicioReproducion(char tecla){
	time_t assed_time,start_time,current_time,passed_time;
	time(&start_time);
	bool band = true;
	bool bandAux = true; 
	bool bandAuxEliminar = true; 
	int m=0,s=0,p=0,valorMaximo,valor = 0;
	Mp3 auxEliminar;
	Mp3 AuxLeer;
	/* Funciona !!! Yeah!!! */
	while(band){
		system("cls");
		cout<<"S) Detener Cancion."<<endl;
		cout<<"P) Pausar Cancion."<<endl;
		cout<<"N) Siguiente Cancion."<<endl<<endl;
		colaMusica.Imprimir();
		time(&current_time);
		passed_time=current_time-start_time;
		m=(p+passed_time)/60;
		s=(p+passed_time)%60;
		cout<<endl<<"Reproduciendo Musica."<<endl<<endl;
		AuxLeer = colaMusica.Leer();
		cout<<AuxLeer<<endl;
		printf("Tiempo %02d:%02d",m,s);
		valorMaximo = (AuxLeer.getTam()*1024)/24;
		cout<<"  | Duracion de la Cancion: "<<valorMaximo<<" Segundos";
		
		Sleep(100);	
		if(s==valorMaximo){
			colaMusica.Eliminar();
			Principal::inicioReproducion(tecla);
		}
		if(tecla == 's' || tecla == 'S'){
			band = false;
			break;
		}
		while(tecla == 'n' || tecla == 'N'){
			if(bandAuxEliminar){
				if(colaMusica.isVacia()) Principal::Main();
				colaMusica.Eliminar();
				bandAuxEliminar = false;
				cout<<endl<<"Siguiente Cancion.";
				cout<<endl<<"Presiona r o R para Iniciar Nueva Cancion!";
			}
			tecla = getch();
			if(tecla == 'r' || tecla == 'R') {
				current_time = 0;
				bandAuxEliminar = true;
				bandAux = true;
				Principal::inicioReproducion(tecla); 
			}
			else {
				cout<<"Opcion Invalida!"<<endl;
				cout<<"Presiona una Tecla Valida!";
			}
		}
		while(tecla == 'p' || tecla =='P'){
			if(bandAux){
				cout<<endl<<"En Pausa!.";
				cout<<endl<<"Presiona r o R para continuar!";
				bandAux = false; 
			}
			tecla = getch();
			if(tecla == 'r' || tecla == 'R') {
				current_time = 0;
				bandAux = true;
			}
			else {
				cout<<"Opcion Invalida!"<<endl;
				cout<<"Presiona una Tecla Valida!";
			}		
		}
		if(colaMusica.isVacia()){
			system("cls");
			valor = 1;
			break;
		}
		if(_kbhit())
		tecla = getch();
	}
	if(valor==0) cout<<endl<<"Se Detuvo la Cancion."<<endl;
	else cout<<endl<<"No existen mas canciones para reproducir."<<endl;
}
#endif
