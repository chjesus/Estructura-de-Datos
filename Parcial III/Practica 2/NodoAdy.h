#ifndef NODOADY_H
#define NODOADY_H

#include "ListaDinSimple.h"

using namespace std;
class NodoAdy{
		char vertice;
		float peso;
	public:
		NodoAdy(){}
		NodoAdy(char vert,float p=1);
		
		float getValor(){return peso;}
		char getVertice(){return vertice;}
		
		bool operator<(const NodoAdy& datos){ 
			return this->vertice<datos.vertice;
		}
		bool operator==(const NodoAdy& datos){
			return this->vertice==datos.vertice;
		}
		void Imprimir() { cout<<"["<< vertice << "] Peso:"<<peso<<" - "; }
//		friend ostream& operator<<(ostream& os, const NodoAdy& datos){  
//	    	os<<"["<<datos.vertice<<" ] Peso: "<<datos.peso<<" - "<<endl;
//		    return os;  
//		}
};

NodoAdy::NodoAdy(char vert,float p){
	this->vertice = vert;
	this->peso = p;
}
#endif
