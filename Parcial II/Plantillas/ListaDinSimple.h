#ifndef LISTDINSIMPLE_H
#define LISTDINSIMPLE_H
#include <iostream>
//#include "Nodo.h"
using namespace std;

template <class T>
class Nodo{
	T inf;
	Nodo<T> *sig;
	public:
		Nodo(){sig = NULL;}
		Nodo(T d){inf = d; sig = NULL;}	
		T getInfo(){return inf;}
		Nodo<T> *getSig(){return sig;}
		void setInf(T d){inf = d;}
		void setSig(Nodo<T> *p){sig = p;}
};

template <class T>
class ListDinSimple{
	Nodo<T> *cab;
	int numNodos;
	public:
		ListDinSimple(){cab = NULL; numNodos = 0;}
		int agregar(T E);
		int eliminar(T &E);
		int buscar(T &E);
		void AgregarInicio(T E);
		void AgregarFinal(T E);
		void imprimir();
		void Vaciar();
		void invert();
		void sort();
		void concat(ListDinSimple);
		int tamLista(){return numNodos;}
		bool isVacia();
		Nodo<T> *getCab(){return cab;}
};

template <class T>
bool ListDinSimple<T>::isVacia(){
	Nodo<T> *p = cab;
	if(!p){
		return true;
	}
	return false;
}

template <class T>
void ListDinSimple<T>::Vaciar(){
	while(cab){
		cab = cab->getSig();
		delete cab;
		if(cab == NULL) break;
	}
	numNodos = 0;
	delete cab;
}

template <class T>
void ListDinSimple<T>::invert(){
	Nodo<T> *prev = NULL;
	Nodo<T> *next = NULL;
	Nodo<T> *temp = cab;
	
	while(temp){
		next = temp->getSig();
		temp->setSig(prev);
		prev = temp;
		temp = next;
	}
	cab = prev;
}

template <class T>
void ListDinSimple<T>::sort(){
	T temp_data;
	Nodo<T> *aux_node = cab;
	Nodo<T> *temp = aux_node;
	
	while(aux_node){
		temp = aux_node;
		while(temp->getSig()){
			temp = temp->getSig();
			if(aux_node->getInfo() > temp->getInfo()){
				temp_data = aux_node->getInfo();
				aux_node->setInf(temp->getInfo());
				temp->setInf(temp_data);
			}
		}
		aux_node = aux_node->getSig();
	}
}

template <class T>
void ListDinSimple<T>::concat(ListDinSimple list){
	Nodo<T> *temp2 = list.cab;
	while(temp2){
		AgregarFinal(temp2->getInfo());
		temp2 = temp2->getSig();
	}
}

template <class T>
void ListDinSimple<T>::AgregarInicio(T E){
	Nodo<T> *new_nodo = new Nodo<T>(E);
	Nodo<T> *temp = cab;
	
	if(!cab){
		cab = new_nodo;
	}else{
		new_nodo->setSig(cab);
		cab = new_nodo;
			while(temp){
				temp = temp->getSig();
			}
	}
	numNodos++;
}

template <class T>
void ListDinSimple<T>::AgregarFinal(T E){
	Nodo<T> *new_nodo = new Nodo<T>(E);
	Nodo<T> *temp = cab;
	
	if(!cab){
		cab = new_nodo;
	}else{
		while(temp->getSig()!=NULL){
			temp = temp->getSig();
		}
		temp->setSig(new_nodo);
	}
	numNodos++;
}

template <class T>
int ListDinSimple<T>::buscar(T &E){
	if(cab==NULL){
		return 0;
	}
	Nodo<T> *p = cab, *ant;
	
	while(p!=NULL){
		if(p->getInfo()==E){
			break;
		}
		ant = p;
		p = p->getSig();
	}
	
	if(p==NULL){
		return -1;
	}
	
	E = p->getInfo();
	return 1;
}

template <class T>
int ListDinSimple<T>::eliminar(T &E){
	
	if(cab==NULL){
		return 0;
	}
	Nodo<T> *p=cab, *ant;
	
	while(p!=NULL){
		if(p->getInfo()==E){
			break;
		}
		ant = p;
		p = p->getSig();
	}
	
	if(p==NULL){
		return -1;
	}
	if(p==cab){
		cab = cab->getSig();
	}
	else{
		ant->setSig(p->getSig());
	}
	
	numNodos--;
	E = p->getInfo();
	delete p;
	return 1;
}

template <class T>
int ListDinSimple<T>::agregar(T E){
	
	Nodo<T> *nue, *p, *ant;
	nue = new Nodo<T>(E);
	if(nue == NULL)
		return 0;
		
	if(cab==NULL)
		cab = nue;
	else{
		ant = NULL;
		p = cab;
		while(p!=NULL){
			if(E < p->getInfo()){
				break;
			}
			else{
				ant = p;
				p = p->getSig();
			}		
		}
		if(p==cab){//caso: ins en cabecera
			cab = nue;
		}
		else{
			ant->setSig(nue);
		}
		nue->setSig(p);
	}	
	numNodos++;
	return 1;
}

template <class T>
void ListDinSimple<T>::imprimir(){
	Nodo<T> *p = cab;
	while(p){
		cout<< p->getInfo()<<endl;
		p = p->getSig();
	}
}
#endif
