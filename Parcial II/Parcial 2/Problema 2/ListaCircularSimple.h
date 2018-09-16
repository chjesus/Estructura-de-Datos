#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include <iostream>
//#include "Nodo.h"

using namespace std;

template<class T> class ListaCircularSimple;

template <class T>
class Nodo {
	T dato;
	Nodo<T> *siguiente, *anterior;
	public:
		Nodo() { siguiente  = NULL; }
		Nodo(T dato) { this -> dato = dato; siguiente  = NULL; anterior = NULL; }
		void setDato(T dato) { this -> dato = dato; }
		void setSiguiente(Nodo<T> *p) { siguiente = p; }
		void setAnterior(Nodo<T> *p) { anterior = p; }
		T getDato() { return dato; }
		Nodo<T>* getSiguiente() { return siguiente; }
		Nodo<T>* getAnterior() { return anterior; }
		friend class ListaCircularSimple<T>;
};

template <class T>
class ListaCircularSimple {
	Nodo<T> *inicio, *fin, *p;
	int size;

	public:

		ListaCircularSimple() { inicio = fin = NULL; size = 0; }
	//	~ListaCircularSimple() { this->vaciar(); }
		bool isVacia() { return (inicio == NULL); }
		int agregar(T dato);
		int agregar(T dato, bool );
		int eliminar(T &);
		int eliminarDato(T );
		int Buscar(T &ele);
		void imprimir();
		void vaciar();
		void nextValor(){ inicio = inicio->getSiguiente();}
		void moverNpasos(int pasos);
		Nodo<T>* getInicio() { return inicio; }
		T getActual(){ return inicio->getDato();}
		int getSize() { return size; }
};

template <class T>
int ListaCircularSimple<T> :: agregar(T dato) {
	Nodo<T>* nuevo = new Nodo<T> (dato);

	if( !nuevo ) return 0;

	if(this->isVacia()) {
		nuevo->setSiguiente(nuevo);
		inicio = nuevo;
		fin = nuevo;
	} else {
		nuevo->setSiguiente(inicio);
		fin->setSiguiente(nuevo);
		fin = nuevo;
	}
	size++;
	return 1;
}

template <class T>
int ListaCircularSimple<T> :: agregar(T dato, bool ord) {
	Nodo<T>* nuevo = new Nodo<T> (dato);

	if( !nuevo ) return 0;

	if(this->isVacia()) {
		nuevo->setSiguiente(nuevo);
		inicio = nuevo;
		fin = nuevo;
	} else {
		if( ord ) { // asendente
			if(nuevo->getDato() < inicio->getDato()) {
				nuevo->setSiguiente(inicio);
				fin->setSiguiente(nuevo);
				inicio = nuevo;
			} else if(nuevo->getDato() > fin->getDato()) {
				nuevo->setSiguiente(inicio);
				fin->setSiguiente(nuevo);
				fin = nuevo;
			} else {
				Nodo<T> *p = inicio->getSiguiente(), *ant = inicio;

				while(true) {
					if(nuevo->getDato() <= p->getDato()) {
						nuevo->setSiguiente(p);
						ant->setSiguiente(nuevo);
						break;
					} else {
						ant = p;
						p = p->getSiguiente();
					}
				}
			}
		} else { // desendente
			if(nuevo->getDato() > inicio->getDato()) {
				nuevo->setSiguiente(inicio);
				fin->setSiguiente(nuevo);
				inicio = nuevo;
			} else if(nuevo->getDato() < fin->getDato()) {
				nuevo->setSiguiente(inicio);
				fin->setSiguiente(nuevo);
				fin = nuevo;
			} else {
				Nodo<T> *p = inicio->getSiguiente(), *ant = inicio;

				while(true) {
					if(nuevo->getDato() >= p->getDato()) {
						nuevo->setSiguiente(p);
						ant->setSiguiente(nuevo);
						break;
					} else {
						ant = p;
						p = p->getSiguiente();
					}
				}
			}
		}	
	}
	size++;
	return 1;
}

template <class T>
int ListaCircularSimple<T> :: eliminar(T &ele) {
	Nodo<T> *p;

	if(this->isVacia()) return 0;

	p = inicio;
	ele = inicio->getDato();
	inicio = inicio->getSiguiente();
	fin->setSiguiente(inicio);
	size--;
	delete p;
	return 1;
}

template <class T>
int ListaCircularSimple<T> :: eliminarDato(T ele) {
	Nodo<T> *p, *ant;

	if(this->isVacia()) return 0;

	p = inicio;
	ant = fin;
	do {
		if(p->getDato() == ele) {
			if(p == inicio) {
				inicio = inicio->getSiguiente();
				fin->setSiguiente(inicio);	
			} else {			
				ant->setSiguiente(p->getSiguiente());
				p->setSiguiente(NULL);
			}
			delete p;
			return 1;
		} else {
			ant = p;
			p = p->getSiguiente();
		}
	} while (p != inicio);
	size--;
	return 0;
}

template <class T>
int ListaCircularSimple<T>::Buscar(T &ele){
	Nodo<T> *p, *ant;

	if(isVacia()) return 0;

	p = inicio;
//	ant = fin;
	do {
		if(p->getDato() == ele) {
//			if(p == inicio) {
//				inicio = inicio->getSiguiente();
//				fin->setSiguiente(inicio);	
//			} else {			
//				ant->setSiguiente(p->getSiguiente());
//				p->setSiguiente(NULL);
//			}
			return 1;
		} else {
//			ant = p;
			p = p->getSiguiente();
		}
	} while (p != inicio);
	return 0;
}
template <class T>
void ListaCircularSimple<T> :: imprimir() {
	Nodo<T> *p = inicio;
	cout << endl << "->";

	do {
		cout << " " << p->getDato() << " ->";
		p = p->getSiguiente();
	} while(p != inicio);

}

template <class T>
void ListaCircularSimple<T>::moverNpasos(int pasos){
	for(int i=0;i<pasos;i++){
		inicio = inicio->getSiguiente();
	}
}
template <class T>
void ListaCircularSimple<T> :: vaciar() {
	Nodo<T> *p = inicio;
	int i = 0;

	while(i < size) {
		inicio = inicio->getSiguiente();
		fin->setSiguiente(inicio);
		delete p;
		//imprimir();
		p = inicio;
		i++;
	}
	inicio = fin = NULL;
	size = 0;
}
#endif
