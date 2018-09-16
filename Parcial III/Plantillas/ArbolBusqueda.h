#ifndef ARBOLBUSQUEDA_H
#define ARBOLBUSQUEDA_H
#include <iostream>
#include <cstring>
using namespace std;

template<class T> class ArbolBusqueda;

template<class T>
class NodoAB {
	public:
		NodoAB(const T dat, NodoAB<T> *izq=NULL, NodoAB<T> *der=NULL) :
		dato(dat), izquierdo(izq), derecho(der) {}
		T dato;
		NodoAB<T> *izquierdo;
		NodoAB<T> *derecho;
	friend class ArbolBusqueda<T>;
};

template<class T>
class ArbolBusqueda {
	private:
		NodoAB<T> *raiz;
		NodoAB<T> *actual;
		int contador;
		int altura;
	public:
		ArbolBusqueda() : raiz(NULL), actual(NULL) {}
		~ArbolBusqueda() { Podar(raiz); }
		void Insertar(const T dat);
		void Borrar(const T dat);
		bool Buscar(const T dat);
		bool Vacio(NodoAB<T> *r) { return r==NULL; }
		bool EsHoja(NodoAB<T> *r) { return !r->derecho && !r->izquierdo; }
		const int NumeroNodos();
		const int AlturaArbol();
		int Altura(const T dat);
		T &ValorActual() { return actual->T; }
		void Raiz() { actual = raiz; }
		void InOrden(void (*func)(T&) , NodoAB<T> *NodoAB=NULL, bool r=true);
		void PreOrden(void (*func)(T&) , NodoAB<T> *NodoAB=NULL, bool r=true);
		void PostOrden(void (*func)(T&) , NodoAB<T> *NodoAB=NULL, bool r=true);
	private:
		void Podar(NodoAB<T>* &);
		void auxContador(NodoAB<T>*);
		void auxAltura(NodoAB<T>*, int);
};

template<class T>
void ArbolBusqueda<T>::Podar(NodoAB<T>* &NodoAB) {
	if(NodoAB) {
		Podar(NodoAB->izquierdo);
		Podar(NodoAB->derecho);
		delete NodoAB;
		NodoAB = NULL;
	}
}

template<class T>
void ArbolBusqueda<T>::Insertar(const T dat) {
	NodoAB<T> *padre = NULL;
	
	actual = raiz;
	while (!Vacio(actual) && dat != actual->dato) {
		padre = actual;
		if (dat > actual->dato)
			actual = actual->derecho;
		else if (dat < actual->dato)
			actual = actual->izquierdo;
	}
	if (!Vacio(actual)) 
		return;
	if (Vacio(padre)) 
		raiz = new NodoAB<T>(dat);
	else if (dat < padre->dato) 
		padre->izquierdo = new NodoAB<T>(dat);
	else if (dat > padre->dato) 
		padre->derecho = new NodoAB<T>(dat);
}

template<class T>
void ArbolBusqueda<T>::Borrar(const T dat) {
	NodoAB<T> *padre = NULL;
	NodoAB<T> *NodoAB;
	T aux;
	
	actual = raiz;
	while (!Vacio(actual)) {
		if (dat == actual->dato) {
			if (EsHoja(actual)) {
				if (padre)
					if (padre->derecho == actual) 
						padre->derecho = NULL;
				else if (padre->izquierdo == actual) 
					padre->izquierdo = NULL;
				delete actual;
				actual = NULL;
				return;
			} else {
				padre = actual;
				if (actual->derecho) {
					NodoAB = actual->derecho;
					while (NodoAB->izquierdo) {
						padre = NodoAB;
						NodoAB = NodoAB->izquierdo;
					}
				} else {
					NodoAB = actual->izquierdo;
					while (NodoAB->derecho) {
						padre = NodoAB;
						NodoAB = NodoAB->derecho;
					}
				}
				aux = actual->dato;
				actual->dato = NodoAB->dato;
				NodoAB->dato = aux;
				actual = NodoAB;
			}
		} else {
			padre = actual;
			if (dat > actual->dato) 
				actual = actual->derecho;
			else if (dat < actual->dato) 
				actual = actual->izquierdo;
		}
	}
}

template<class T>
void ArbolBusqueda<T>::InOrden(void (*func)(T&) , NodoAB<T> *NodoAB, bool r) {
	if (r) 
		NodoAB = raiz;
	if (NodoAB->izquierdo) 
		InOrden(func, NodoAB->izquierdo, false);
	func(NodoAB->dato);
	if (NodoAB->derecho) 
		InOrden(func, NodoAB->derecho, false);
}

template<class T>
void ArbolBusqueda<T>::PreOrden(void (*func)(T&), NodoAB<T> *NodoAB, bool r) {
	if (r) 
		NodoAB = raiz;
	func(NodoAB->dato);
	if (NodoAB->izquierdo) 
		PreOrden(func, NodoAB->izquierdo, false);
	if (NodoAB->derecho)
		PreOrden(func, NodoAB->derecho, false);
}

template<class T>
void ArbolBusqueda<T>::PostOrden(void (*func)(T&), NodoAB<T> *NodoAB, bool r) {
	if (r) 
		NodoAB = raiz;
	if (NodoAB->izquierdo) 
		PostOrden(func, NodoAB->izquierdo, false);
	if (NodoAB->derecho) 
		PostOrden(func, NodoAB->derecho, false);
	func(NodoAB->dato);
}

template<class T>
bool ArbolBusqueda<T>::Buscar(const T dat) {
	actual = raiz;
	while (!Vacio(actual)) {
		if (dat == actual->T) 
			return true;
		else if (dat > actual->T) 
			actual = actual->derecho;
		else if (dat < actual->T) 
			actual = actual->izquierdo;
	}
	return false;
}

template<class T>
int ArbolBusqueda<T>::Altura(const T dat) {
	int altura = 0;
	actual = raiz;
	while (!Vacio(actual)) {
		if (dat == actual->dato) 
			return altura;
		else {
			altura++;
			if (dat > actual->dato) 
				actual = actual->derecho;
			else if (dat < actual->dato) 
				actual = actual->izquierdo;
		}
	}
	return -1;
}

template<class T>
const int ArbolBusqueda<T>::NumeroNodos() {
	contador = 0;
	
	auxContador(raiz);
	return contador;
}

template<class T>
void ArbolBusqueda<T>::auxContador(NodoAB<T> *NodoAB) {
	contador++;
	if (NodoAB->izquierdo) 
		auxContador(NodoAB->izquierdo);
	if (NodoAB->derecho)   
		auxContador(NodoAB->derecho);
}

template<class T>
const int ArbolBusqueda<T>::AlturaArbol() {
	altura = 0;
	auxAltura(raiz, 0);
	return altura;
}

template<class T>
void ArbolBusqueda<T>::auxAltura(NodoAB<T> *NodoAB, int a) {
	if (NodoAB->izquierdo) 
		auxAltura(NodoAB->izquierdo, a+1);
	if (NodoAB->derecho)   
		auxAltura(NodoAB->derecho, a+1);
	if (EsHoja(NodoAB) && a > altura) 
		altura = a;
}
#endif
