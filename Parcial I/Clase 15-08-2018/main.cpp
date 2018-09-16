#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <algorithm>

#include "Archivo.h"

/**
	Escriba un programa para leer un archivo de texto los datos de archivo mp3 descargados desde iTunes:
	genero,album,artista,cancion y tamaño, separados por espacio en blanco. Cargas los datos en un vector 
	y ordenar de acuerdo a:
		*primera clave: genero
		*segunda clave: artista
		*tercera clave: album
		*cuarta clave: cancion
	
	Nota: usar el metodo ShakerSort
*/

template <class T>
void inter(T &A, T &B);

template <class T>
void crearAndImprimir(vector<T> &v,int &n);

template <class T>
void ordenarGenero(vector<T> &v,string nombre);

template <class T>
void ordenarArtista(vector<T> &v,string nombre);

template <class T>
void ordenarAlbum(vector<T> &v,string nombre);

template <class T>
void ordenarCancion(vector<T> &v,string nombre);

inline string to_string(int x);
using namespace std;
int main(int argc, char** argv) {
	vector<iTunes> lista;
	
	int bandera,datModif;
	int cont = 0,tipo;
	bool band = true;
	char tecla,resp;
	
	char nombreArchivo[40] = "mp3.txt";
	Archivo<iTunes> *leer = new Archivo<iTunes>(nombreArchivo);	
	vector<int> busqueda;
	
	leer->abrirFichero();
	leer->separarCadena(lista,0);
	leer->cerrarFichero();	
	
	bandera = lista.size();
	do{
		cout<<"1) Agregar un nuevo archivo mp3."<<endl;
		cout<<"2) Hacer Busqueda."<<endl;
		cout<<"3) Eliminar un Archivo o Cancion."<<endl;
		cout<<"4) Modificar o cambiar cualquier dato."<<endl;
		cout<<"5) Finalizar programa y actulizar el archivo fuente."<<endl;
		tecla=getch();
		switch(tecla){
			case '1':
				system("cls");
				crearAndImprimir(lista,cont);
				system("cls");
				ordenarGenero(lista,"Genero");
				ordenarArtista(lista,"Artista");
				ordenarAlbum(lista,"Album");
				ordenarCancion(lista,"Cancion");
				system("PAUSE");
				system("cls");
				break;
			case '2':
				system("cls");
				cout<<"Busqueda: "<<endl;
					cout<<"Deseas hacer una busqueda? s/n: ";
					cin>>resp;
					while(resp=='S' || resp=='s'){
						system("cls");
						tipo = leer->menuBusqueda("Buscar");
						leer->busquedaPorTipo(lista,busqueda,tipo);
						cout<<endl<<"Deseas hacer una busqueda? s/n: ";
						cin>>resp;
					}
				system("PAUSE");
				system("cls");
				break;
			case '3':
				system("cls");
				cout<<"Eliminar Archivo o Cancion!"<<endl<<endl;
				leer->eliminarArchivo(lista);
				system("PAUSE");
				system("cls");
				break;
			case '4':
				system("cls");
				cout<<"Modificar Array"<<endl;
				datModif = leer->modificarArray(lista);
				system("PAUSE");
				system("cls");
				break;
			case '5':
				system("cls");
				cout<<"Actualizar Archivo!"<<endl;
				leer->modificarArchivo(lista,bandera,datModif);
				system("PAUSE");
				system("cls");
				band = false;
				break;
			default:
				cout<<"Error"<<endl;
				system("PAUSE");
				system("cls");
				break;
		}
	}while(band == true);	
	return 0;
}

template <class T>
void inter(T &A, T &B){
	T aux = A;
	A = B;
	B = aux;
}

template <class T>
void ordenarGenero(vector<T> &v,string nombre){
	int inicio = 0,final = v.size()-1;
	int band;
	
	do{
		band=0;
		for(int i=inicio;i<final;i++){
			if(strcmpi(v[i].getGenero().c_str(),v[i+1].getGenero().c_str())>0){
				inter(v[i],v[i+1]);
				band=1;
			}
		}
		if(band==1){
			for(int i=final-1,band=0;i>inicio;i--){
				if(strcmpi(v[i].getGenero().c_str(),v[i-1].getGenero().c_str())<0){
					inter(v[i],v[i-1]);
					band=1;
				}
			}
		}
		inicio++;
		final--;
	}while(inicio<final && band==1);
	
	cout<<"Ordenado por "<<nombre<<"!"<<endl<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].getGenero()<<endl;
	}
	cout<<endl;
}

template <class T>
void ordenarArtista(vector<T> &v,string nombre){
	int inicio = 0,final = v.size()-1;
	int band;
	
	do{
		band=0;
		for(int i=inicio;i<final;i++){
			if(strcmpi(v[i].getArtista().c_str(),v[i+1].getArtista().c_str())>0){
				inter(v[i],v[i+1]);
				band=1;
			}
		}
		if(band==1){
			for(int i=final-1,band=0;i>inicio;i--){
				if(strcmpi(v[i].getArtista().c_str(),v[i-1].getArtista().c_str())<0){
					inter(v[i],v[i-1]);
					band=1;
				}
			}
		}
		inicio++;
		final--;
	}while(inicio<final && band==1);
	
	cout<<"Ordenado por "<<nombre<<"!"<<endl<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].getArtista()<<endl;
	}
	cout<<endl;
}

template <class T>
void ordenarAlbum(vector<T> &v,string nombre){
	int inicio = 0,final = v.size()-1;
	int band;
	
	do{
		band=0;
		for(int i=inicio;i<final;i++){
			if(strcmpi(v[i].getAlbum().c_str(),v[i+1].getAlbum().c_str())>0){
				inter(v[i],v[i+1]);
				band=1;
			}
		}
		if(band==1){
			for(int i=final-1,band=0;i>inicio;i--){
				if(strcmpi(v[i].getAlbum().c_str(),v[i-1].getAlbum().c_str())<0){
					inter(v[i],v[i-1]);
					band=1;
				}
			}
		}
		inicio++;
		final--;
	}while(inicio<final && band==1);
	
	cout<<"Ordenado por "<<nombre<<"!"<<endl<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].getAlbum()<<endl;
	}
	cout<<endl;
}

template <class T>
void ordenarCancion(vector<T> &v,string nombre){
	int inicio = 0,final = v.size()-1;
	int band;
	
	do{
		band=0;
		for(int i=inicio;i<final;i++){
			if(strcmpi(v[i].getCancion().c_str(),v[i+1].getCancion().c_str())>0){
				inter(v[i],v[i+1]);
				band=1;
			}
		}
		if(band==1){
			for(int i=final-1,band=0;i>inicio;i--){
				if(strcmpi(v[i].getCancion().c_str(),v[i-1].getCancion().c_str())<0){
					inter(v[i],v[i-1]);
					band=1;
				}
			}
		}
		inicio++;
		final--;
	}while(inicio<final && band==1);
	
	cout<<"Ordenado por "<<nombre<<"!"<<endl<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i].getCancion()<<endl;
	}
	cout<<endl;
}
template <class T>
void crearAndImprimir(vector<T> &v,int &n){
	Archivo<T> *leer = new Archivo<T>();	
	leer->crearArchivo(v);
}

inline string to_string(int x){
	string l;
		while(x) {
			l.push_back(x%10 + '0');
			x/=10;
		}
	reverse(l.begin(), l.end());
	return l;
}
