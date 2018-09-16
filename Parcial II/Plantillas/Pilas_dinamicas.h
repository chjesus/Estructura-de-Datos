#ifndef PILAS_DINAMICAS_H
#define PILAS_DINAMICAS_H
#include <iostream>
using namespace std;

template<class T> class Pilas_dinamicas;
//template<class T> class ListaEnlazada;
//template<class T> class Colas_dinamicas;

template<class T>
class NodoP {
	private:
		T valor;
		NodoP<T> *siguiente;
	public:
		NodoP(T v, NodoP<T> *sig = NULL) : valor(v), siguiente(sig) {}
		
		void setValor(T val){ valor=val; }
		void setSiguiente(NodoP<T> *p){ siguiente=p; }
		T getValor(){ return valor; }
		NodoP<T> *getSiguiente(){ return siguiente; }
	friend class Pilas_dinamicas<T>;
};

template<class T>
class Pilas_dinamicas {
	private:
		NodoP<T> *ultimo;
		int numNodos;
	public:
		Pilas_dinamicas() {	ultimo = NULL; numNodos = 0; }
		~Pilas_dinamicas();
		bool isVacia();
		void AnadirInicio(T);
        void AnadirFinal(T);
		void Anadir(T v);
		T Eliminar();
		T Leer();
		void Vaciar();
		int Buscar(T &E);
		void Imprimir();
		void invert();
		void sort();
		void mezcla(Pilas_dinamicas);
		void concat(Pilas_dinamicas);
		void insert_sort(T a[], int size);
//	friend class ListaEnlazada<T>;
//	friend class Colas_dinamicas<T>;
};

template<typename T>
void Pilas_dinamicas<T>::concat(Pilas_dinamicas pil)
{
    NodoP<T> *temp2 = pil.ultimo;
    while (temp2) {
        AnadirFinal(temp2->getValor());
        temp2 = temp2->getSiguiente();
    }
}

template<typename T>
void Pilas_dinamicas<T>::insert_sort(T a[], int size)
{
    T temp;
    for (int i = 0; i < size; i++) {
        for (int j = i-1; j>= 0 && a[j+1] < a[j]; j--) {
            temp = a[j+1];
            a[j+1] = a[j];
            a[j] = temp;
        }
    }
}
 
template<typename T>
void Pilas_dinamicas<T>::mezcla(Pilas_dinamicas list_2)
{
    NodoP<T> *temp = ultimo;
    NodoP<T> *temp2 = list_2.ultimo;
 
    Pilas_dinamicas intersection_list;
    int numNodos2 = list_2.numNodos;
    int num_inter = 0;
    T *v1 = new T[numNodos];
    T *v2 = new T[numNodos2];
    int i = 0;
    while (temp) {
        v1[i] = temp->getValor();
        temp = temp->getSiguiente();
        i++;
    }
    int j = 0;
    while (temp2) {
        v2[j] = temp2->getValor();
        temp2 = temp2->getSiguiente();
        j++;
    }
    // Ordeno los vectores
//    insert_sort(v1, numNodos);
//    insert_sort(v2, numNodos2);
    int v1_i = 0;
    int v2_i = 0;
    int k;
	for(k = 0;(v1_i < numNodos) && (v2_i < numNodos2); k++) {
		intersection_list.Anadir(v1[v1_i]);
		v1_i++;
		intersection_list.Anadir(v2[v2_i]);
		v2_i++;
	}
	while (v1_i < numNodos) {
		intersection_list.Anadir(v1[v1_i]);
		v1_i++;
	}
	while (v2_i < numNodos2) {
		intersection_list.Anadir(v2[v2_i]);
		v2_i++;
	}
 
	intersection_list.Imprimir();
}

template<typename T>
void Pilas_dinamicas<T>::sort()
{
    T temp_data;
    NodoP<T> *aux_node = ultimo;
    NodoP<T> *temp = aux_node;
 
    while (aux_node) {
        temp = aux_node;
        while (temp->getSiguiente()) {
            temp = temp->getSiguiente();
            if (aux_node->getValor() > temp->getValor()) {
                temp_data = aux_node->getValor();
                aux_node->setValor(temp->getValor());
                temp->setValor(temp_data);
            }
        }
        aux_node = aux_node->getSiguiente();
    }
}

template<typename T>
void Pilas_dinamicas<T>::invert()
{
    NodoP<T> *prev = NULL;
    NodoP<T> *next = NULL;
    NodoP<T> *temp = ultimo;
 
    while (temp) {
        next = temp->getSiguiente();
        temp->setSiguiente(prev);
        prev = temp;
        temp = next;
    }
    ultimo = prev;
}

template<class T>
bool Pilas_dinamicas<T>::isVacia()
{
	NodoP<T> *p = ultimo;
	if(!p){
		return true;
	}
	return false;
}

template<class T>
Pilas_dinamicas<T>::~Pilas_dinamicas()
{
   while(ultimo) Eliminar();
   numNodos = 0;
}

template<class T>
void Pilas_dinamicas<T>::Vaciar(){
	while(ultimo) Eliminar();
   numNodos = 0;
}
template<class T>
void Pilas_dinamicas<T>::Anadir(T v)
{
   NodoP<T> *nuevo;
   nuevo = new NodoP<T>(v, ultimo);
   ultimo = nuevo;
   numNodos++;
}

template<typename T>
void Pilas_dinamicas<T>::AnadirFinal(T data_)
{
    NodoP<T> *new_nodo = new NodoP<T> (data_);
    NodoP<T> *temp = ultimo;
 
    if (!ultimo) {
        ultimo = new_nodo;
    } else {
        new_nodo->setSiguiente(ultimo);
        ultimo = new_nodo;
        while (temp) {
            temp = temp->getSiguiente();
        }
    }
    numNodos++;
}
 
template<typename T>
void Pilas_dinamicas<T>::AnadirInicio(T data_)
{
    NodoP<T> *new_nodo = new NodoP<T> (data_);
    NodoP<T> *temp = ultimo;
 
    if (!ultimo) {
        ultimo = new_nodo;
    } else {
        while (temp->getSiguiente() != NULL) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(new_nodo);
    }
    numNodos++;
}

template<class T>
T Pilas_dinamicas<T>::Eliminar()
{
    NodoP<T> *_Nodo;
    T v;
    if(!ultimo) return v;
    _Nodo = ultimo;
    ultimo = _Nodo->siguiente;
    v = _Nodo->valor;
    delete _Nodo;
    numNodos--;
    return v;
}

template<class T>
T Pilas_dinamicas<T>::Leer(){
	
	NodoP<T> *_Nodo;
    T v;
    if(!ultimo) return v;
    _Nodo = ultimo;
    v = _Nodo->valor;
    return v;
}

template<class T>
int Pilas_dinamicas<T>::Buscar(T &E){
	NodoP<T> *_Nodo = ultimo;
	while(_Nodo){
		if(_Nodo->getValor()==E){
			E = _Nodo->getValor();
			return 1;
		}
		else{
			_Nodo = _Nodo->getSiguiente();
		}
	}
	return 0;
	
}

template <class T>
void Pilas_dinamicas<T>::Imprimir(){
	NodoP<T> *p = ultimo;
	while(p){
		cout<<p->getValor()<<" ";
		p=p->getSiguiente();
	}
}
#endif
