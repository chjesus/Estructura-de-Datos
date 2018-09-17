#include <iostream>
#include <conio.h>

#include "Archivo.h"
#include "MezclaDirecta.h"

void busquedaNombre(int tam){	
	Archivo<Alumnos> leer;
	char nombreBus[40];
	
	cout<<"Ingrese el nombre a buscar: ";
	cin>>nombreBus;
	Alumnos a(0,nombreBus,0,0.0,"");
	if(leer.busquedaBinaria(a,tam)){
		a.imprimir();
		cout<<endl<<"Dato Encontrado!!"<<endl<<endl;
	}else{
		cout<<endl<<"Dato no Encontrado!"<<endl<<endl;
	}
}
void busquedaCedula(){	
	Archivo<Alumnos> leer;
	int cedula;
	
	cout<<"Ingrese la cedula a buscar: ";
	cin>>cedula;
	Alumnos a(cedula,"",0,0.0,"");
	if(leer.busquedaSecuencial(a)){
		a.imprimir();
		cout<<endl<<"Dato Encontrado!!"<<endl<<endl;
	}else{
		cout<<endl<<"Dato no Encontrado!"<<endl<<endl;
	}
}

void busquedaTelefono(int tam){
	Archivo<Alumnos> leer;
	int telf,pos;
	
	cout<<"Ingrese el telefono a buscar: ";
	cin>>telf;
	Alumnos a(0,"",telf,0.0,"");
	if(leer.busquedaSecuencialTel(a)){
		a.imprimir();
		cout<<endl<<"Dato encontrado!!"<<endl<<endl;
	}else{
		cout<<endl<<"Dato no Encontrado!"<<endl<<endl;
	}
}
using namespace std;
int main(int argc, char** argv) {
	char nombre[40]="Alumno.dat";
	vector<Alumnos> listaAlum;
	Archivo<Alumnos> leer;
	bool band = true;
	char tecla;

	leer.llenarVector(nombre,listaAlum);
	int tam = listaAlum.size();
	
	MezclaDirecta<Alumnos> ordenar("Alumno.dat");
	ordenar.Ordenar(tam);
	
	do{
		cout<<"1) Imprimir Datos."<<endl;
		cout<<"2) Buscar por Nombre."<<endl;
		cout<<"3) Buscar por Cedula."<<endl;
		cout<<"4) Buscar por Telefono."<<endl;
		cout<<"5) Salir.";
		tecla = getch();
		switch(tecla){
			case '1':
				system("cls");
				cout<<"Datos:"<<endl<<endl;
				leer.imprimirArchivo(nombre);
				cout<<endl;
				system("PAUSE");
				system("cls");
				break;
			case '2':
				system("cls");
				busquedaNombre(tam);
				cout<<endl;
				system("PAUSE");
				system("cls");
				break;
			case '3':
				system("cls");
				busquedaCedula();
				cout<<endl;
				system("PAUSE");
				system("cls");
				break;
			case '4':
				system("cls");
				busquedaTelefono(tam);
				cout<<endl;
				system("PAUSE");
				system("cls");
				break;
			case '5':
				system("cls");
				band = false;
				system("PAUSE");
				system("cls");
				break;
			default:
				system("cls");
				cout<<"Opcion invalida!"<<endl;
				system("PAUSE");
				system("cls");
		}
	}while(band == true);

	return 0;
}
