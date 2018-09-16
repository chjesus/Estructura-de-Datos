#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

template<class T> class ListaDobEnlazada;

template<class T>
class Nodo {
	private:
		T valor;
		Nodo<T> *siguiente;
		Nodo<T> *anterior;
	public:
		Nodo(T v, Nodo<T> *sig = NULL, Nodo<T> *ant = NULL) :
		valor(v), siguiente(sig), anterior(ant) {}
	friend class ListaDobEnlazada<T>;
};

template<class T>
class ListaDobEnlazada {
	private:
		Nodo<T> *plista;
	public:
		ListaDobEnlazada() : plista(NULL) {}
		~ListaDobEnlazada();
		void Anadir(T v);
		void AnadirSinOrden(T v);
		void Eliminar(T &v);
		int BuscarInicio(T &v);
		int BuscarUltimo(T &v);
		bool isVacia() { return plista == NULL; }
		void Vaciar();
		void Imprimir(int);
		void ImprimirClase(int);
		void Siguiente();
		void Anterior();
		void Primero();
		void Ultimo();
		bool Actual() { return plista != NULL; }
		T ValorActual() { return plista->valor; }
};

template<class T>
ListaDobEnlazada<T>::~ListaDobEnlazada()
{
	Nodo<T> *aux;
	Primero();
	while(plista) {
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}               
}

template<class T>
void ListaDobEnlazada<T>::Vaciar(){
	Nodo<T> *aux;
	Primero();
	while(plista) {
		aux = plista;
		plista = plista->siguiente;
		delete aux;
	}   
}
template<class T>
void ListaDobEnlazada<T>::Anadir(T v)
{
	Nodo<T> *nuevo;
	
	Primero();
	if(isVacia() || plista->valor > v) {
		nuevo = new Nodo<T>(v, plista);
		if(!plista)
			plista = nuevo;
		else 
			plista->anterior = nuevo;
	} else {
		while(plista->siguiente && plista->siguiente->valor <= v)
			Siguiente();
		nuevo = new Nodo<T>(v, plista->siguiente, plista);
		plista->siguiente = nuevo;
		if(nuevo->siguiente) 
			nuevo->siguiente->anterior = nuevo;
	}
}

template<class T>
void ListaDobEnlazada<T>::AnadirSinOrden(T v)
{
	Nodo<T> *nuevo;
	
	Primero();
	if(isVacia()) {
		nuevo = new Nodo<T>(v, plista);
		if(!plista)
			plista = nuevo;
		else 
			plista->anterior = nuevo;
	} else {
		while(plista->siguiente)
			Siguiente();
		nuevo = new Nodo<T>(v, plista->siguiente, plista);
		plista->siguiente = nuevo;
		if(nuevo->siguiente) 
			nuevo->siguiente->anterior = nuevo;
	}
}
template<class T>
void ListaDobEnlazada<T>::Eliminar(T &v)
{
	Nodo<T> *pNodo,*aux;
	Primero();
	pNodo = plista;
	while(!(pNodo->valor==v) && pNodo){
		Siguiente();
		pNodo=plista;
	}
	Primero();
	if(pNodo==plista){
		if (pNodo->siguiente==NULL){
			plista=NULL;
		} else {
			cout<<"eliminar primero"<<endl;
			aux=plista;
			plista=pNodo->siguiente;
			plista->anterior=NULL;
			delete aux;
		}
	}else{
		Ultimo();
		if (pNodo==plista){
			cout<<"eliminar ultimo"<<endl;
			pNodo->anterior->siguiente=NULL;
			aux=pNodo;
			delete aux;
		} else {
			cout<<"es uno intermedio"<<endl;
			pNodo->anterior->siguiente=pNodo->siguiente;
			pNodo->siguiente->anterior=pNodo->anterior;
			aux=pNodo;
			delete aux;
		}
	}
	
}

template<class T>
int ListaDobEnlazada<T>::BuscarInicio(T &v){
	Nodo<T> *pNodo,*aux;
	Primero();
	pNodo = plista;
	while(pNodo){
		if(pNodo->valor==v){
			return 1;
		}else{
			Siguiente();
			pNodo=plista;
		}
	}
	return 0;
}

template<class T>
int ListaDobEnlazada<T>::BuscarUltimo(T &v){
	Nodo<T> *pNodo,*aux;
	Ultimo();
	pNodo = plista;
	while(pNodo){
		if(pNodo->valor==v){
			return 1;
		}else{
			Ultimo();
			pNodo=plista;
		}
	}
	return 0;
}
template<class T>
void ListaDobEnlazada<T>::Imprimir(int orden)
{
	Nodo<T> *pNodo;
	if(orden == ASCENDENTE) {
		Primero();
		pNodo = plista;
		if(!pNodo)cout<<"lista doble vacia"<<endl;
		while(pNodo) {
			cout << pNodo->valor << " ";
			pNodo = pNodo->siguiente;
		}
	} else {
		Ultimo();
		pNodo = plista;
		if(!pNodo)cout<<"lista doble vacia"<<endl;
		while(pNodo) {
			cout << pNodo->valor << " ";
			pNodo = pNodo->anterior;
		}
	}
	cout<<endl;
}

template<class T>
void ListaDobEnlazada<T>::ImprimirClase(int orden)
{
	Nodo<T> *pNodo;
	if(orden == ASCENDENTE) {
		Primero();
		pNodo = plista;
		while(pNodo) {
			pNodo->valor.imprimir();
			pNodo = pNodo->siguiente;
		}
	} else {
		Ultimo();
		pNodo = plista;
		while(pNodo) {
			pNodo->valor.imprimir();
			pNodo = pNodo->anterior;
		}
	}
	cout<<endl;
}

template<class T>
void ListaDobEnlazada<T>::Siguiente()
{
	if(plista) 
		plista = plista->siguiente;
}

template<class T>
void ListaDobEnlazada<T>::Anterior()
{
	if(plista) 
		plista = plista->anterior;
}

template<class T>
void ListaDobEnlazada<T>::Primero()
{
	while(plista && plista->anterior) 
		plista = plista->anterior;
}

template<class T>
void ListaDobEnlazada<T>::Ultimo()
{
	while(plista && plista->siguiente) 
		plista = plista->siguiente;
}
#endif
