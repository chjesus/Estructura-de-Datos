#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>

#include "iTunes.h"

template <class T>
class Archivo{
	fstream ficheroTexto,ficheroNew;
	string cadena;
	string auxCadena;
	char nombre[40];
	
	public:
		Archivo(){}
		Archivo(char *nom){strcpy(nombre,nom);}
	
		void abrirFichero();
		void cerrarFichero();
		void separarCadena(vector<T> &lista,int x);
		void crearArchivo(vector<T> &lista);
		int menuBusqueda(string b);
		void busquedaPorTipo(vector<T> &lista,vector<int> &busqueda,int tipo);
		void modificarArchivo(vector<T> &lista,int bandera,int x);
		int modificarArray(vector<T> &lista);
		void eliminarArchivo(vector<T> &lista);
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
void Archivo<T>::separarCadena(vector<T> &lista,int x){
	if(ficheroTexto.fail()){
		cout<<"Error al Abrir el Archivo"<<endl<<endl;
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
			if(x == 0){
				T u(genero,album,artista,cancion,tam);
				lista.push_back(u);
			}else if(x == 1){
				cout<<"Genero: "<<genero<<" Album: "<<album<<" Artista: "<<artista<<" Cancion: "<<cancion<<endl;
			}
		}
	}
}

template <class T>
void Archivo<T>::crearArchivo(vector<T> &lista){
	string genero;
	string album;
	string artista;
	string cancion;
	string tam;
	
	bool band;
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i];
	}

	do{
		band = true;
		cout<<endl<<"Ingrese el Genero: ";
		cin>>genero;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getGenero().c_str(),genero.c_str())==0){
				band = false;
				break;
			}
		}
		if(band == false) cout<<"Dato ya Existe"<<endl;
	}while(band == false);
	
	do{
		band = true;
		cout<<"Ingrese el Album: ";
		cin>>album;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getAlbum().c_str(),album.c_str())==0){
				band = false;
				break;
			}
		}
		if(band == false) cout<<"Dato ya Existe"<<endl;
	}while(band == false);
	
	do{
		band = true;
		cout<<"Ingrese el Artista: ";
		cin>>artista;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getArtista().c_str(),artista.c_str())==0){
				band = false;
			}
		}
		if(band == false) cout<<"Dato ya Existe"<<endl;
	}while(band == false);
	
	do{
		band = true;
		cout<<"Ingrese la Cancion: ";
		cin>>cancion;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getCancion().c_str(),cancion.c_str())==0){
				band = false;
				break;
			}
		}
		if(band == false) cout<<"Dato ya Existe"<<endl;
	}while(band == false);
	
	cout<<"Ingrese el Tamaño: ";
	cin>>tam;
	tam+="mb";

	ficheroNew.open("mp3.txt",ios::app);
	ficheroNew<<endl<<genero<<" "<<album<<" "<<artista<<" "<<cancion<<" "<<tam;
	ficheroNew.close();
	
	lista.clear();
	ficheroNew.open("mp3.txt",ios::in);
	if(ficheroNew.fail()){
		cout<<"Error al Abrir el Archivo"<<endl;
	}else{
		while(getline(ficheroNew,cadena)){
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
	ficheroNew.close();
}

template <class T>
int Archivo<T>::menuBusqueda(string b){
	char tecla;
	int tipo;
	bool band = true;
	
	do{
		cout<<"1) "<<b<<" por Genero."<<endl;
		cout<<"2) "<<b<<" por Artista."<<endl;
		cout<<"3) "<<b<<" por Album."<<endl;
		cout<<"4) "<<b<<" por Cancion."<<endl;
		tecla=getch();
			switch(tecla){
				case '1':
					tipo = 1;
					band = false;
					system("cls");
					break;
				case '2':
					tipo = 2;
					band = false;
					system("cls");
					break;
				case '3':
					tipo = 3;
					band = false;
					system("cls");
					break;
				case '4':
					tipo = 4;
					band = false;
					system("cls");
					break;
				default:
					cout<<"Opcion Invalida."<<endl;
					system("PAUSE");
					system("cls");
					break;
		}
	}while(band == true);
	return tipo;
}

template <class T>
void Archivo<T>::busquedaPorTipo(vector<T> &lista,vector<int> &busqueda,int tipo){
	bool band;
	string nombre;
	cout<<"Busqueda por Tipo de dato!"<<endl;
	if(tipo == 1){
		cout<<"Ingrese el Genero: ";
		cin>>nombre;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getGenero().c_str(),nombre.c_str())==0){
				busqueda.push_back(i);
				band=true;
				break;
			}else{
				band = false;
			}
		}	
		if(band == false){
			cout<<"Dato No Encontrado"<<endl;
		}
	}else if(tipo == 2){
		cout<<"Ingrese el Artista: ";
		cin>>nombre;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getArtista().c_str(),nombre.c_str())==0){
				busqueda.push_back(i);
				band=true;
				break;
			}else{
				band = false;
			}
		}
		if(band == false){
			cout<<"Dato No Encontrado"<<endl;
		}
	}else if(tipo == 3){
		cout<<"Ingrese el Album: ";
		cin>>nombre;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getAlbum().c_str(),nombre.c_str())==0){
				busqueda.push_back(i);
				band=true;
				break;
			}else{
				band = false;
			}
		}
		if(band == false){
			cout<<"Dato No Encontrado"<<endl;
		}
	}else if(tipo == 4){
		cout<<"Ingrese la Cancion: ";
		cin>>nombre;
		for(int i=0;i<lista.size();i++){
			if(strcmpi(lista[i].getCancion().c_str(),nombre.c_str())==0){
				busqueda.push_back(i);
				band=true;
				break;
			}else{
				band = false;
			}
		}
		if(band == false){
			cout<<"Dato No Encontrado"<<endl;
		}
	}
	
	cout<<endl<<"Datos Encontrados: "<<endl;
	for(int i=0;i<busqueda.size();i++){
		cout<<lista[busqueda[i]];
	}
}

