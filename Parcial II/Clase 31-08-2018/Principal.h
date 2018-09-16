#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <fstream>
#include <stdlib.h>
#include <conio.h>

#include "Departamento.h"
#include "Producto.h"

using namespace std;
class Principal{
	fstream departamento,producto;
	ListDinSimple<Departamento> tienda;
	
	string cadena;
	char *auxCadena;

	public:
		void Main();
		void separarDepa();
		void separarProd();
		void imprimirListado();
		
		void consultarOrActualizarProducto(bool b);
		void eliminarProducto();
		void agregarProducto();
		void agregarDepartamento();
		void eliminarDepartamento();
		void consultarDepartamento();
		
		void ActualizarArchivo();
		
		void mostrarMensajeError();
};

void Principal::Main(){
	char tecla;
	bool band = true;
	bool bandAux = false;
	do{
		cout<<"/------------------------Tienda------------------------/"<<endl<<endl;
		cout<<"1) Crear Sistema de la Tienda."<<endl;	
		cout<<"2) Consultar los datos de un Producto."<<endl;
		cout<<"3) Actualizar el precio de un Producto."<<endl;
		cout<<"4) Eliminar un Producto."<<endl;
		cout<<"5) Agregar Nuevo Producto."<<endl;
		cout<<"6) Agregar Nuevo Departamento."<<endl;
		cout<<"7) Eliminar Departamento."<<endl;
		cout<<"8) Consultar Departamento."<<endl;
		cout<<"9) Imprimir el Catalogo de Productos de toda la Tienda por Departamentos."<<endl;
		cout<<"f) Salir."; //Si se registro algun Cambio o actualizacion entonces debera actualizar la data en los Archivos
		tecla=getch();
		switch(tecla){
			case '1':
				bandAux = true;
				system("cls");
				Principal::separarDepa();
				Principal::separarProd();
				cout<<endl<<endl<<"Sistema Creado Sastifactoriamente!"<<endl<<endl;
				system("PAUSE");
				system("cls");
				break;
			case '2':
				if(bandAux){
					system("cls");
					Principal::consultarOrActualizarProducto(false);
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '3':
				if(bandAux){
					system("cls");
					Principal::consultarOrActualizarProducto(true);
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '4':
				if(bandAux){
					system("cls");
					Principal::eliminarProducto();
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '5':
				if(bandAux){
					system("cls");
					Principal::agregarProducto();
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '6':
				if(bandAux){
					system("cls");
					Principal::agregarDepartamento();
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '7':
				if(bandAux){
					system("cls");
					Principal::eliminarDepartamento();
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '8':
				if(bandAux){
					system("cls");
					Principal::consultarDepartamento();
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case '9':
				if(bandAux){
					system("cls");
					cout<<"Catalogo de Productos de Toda la Tienda"<<endl<<endl;
					Principal::imprimirListado();
					system("PAUSE");
					system("cls");
				}else {
					Principal::mostrarMensajeError();
				}
				break;
			case 'f':
				system("cls");
				cout<<"Fin del Programa."<<endl<<endl;
				Principal::ActualizarArchivo();
				band = false;
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

void Principal::separarDepa(){
	char nombreDepa[40] = "Departamento.txt";

	departamento.open(nombreDepa,ios::in);
		if(departamento.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(departamento,cadena)){
				auxCadena = strtok(&cadena[0],",");
				int auxNumero = atoi(auxCadena);
				
				auxCadena = strtok(NULL,"\n");
				char auxNombre[30];
				strcpy(auxNombre,auxCadena);
				
				Departamento depa(auxNumero,auxNombre);
				tienda.agregar(depa);
			}
		}
	departamento.close();
	
//	tienda.Imprimir();
}
 
void Principal::separarProd(){
	char nombrePro[40]="Productos.txt";
	int auxCodigo;
	char w[1]="";
	
	producto.open(nombrePro,ios::in);
		if(producto.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(producto,cadena)){
				auxCadena = strtok(&cadena[0],",");
				int auxNumero = atoi(auxCadena);
				
				auxCadena = strtok(NULL,",");
				char auxNombre[30];
				strcpy(auxNombre,auxCadena);
				
				auxCadena = strtok(NULL,"\n");
				float auxPrecio = atof(auxCadena);
				
				Producto pr(auxNumero,auxNombre,auxPrecio);
				auxCodigo = auxNumero/100;
				Departamento buscar(auxCodigo,w);
					if(tienda.buscar(buscar)==1){
						buscar.agregarProducto(pr);
					}
			}
		}
	producto.close();
}

void Principal::imprimirListado(){
	Nodo<Departamento> *Depa;
	Depa=tienda.getCab();
	cout<<"Listado de Tienda."<<endl<<endl;
		while(Depa!=NULL){
			Depa->getInfo().imprimir(true);
			Depa=Depa->getSig();
		}
}

void Principal::consultarOrActualizarProducto(bool b){
	string aux;
	char w[1]="";
	float precio = 0.0;
	int cont = 0,codigo,auxCodigo;
	Producto Copia;
	if(b){
		cout<<"Ingrese Codigo del Producto a Actualizar: ";
		cin>>aux;
	}else{
		cout<<"Ingrese Codigo del Producto a Consular: ";
		cin>>aux;
	}
	
	for(int i=0;i<aux.length();i++) cont++;

	if(cont==4){
		if(b){
			cout<<"Ingrese el Precio a actualizar: ";
			cin>>precio;
		}
		codigo = atoi(aux.c_str());
		auxCodigo = codigo/100;
		Departamento consultar(auxCodigo,w);
		Producto dato(codigo,w,0.0);
			if(tienda.buscar(consultar)==1){
				if(consultar.buscarProducto(dato)==1){
					if(b){
						Copia = dato;
						Copia.setPrecio(precio);
						consultar.eliminarProducto(dato);
						consultar.agregarProducto(Copia);
					}else cout<<dato<<endl;
				}else cout<<endl<<"Producto no Encontrado."<<endl<<endl;
			}else cout<<endl<<"Departamento no Encontrado."<<endl<<endl;
	}else{
		system("cls");
		cout<<"Ingrese un Codigo de 4 Digitos!"<<endl<<endl;
	}
}

void Principal::eliminarProducto(){
	string aux;
	float precio = 0.0;
	int cont = 0,codigo,auxCodigo;
	char w[1]="";
	
	cout<<"Ingrese Codigo del Producto a Eliminar: ";
	cin>>aux;
	
	for(int i=0;i<aux.length();i++) cont++;

	if(cont==4){
		codigo = atoi(aux.c_str());
		auxCodigo = codigo/100;
		Departamento consultar(auxCodigo,w);
		Producto dato(codigo,w,0.0);
			if(tienda.buscar(consultar)==1){
				if(consultar.buscarProducto(dato)==1){
					consultar.eliminarProducto(dato);
					cout<<endl<<"Se Elimino Sastifactoriamente."<<endl<<endl;
				}else cout<<endl<<"Producto no Encontrado."<<endl<<endl;
			}else cout<<endl<<"Departamento no Encontrado."<<endl<<endl;
	}else{
		system("cls");
		cout<<"Ingrese un Codigo de 4 Digitos!"<<endl<<endl;
	}
}

void Principal::agregarProducto(){
	int codigo,cont = 0,auxCodigo;
	string aux;
	char nombre[40];
	char nombreDep[40];
	float precio;
	char w[1]="";
	
	cout<<"Ingrese Codigo del Producto: ";
	cin>>aux;
	cout<<endl<<"Ingrese Nombre del Prducto: ";
	cin>>nombre;
	cout<<endl<<"Ingrese Precio del Producto: ";
	cin>>precio;
	
	for(int i=0;i<aux.length();i++) cont++;

	if(cont==4){
		codigo = atoi(aux.c_str());
		auxCodigo = codigo/100;
		Departamento consultar(auxCodigo,w);
		Producto dato(codigo,w,0.0);
			if(tienda.buscar(consultar)==1){
				if(consultar.buscarProducto(dato)==1){
					consultar.agregarProducto(dato);
					cout<<endl<<"Se Agrego Sastifactoriamente."<<endl<<endl;
				}else{

				}
			}else{
				cout<<endl<<"Ingrese Nombre del Departamento: ";
				cin>>nombreDep;
				Departamento consultarAux(auxCodigo,nombreDep);
				tienda.agregar(consultarAux);
					if(tienda.buscar(consultarAux)==1){
						Producto prAux(codigo,nombre,precio);
						if(consultarAux.buscarProducto(prAux)!=1) consultarAux.agregarProducto(prAux);
					}
				cout<<endl<<"Departamento Creado Sastifactoriamente."<<endl;
			}
	}else{
		system("cls");
		cout<<"Ingrese un Codigo de 4 Digitos!"<<endl<<endl;
	}
}

void Principal::agregarDepartamento(){
	int codigo,cont = 0,auxCodigo;
	string aux;
	char nombreDep[40];
	char w[1]="";
		
	cout<<"Ingrese Codigo del Producto: ";
	cin>>aux;
	
	for(int i=0;i<aux.length();i++) cont++;

	if(cont==4){
		codigo = atoi(aux.c_str());
		auxCodigo = codigo/100;
		Departamento consultar(auxCodigo,w);
		Producto dato(codigo,w,0.0);
			if(tienda.buscar(consultar)!=1){
				cout<<endl<<"Ingrese Nombre del Departamento: ";
				cin>>nombreDep;
				Departamento consultarAux(auxCodigo,nombreDep);
				tienda.agregar(consultarAux);
				cout<<endl<<"Departamento Creado Sastifactoriamente."<<endl;
			}else{
				cout<<endl<<"Departamento Existente."<<endl;
			}
	}else{
		system("cls");
		cout<<"Ingrese un Codigo de 4 Digitos!"<<endl<<endl;
	}
}
void Principal::eliminarDepartamento(){
	int codigo;
	char w[1]="";
	
	cout<<"Ingrese Codigo del Departamento a eliminar: ";
	cin>>codigo;

	Departamento consultar(codigo,w);
		if(tienda.buscar(consultar)==1){
			consultar.vaciarListaProducto();
			tienda.eliminar(consultar);
			cout<<endl<<"Se Elimino el Departamento Sastifactoriamente."<<endl<<endl;
		}else{
			cout<<endl<<"Departamento no Existente."<<endl;
		}
}

void Principal::consultarDepartamento(){
	int codigo;
	char letra;
	char w[1]="";
	
	cout<<"Ingrese Codigo del Departamento a Mostrar: ";
	cin>>codigo;

	Departamento consultar(codigo,w);
		if(tienda.buscar(consultar)==1){
			cout<<"Mostrar los Productos? s/n";
			cin>>letra;
			if(letra == 's' || letra == 'S'){
				consultar.imprimir(true);
			}else consultar.imprimir(false);
		}else{
			cout<<endl<<"Departamento no Existente."<<endl;
		}
}

void Principal::ActualizarArchivo(){
	
}
void Principal::mostrarMensajeError(){
	system("cls");
	cout<<"Error - Debes Crear el Sistema."<<endl<<endl;
	system("PAUSE");
	system("cls");
}
#endif
