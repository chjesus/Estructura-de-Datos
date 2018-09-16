#ifndef NODODIR_H
#define NODODIR_H

#include "NodoAdy.h"
#include "ListaDinSimple.h"


using namespace std;
class NodoDir{
		char vertice;
		ListDinSimple<NodoAdy> *ady;
	public:
		NodoDir(){}
		NodoDir(char vert, bool band=true);
		
		char getVertice(){return vertice;}
		int AgregarAdy(NodoAdy e){ady->agregar(e);}
		
		void Imprimir();
		
		Nodo<NodoAdy> *getCabecera(){return ady->getCab();}
		
		bool operator<(const NodoDir& datos){ 
			return this->vertice<datos.vertice;
		}
		bool operator==(const NodoDir& datos){
			return this->vertice==datos.vertice;
		}

};

NodoDir::NodoDir(char vert, bool band){
	this->vertice = vert;
	if(band) ady = new ListDinSimple<NodoAdy>;
}

void NodoDir::Imprimir(){
	cout<<endl<<vertice<<" Nodos Adyacentes: ";
	ady->imprimir();
}
#endif