template <class T>
int Archivo<T>::modificarArray(vector<T> &lista){
	int tipo;
	int pos;
	string palabra;
	
	for(int i=0;i<lista.size();i++){
		cout<<i<<")"<<lista[i];
	}
	cout<<endl<<"ingrese la posicion a modificar: ";
	cin>>pos;
		if(pos>=0 && pos<lista.size()){
			tipo = Archivo::menuBusqueda("Modificar");
			if(tipo == 1){
				cout<<"Ingrese el Genero a Modificar: ";
				cin>>palabra;
				lista[pos].setGenero(palabra);
				return 1;
			}else if(tipo == 2){
				cout<<"Ingrese el Album a Modificar: ";
				cin>>palabra;
				lista[pos].setAlbum(palabra);
				return 1;
			}else if(tipo == 3){
				cout<<"Ingrese el Artista a Modificar: ";
				cin>>palabra;
				lista[pos].setArtista(palabra);
				return 1;
			}else if(tipo == 4){
				cout<<"Ingrese la Cancion a Modificar: ";
				cin>>palabra;
				lista[pos].setCancion(palabra);
				return 1;
			}	
		}else{
			cout<<"Dato no Existe!"<<endl;
			return -1;
		}
}
template <class T>
void Archivo<T>::modificarArchivo(vector<T> &lista,int bandera,int x){
	bool band = false;
	
	cout<<"Archivo Original"<<endl;
	Archivo::abrirFichero();
	Archivo::separarCadena(lista,1);
	Archivo::cerrarFichero();
	
	if(bandera != lista.size() || x == 1){
		ficheroTexto.open("mp3.txt",ios::out);
			for(int i=0;i<lista.size();i++){
				ficheroTexto<<lista[i].getGenero()<<" "<<lista[i].getAlbum()<<" "<<lista[i].getArtista()<<" "<<lista[i].getCancion()<<" "<<lista[i].getTam()<<endl;
			}
		ficheroTexto.close();
		band = true;	
	}
	
	if(band == true){
		cout<<endl<<"Archivo Fuente Actulizado!"<<endl<<endl;
		Archivo::abrirFichero();
		Archivo::separarCadena(lista,1);
		Archivo::cerrarFichero();
	}else{
		cout<<endl<<"El Archivo no fue modificado!."<<endl;
	}
}

template <class T>
void Archivo<T>::eliminarArchivo(vector<T> &lista){
	int pos;
	
	if(lista.empty()){
		cout<<"No se a leido el archivo!"<<endl<<endl;
	}else{
		for(int i=0;i<lista.size();i++){
			cout<<i<<")"<<lista[i];
		}
		
		cout<<"Ingrese la posicion a eliminar!";
		cin>>pos;
		lista.erase(lista.begin()+(pos),lista.begin()+(pos+1));
		
		ficheroTexto.open("mp3.txt",ios::out);
			for(int i=0;i<lista.size();i++){
				ficheroTexto<<lista[i].getGenero()<<" "<<lista[i].getAlbum()<<" "<<lista[i].getArtista()<<" "<<lista[i].getCancion()<<" "<<lista[i].getTam()<<endl;
			}
		ficheroTexto.close();
	}
	
}
#endif
