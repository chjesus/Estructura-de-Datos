#ifndef BICOLA_H
#define BICOLA_H
#include <iostream>
using namespace std;
template <class T>
class Nodo{
	
	T inf;
	Nodo<T> *sig, *ant;
	public:
		Nodo(T d){ inf = d; sig = NULL, ant = NULL;}
		Nodo() { sig = NULL, ant = NULL; }
		T get_inf() { return inf;}
		
		Nodo <T> *get_sig(){ return sig;}
		Nodo <T> *get_ant(){ return ant;}
		void set_inf(T d) { inf = d;}
		void set_sig (Nodo<T> *p) { sig = p;}
		void set_ant(Nodo<T> *p) { ant = p;}
		friend class Bicola<T>;
};

template <class T>
class Bicola{
	Nodo<T> *izq,*der;
	public:
		Bicola(){izq=der=NULL;}
		int Agregar(T E,bool band=true); //true->izq, false->der;
		int Eliminar(T &E,bool band=true); //true->izq, false->der;
		void imprimir(bool band=true);
};

template <class T>
int Bicola<T>::Agregar(T e,bool band){
	Nodo<T> *nue;
	nue = new Nodo<T>(e);
	if(nue==NULL) return 0;
	if(izq==NULL) izq=der=nue;
	else if(band){
		izq->set_ant(nue);
		nue->set_sig(izq);
		izq=nue;
	}else{
		der->set_sig(nue);
		nue->set_ant(der);
		der=nue;
	}
	return 1;
}

template <class T>
int Bicola<T>::Eliminar(T &E,bool band){
	Nodo<T> *p;
	if(izq==NULL) return 0;
	else if(izq==der){
		E=izq->get_inf();
		delete izq;
		izq=der=NULL;
	}else if(band){
		p=izq;
		izq=izq->get_sig();
		izq->set_ant(NULL);
		E=p->get_inf();
		delete p;
	}else{
		p=der;
		der=der->get_ant();
		der->set_sig(NULL);
		E=p->get_inf();
		delete p;
	}
	return 1;
}

template <class T>
void Bicola<T>::imprimir(bool band){
	Nodo<T> *p;
	string car;
	if(band){
		p=izq;
		car="->";
	}else{
		p=der;
		car="<-";
	}
		while(p!=NULL){
			cout<<car<<p->get_inf();
			if(band){
				p=p->get_sig(); 
				car="->";
			}else {
				p=p->get_ant(); car="<-";
			}
		}
}

#endif
