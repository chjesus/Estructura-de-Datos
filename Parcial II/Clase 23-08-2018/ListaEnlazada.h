#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
using namespace std;

template<class T> class ListaEnlazada;
//template<class T> class Pilas_dinamicas;
//template<class T> class Colas_dinamicas;

template<class T>
class Nodo {
	private:
		T valor;
		Nodo<T> *siguiente;
	public:
		Nodo() { siguiente = NULL; }
		Nodo(T _valor) { valor = _valor; siguiente = NULL; }
		void setValor(T _valor) { valor = _valor; }
		void setSiguiente(Nodo<T> *p) { siguiente = p; }
		T getValor() { return valor; }
		Nodo<T> *getSiguiente() { return siguiente;	}
	friend class ListaEnlazada<T>;
};


template<class T>
class ListaEnlazada {
	
	Nodo<T> *inicio;
	int numNodos;
	public:
		ListaEnlazada() { inicio = NULL; numNodos = 0; }
		~ListaEnlazada();
		void AnadirInicio(T);
        void AnadirFinal(T);
		int Anadir(T valor);
		int Eliminar(T &valor);
		bool isVacia();
		void Imprimir();
		int Comparar(int n);
		void invert();
		void sort();
		void mezcla(ListaEnlazada);
		void concat(ListaEnlazada);
		void insert_sort(T a[], int size);
//	friend class Pilas_dinamicas<T>;
//	friend class Colas_dinamicas<T>;
};

template<typename T>
void ListaEnlazada<T>::concat(ListaEnlazada list)
{
    Nodo<T> *temp2 = list.inicio;
    while (temp2) {
        AnadirFinal(temp2->getValor());
        temp2 = temp2->getSiguiente();
    }
}

template<typename T>
void ListaEnlazada<T>::insert_sort(T a[], int size)
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
void ListaEnlazada<T>::mezcla(ListaEnlazada list_2)
{
    Nodo<T> *temp = inicio;
    Nodo<T> *temp2 = list_2.inicio;
 
    ListaEnlazada intersection_list;
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
void ListaEnlazada<T>::sort()
{
    T temp_data;
    Nodo<T> *aux_node = inicio;
    Nodo<T> *temp = aux_node;
 
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
void ListaEnlazada<T>::invert()
{
    Nodo<T> *prev = NULL;
    Nodo<T> *next = NULL;
    Nodo<T> *temp = inicio;
 
    while (temp) {
        next = temp->getSiguiente();
        temp->setSiguiente(prev);
        prev = temp;
        temp = next;
    }
    inicio = prev;
}

template<class T>
bool ListaEnlazada<T>::isVacia()
{
	Nodo<T> *p = inicio;
	if(!p){
		return true;
	}
	return false;
}

template<class T>
ListaEnlazada<T>::~ListaEnlazada()
{
	while(inicio) {
		inicio = inicio->getSiguiente();
		delete inicio;
		if(inicio == NULL)
			break;
	}
	numNodos = 0;
	delete inicio;
}

template<class T>
int ListaEnlazada<T>::Eliminar(T &valor) {
	Nodo<T> *ant, *p;
	if(inicio == NULL)
		return -1;
	ant = NULL; p = inicio;
	while(p) {
		if(p->getValor().getClave() == valor.getClave())
			break;
		else {
			ant = p;
			p = p->getSiguiente();
		}
	}
	if(!p) {
		valor = p->getValor();
		numNodos--; // OJO T_T
		return -1;
	}
	if(p == inicio)
		inicio = inicio->getSiguiente();
	else
		ant->setSiguiente(p->getSiguiente());
		
	p->setSiguiente(NULL);
	delete p;
	return 1;
}

template<class T>
int ListaEnlazada<T>::Anadir(T valor)
{
	Nodo<T>*Nuevo, *p, *Anterior;
	Nuevo = new Nodo<T>(valor);
	p = inicio;
	if(Nuevo == NULL)
		return 0;
	Anterior = NULL;
	while(p) {
		if(Nuevo->getValor() < p->getValor()) //sobrecargar V:
			break;
		else {
			Anterior = p;
			p = p->getSiguiente();
		}
	}
	if(p == inicio) {
		Nuevo->setSiguiente(inicio);
		inicio = Nuevo;
	} else {
		Nuevo->setSiguiente(p);
		Anterior->setSiguiente(Nuevo);
	}
	numNodos++;
	return 1;
}

template<typename T>
void ListaEnlazada<T>::AnadirInicio(T data_)
{
    Nodo<T> *new_nodo = new Nodo<T> (data_);
    Nodo<T> *temp = inicio;
 
    if (!inicio) {
        inicio = new_nodo;
    } else {
        new_nodo->getSiguiente() = inicio;
        inicio = new_nodo;
        while (temp) {
            temp = temp->getSiguiente();
        }
    }
    numNodos++;
}
 
template<typename T>
void ListaEnlazada<T>::AnadirFinal(T data_)
{
    Nodo<T> *new_nodo = new Nodo<T> (data_);
    Nodo<T> *temp = inicio;
 
    if (!inicio) {
        inicio = new_nodo;
    } else {
        while (temp->getSiguiente() != NULL) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(new_nodo);
    }
    numNodos++;
}

template<class T>
void ListaEnlazada<T>::Imprimir()
{
	Nodo<T> *p = inicio;
	while(p) {
		cout << p->getValor() <<endl; //sobrecargar :v
		p = p->getSiguiente();
	}
}

template<class T>
int ListaEnlazada<T>::Comparar(int n){
	Nodo<T> *p = inicio;
	int a;
	while(p) {
		a = p->getValor().getClave(); 
		if(n == a){
			return 1;
		}
		p = p->getSiguiente();
	}
	return -1;
}
#endif
