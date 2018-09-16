#ifndef GENERO_H
#define GENERO_H

#include "ListaDinSimple.h"
#include "Canciones.h"

using namespace std;
class Genero{
	char genero[30];
	ListDinSimple<Canciones> *lista;
	public:
		Genero(){}
		Genero(char *gen){
			strcpy(this->genero,gen);
			lista = new ListDinSimple<Canciones>();
		}
		int agregarCancion(Canciones x);
		int eliminarCancion(Canciones &x);
		int buscarCancion(Canciones &x);
		void vaciarListaCanciones();
		void invertListaCanciones();
		void imprimir(bool band=true);
		
		char *getGenero(){return genero;}
		
		void setGenero(char *gen) {strcpy(this->genero,gen);}
		
		bool operator<(const Genero& datos){
			return strcmpi(this->genero,datos.genero)<0;
		}
		bool operator==(const Genero& datos){
			return strcmpi(this->genero,datos.genero)==0;
		}
		friend ostream& operator<<(ostream& os, const Genero& datos){
			os<<"Genero: "<<datos.genero;
			return os;
		}
};

int Genero::agregarCancion(Canciones x){
	return lista->agregar(x);
}
int Genero::eliminarCancion(Canciones &x){
	return lista->eliminar(x);
}
int Genero::buscarCancion(Canciones &x){
	return lista->buscar(x);
}
void Genero::vaciarListaCanciones(){
	lista->Vaciar();
}
void Genero::invertListaCanciones(){
	lista->invert();
}
void Genero::imprimir(bool band){
	cout<<endl<<"Genero: "<<genero<<endl;
	if(band){
		cout<<"Canciones: "<<endl;
		lista->imprimir();
	}
}
#endif
