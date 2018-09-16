#include <iostream>
#include "ArbolBB.h"

using namespace std;
int main(int argc, char** argv) {
	ArbolBB<int> obj;
	
	obj.Agregar(40);
	obj.Agregar(10);
	obj.Agregar(50);
	obj.Agregar(20);
	obj.Agregar(5);
	obj.Agregar(15);
	obj.Agregar(25);
	obj.Agregar(60);
	obj.Agregar(54);
	obj.Agregar(18);
	obj.Agregar(23);
	
	obj.inOrden(obj.getRaiz(),0);
//	obj.nodosNivel(obj.getRaiz(),0,1);
////	obj.inOrden(obj.getRaiz(),0);
////	cout<<endl;
	system("PAUSE");
	cout<<endl<<endl<<endl;
////	cout<<endl<<"Tamaño: "<<obj.getSize()<<endl<<endl;
////	system("PAUSE");
////	cout<<endl<<"Anchura: "<<endl;
////	obj.Anchura(obj);
////	system("PAUSE");
////	cout<<endl<<"Altura: "<<obj.AlturaArbol()<<endl;
////	system("PAUSE");
////	obj.contadorNodos(obj.getRaiz());
////	cout<<endl<<"Nodos Izquierda: "<<obj.nodoIzquierda()<<endl;
////	cout<<endl<<"Nodos Derecha: "<<obj.nodoDerecha()<<endl; 
////	system("PAUSE");
////	cout<<endl;
//	obj.desendientes(obj.getRaiz());
	obj.nivel(1);
//	int valor = 511;
//	if(obj.Buscar(valor)) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;
//	
//	cout<<endl;
//	valor = 20;
//	if(obj.Buscar(valor)) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;
//	
//	obj.Agregar(45);
//	
//	cout<<endl;
//	valor = 23;
//	if(obj.Buscar(valor,obj.getIterador())) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;
//	
//	cout<<endl;
//	valor = 50;
//	if(obj.Buscar(valor,obj.getIterador())) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;
//	
//	cout<<endl;
//	valor = 40;
//	if(obj.Buscar(valor,obj.getIterador())) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;
	
//	cout<<endl;
//	valor = 18;
//	if(obj.Buscar(valor)) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;
//	
//	cout<<endl;	
//	valor = 5;
//	if(obj.Buscar(valor)) cout<<"Dato Existe!"<<" Dato: "<<valor;
//	else cout<<"Dato no Existe"<<" Dato: "<<valor;

//	int eliminar = 18; 
//	obj.Eliminar(eliminar);
//	eliminar = 23; 
//	obj.Eliminar(eliminar);
//	eliminar = 15; 
//	obj.Eliminar(eliminar);
//	eliminar = 25; 
//	obj.Eliminar(eliminar);
//	eliminar = 54; 
//	obj.Eliminar(eliminar);
//	eliminar = 5; 
//	obj.Eliminar(eliminar);
//	eliminar = 20; 
//	obj.Eliminar(eliminar);
//	
//	obj.inOrden(obj.getRaiz(),0);
//	system("PAUSE");
//	cout<<endl<<endl<<endl;
//	eliminar = 60; 
//	obj.Eliminar(eliminar);
//	eliminar = 18; 
//	obj.Eliminar(eliminar);
//	eliminar = 50; 
//	obj.Eliminar(eliminar);
//	eliminar = 50; 
//	obj.Eliminar(eliminar);
//	eliminar = 40; 
//	obj.Eliminar(eliminar);
	
//	eliminar = 60; 
//	obj.Eliminar(eliminar);

//	obj.inOrden(obj.getRaiz(),0);
	return 0;
}
