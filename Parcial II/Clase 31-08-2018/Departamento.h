#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include "ListaDinSimple.h"
#include "Producto.h"

using namespace std;
class Departamento{
	int codigo;
	char nombre[30];
	
	ListDinSimple<Producto> *lista;
	
	public:
		Departamento(){}
		Departamento(int cod,char *nom){
			this->codigo = cod;
			strcpy(this->nombre,nom);
			lista = new ListDinSimple<Producto>();
		}
		int agregarProducto(Producto x);
		int eliminarProducto(Producto &x);
		int buscarProducto(Producto &x);
		void vaciarListaProducto();
		void imprimir(bool band=true);
		
		int getCodigo(){return codigo;}
		char *getNombre(){return nombre;}
		
		void setCodigo(int cod){this->codigo = cod;}
		void setNombre(char *nom){strcpy(this->nombre,nom);}
		
		bool operator<(const Departamento& datos){
			return this->codigo<datos.codigo;
		}
		bool operator==(const Departamento& datos){
			return this->codigo==datos.codigo;
		}
		friend ostream& operator<<(ostream& os, const Departamento& datos){
			os<<"Codigo: "<<datos.codigo<<" Nombre: "<<datos.nombre<<endl;
			return os;
		}
};

int Departamento::agregarProducto(Producto x){
	return lista->agregar(x);
}
int Departamento::eliminarProducto(Producto &x){
	return lista->eliminar(x);
}
int Departamento::buscarProducto(Producto &x){
	return lista->buscar(x);
}
void Departamento::vaciarListaProducto(){
	lista->Vaciar();
}
void Departamento::imprimir(bool band){
	cout<<"Codigo del Departamento: "<<codigo<<endl;
	cout<<"Nombre del Departamento: "<<nombre<<endl;
		if(band){
			cout<<endl<<"Productos del Departamento: "<<endl<<endl;
			lista->imprimir();
		}
}
#endif
