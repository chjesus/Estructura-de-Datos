#ifndef COLAS_DINAMICAS_H
#define COLAS_DINAMICAS_H
#include <iostream>
using namespace std;

template<class T> class Colas_dinamicas;
//template<class T> class ListaEnlazada;
//template<class T> class Pilas_dinamicas;

template<class T>
class nodo {
	private:
		T valor;
		nodo<T> *siguiente;
	public:
		nodo(T v, nodo<T> *sig = NULL) {
			valor = v;
			siguiente = sig;
		}
		void setValor(T val){ valor = val; }
		void setSiguiente(nodo<T> *p){ siguiente=p; }
		nodo<T> *getSiguiente(){ return siguiente; }
		T getValor(){ return valor; }
	friend class Colas_dinamicas<T>;
};

template<class T>
class Colas_dinamicas {
	private:
		nodo<T> *primero, *ultimo;
		int numNodos;
	public:
		Colas_dinamicas() : primero(NULL), ultimo(NULL), numNodos(0) {}
		~Colas_dinamicas();
		bool isVacia();
		void AnadirInicio(T);
        void AnadirFinal(T);
		void Anadir(T v);
		T Eliminar();
		T Leer();
		void Imprimir();
		int comparar(int n);
		void invert();
		void sort();
		void mezcla(Colas_dinamicas);
		void concat(Colas_dinamicas);
		void insert_sort(T a[], int size);
	//en caso de necesitar usar pilas o listas en conjunto con esta importar las librerias y declararlas como amigas y el prototipo de platnilla..
	//friend class Pilas_dinamicas <T>;
	//friend class ListaEnlazada <T>;
};

template<typename T>
void Colas_dinamicas<T>::concat(Colas_dinamicas col)
{
    nodo<T> *temp2 = col.primero;
    while (temp2) {
        AnadirFinal(temp2->getValor());
        temp2 = temp2->getSiguiente();
    }
}

template<typename T>
void Colas_dinamicas<T>::insert_sort(T a[], int size)
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
void Colas_dinamicas<T>::mezcla(Colas_dinamicas list_2)
{
    nodo<T> *temp = primero;
    nodo<T> *temp2 = list_2.primero;
 
    Colas_dinamicas intersection_list;
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
void Colas_dinamicas<T>::sort()
{
    T temp_data;
    nodo<T> *aux_node = primero;
    nodo<T> *temp = aux_node;
 
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
void Colas_dinamicas<T>::invert()
{
    nodo<T> *prev = NULL;
    nodo<T> *next = NULL;
    nodo<T> *temp = primero;
    while (temp) {
        next = temp->getSiguiente();
        temp->setSiguiente(prev);
        prev = temp;
        temp = next;
    }
    primero = prev;
}

template<class T>
bool Colas_dinamicas<T>::isVacia()
{
	nodo<T> *p = primero;
	if(!p) {
		return true;
	}		
	return false;
}

template<class T>
void Colas_dinamicas<T>::Imprimir()
{
	nodo<T> *p = primero;
	while(p){
		cout << p->getValor() <<endl;
		p = p->getSiguiente();
	} 
}

template<class T>
int Colas_dinamicas<T>::comparar(int n)
{
	nodo<T> *p = primero;
	int a;
	while(p){
		a = p->getValor();
		if(n == a){
			return 1;
		}
		p = p->getSiguiente();
	} 
}

template<class T>
Colas_dinamicas<T>::~Colas_dinamicas()
{
	while(primero)
		Leer();
	numNodos = 0;
}

template<class T>
void Colas_dinamicas<T>::Anadir(T v)
{
   nodo<T> *nuevo;
   nuevo = new nodo<T>(v);
   if(ultimo) ultimo->siguiente = nuevo;
   ultimo = nuevo;
   if(!primero) primero = nuevo;
   numNodos++;
}

template<typename T>
void Colas_dinamicas<T>::AnadirInicio(T data_)
{
    nodo<T> *new_nodo = new nodo<T> (data_);
    nodo<T> *temp = primero;
 
    if (!primero) {
        primero = new_nodo;
    } else {
        new_nodo->getSiguiente() = primero;
        primero = new_nodo;
        while (temp) {
            temp = temp->getSiguiente();
        }
    }
    numNodos++;
}
 
template<typename T>
void Colas_dinamicas<T>::AnadirFinal(T data_)
{
    nodo<T> *new_nodo = new nodo<T> (data_);
    nodo<T> *temp = primero;
 
    if (!primero) {
        primero = new_nodo;
    } else {
        while (temp->getSiguiente() != NULL) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(new_nodo);
    }
    numNodos++;
}

template<class T>
T Colas_dinamicas<T>::Eliminar()
{
   nodo<T> *Nodo;
   T v;
   Nodo = primero;
   if(!Nodo) return 0;
   primero = Nodo->siguiente;
   v = Nodo->valor;
   delete Nodo;
   numNodos--;
   if(!primero) ultimo = NULL;
   return v;
}

template<class T>
T Colas_dinamicas<T>::Leer()
{
   nodo<T> *Nodo;
   T v;
   Nodo = primero;
   if(!Nodo) return 0;
//   primero = Nodo->siguiente;
   v = Nodo->valor;
//   delete Nodo;
//   numNodos--;
//   if(!primero) ultimo = NULL;
   return v;
}
#endif
