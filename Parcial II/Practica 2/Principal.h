#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <conio.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "Archivo.h"
#include "Personas.h"
#include "Colas_dinamicas.h"
#include "ListaEnlazada.h"
using namespace std;
template <class T>
class Principal{
	Colas_dinamicas<int> cola;
	ListaEnlazada<T> lista;
	Archivo<T> *leer; 
	vector<T> datos;
	vector<T> clientesF;
	T persona;
	char tecla;
	bool band;
	int tam,cont,contDatos;
	public:
		Principal(){}
		void Menu();
};

template <class T>
void Principal<T>::Menu(){
	char nombreArchivo[20] = "titular.txt";
	string auxPalabra,newPalabra;
	int ced,clave,aux,restarCaracter = 0,tam,contClientes;
	leer = new Archivo<T>(nombreArchivo);
	band = true;
	contDatos = 0;
	int minInicio = 0,segInicio = 0;
	int m,s,p=0;
	int auxm=0;
	int auxs=0;
	int mayorM=-999,mayorS=-999;
	int menorM=999,menorS=999;
	int taqMayor,taqMenor;
	time_t timerVisual = time(NULL); 
	time_t assed_time,start_time,current_time,passed_time;
	time(&start_time);
	do{
		cout<<"A) Leer del Archivo una linea, generar el codigo, agregar a la cola y lista."<<endl;
		cout<<"L) Para visualizar la infomacion de la lista."<<endl;
		cout<<"1) Para finalizar la atencion del cliente en taquilla 1."<<endl;
		cout<<"2) Para finalizar la atencion del cliente en taquilla 2."<<endl;
		cout<<"3) Para finalizar la atencion del cliente en taquilla 3."<<endl;
		cout<<"F) Finalizar la ejecucion del programa y ver las estadisticas del tiempo.";
		tecla = getch();
		switch(tecla){
			case 'a':
				system("cls");
				datos.clear();
				leer->abrirFichero();
				leer->separarCadena(datos);
				leer->cerrarFichero();
				for(int i=0;i<datos.size();i++){
					cout<<"Cedula: "<<datos[i].getCedula()<<" | Nombre: "<<datos[i].getNombre()<<endl;
				}
				if(contDatos < datos.size()){
					cout<<endl<<"Dato a Guardar: "<<datos[contDatos].getCedula()<<endl;
					auxPalabra = datos[contDatos].getCedula();
					ced = atoi(auxPalabra.c_str());
					clave = ced%1000;
					
					restarCaracter = 0;
						while(!lista.isVacia()){
						newPalabra = "";
						aux = lista.Comparar(clave);
							if(aux==1){
								restarCaracter++;
								for(int i = 0; i<auxPalabra.length()-restarCaracter;i++){
									newPalabra +=auxPalabra[i];
								}
								auxPalabra = newPalabra;
								ced = atoi(auxPalabra.c_str());
								clave = ced%1000;
							}else{
								break;
							}
						}
						T a(clave,datos[contDatos].getCedula(),datos[contDatos].getNombre());
						lista.Anadir(a);
						cola.Anadir(clave);
					contDatos++;
					cout<<endl<<"Dato almacenado!";
				}else{
					cout<<"No ahi mas datos para procesar!."<<endl<<endl;
					system("PAUSE");
					system("cls");
				}
				cout<<endl<<endl<<"Hora de inicio: "<<ctime(&timerVisual)<<endl<<endl;
					time(&current_time);
					passed_time=current_time-start_time;
					m=(p+passed_time)/60;
					s=(p+passed_time)%60;
				system("PAUSE");
				system("cls");
				break;
			case 'l':
				system("cls");
				cout<<"Datos en lista!"<<endl<<endl;
				lista.Imprimir();
				system("PAUSE");
				system("cls");
				break;
			case '1':
				system("cls");
				cout<<"Taquilla #1"<<endl;
					if(!cola.isVacia()){
						T data(cola.Leer(),1);
						T eliminar(cola.Leer(),"","");
						clientesF.push_back(data);
						cola.Eliminar();
						int eliminarLista = cola.Leer();
						lista.Eliminar(eliminar);
					}else{
						cout<<"Todos los clientes se Encuentran despachados!";
					}
					cout<<endl<<"Ultimos 5 clientes Atendidos: "<<endl<<endl;
					tam = clientesF.size()-1;
					contClientes=0;
					while(contClientes < 5 && tam > -1){
						if(clientesF[tam].getTaquilla() == 1){
							cout<<"Clave: "<<setfill('0')<<setw(3)<<clientesF[tam].getClave()<<" | Taquilla "<<clientesF[tam].getTaquilla()<<endl;
							contClientes++;
						}
						tam--;
					}
				if(m>mayorM || s>mayorS){
					mayorM=m;
					mayorS=s;
					taqMayor=1;
				}
				if(m<menorM || s<menorS){
					menorM=m;
					menorS=s;
					taqMenor=1;
				}
				cout<<"Transcurrio: "<<m-auxm<<":Minutos "<<s-auxs<<":Segundos"<<endl<<endl;
				auxm=m;
				auxs=s;
				system("PAUSE");
				system("cls");
				break;
			case '2':
				system("cls");
				cout<<"Taquilla #2"<<endl;
					if(!cola.isVacia()){
						T data(cola.Leer(),2);
						T eliminar(cola.Leer(),"","");
						clientesF.push_back(data);
						cola.Eliminar();
						int eliminarLista = cola.Leer();
						lista.Eliminar(eliminar);
					}else{
						cout<<"Todos los clientes se Encuentran despachados!";
					}
					cout<<endl<<"Ultimos 5 clientes Atendidos: "<<endl<<endl;
					tam = clientesF.size()-1;
					contClientes=0;
					while(contClientes < 5 && tam > -1){
						if(clientesF[tam].getTaquilla()==2){
							cout.fill('0');
							cout.width(3);
							cout<<"Clave: "<<setfill('0')<<setw(3)<<clientesF[tam].getClave()<<" | Taquilla "<<clientesF[tam].getTaquilla()<<endl;
							contClientes++;
						}
						tam--;
					}
				if(m>mayorM || s>mayorS){
					mayorM=m;
					mayorS=s;
					taqMayor=2;
				}
				if(m<menorM || s<menorS){
					menorM=m;
					menorS=s;
					taqMenor=2;
				}
				cout<<"Transcurrio: "<<m-auxm<<":Minutos "<<s-auxs<<":Segundos"<<endl<<endl;
				auxm=m;
				auxs=s;
				system("PAUSE");
				system("cls");
				break;
			case '3':
				system("cls");
				cout<<"Taquilla #3"<<endl;
					if(!cola.isVacia()){
						T data(cola.Leer(),3);
						T eliminar(cola.Leer(),"","");
						clientesF.push_back(data);
						cola.Eliminar();
						int eliminarLista = cola.Leer();
						lista.Eliminar(eliminar);
					}else{
						cout<<"Todos los clientes se Encuentran despachados!";
					}
					cout<<endl<<"Ultimos 5 clientes Atendidos: "<<endl<<endl;
					tam = clientesF.size()-1;
					contClientes=0;
					while(contClientes < 5 && tam > -1){
						if(clientesF[tam].getTaquilla()==3){
							cout<<"Clave: "<<setfill('0')<<setw(3)<<clientesF[tam].getClave()<<" | Taquilla "<<clientesF[tam].getTaquilla()<<endl;
							contClientes++;
						}
						tam--;
					}
				if(m>mayorM || s>mayorS){
					mayorM=m;
					mayorS=s;
					taqMayor=3;
				}
				if(m<menorM || s<menorS){
					menorM=m;
					menorS=s;
					taqMenor=3;
				}
				cout<<"Transcurrio: "<<m-auxm<<":Minutos "<<s-auxs<<":Segundos"<<endl<<endl;
				auxm=m;
				auxs=s;
				system("PAUSE");
				system("cls");
				break;
			case 'f':
				band = false;
				system("cls");
				if(mayorM >-1 && mayorS>-1){
					cout<<"Taquilla con mayor tiempo es: "<<"Taquilla "<<taqMayor<<" | Minutos: "<<mayorM<<" Segundos: "<<mayorS<<endl;
				}else{
					cout<<endl<<"No se a despachado algun cliente para determinar el mayor tiempo"<<endl;
				}
				
				if(menorM<999 && menorS<999){
					cout<<endl<<"Taquilla con menor tiempo es: "<<"Taquilla "<<taqMenor<<" | Minutos: "<<menorM<<" Segundos: "<<menorS<<endl;
				}else{
					cout<<endl<<"No se a despachado algun cliente para determinar el menor tiempo"<<endl;
				}
				cout<<"Fin del Programa.";
				break;
			default:
				system("cls");
				cout<<"Opcion invalida!";
				system("PAUSE");
				system("cls");
		}
		Sleep(100);
	}while(band == true);
}
#endif
