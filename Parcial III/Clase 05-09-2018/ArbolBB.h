#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <windows.h>
#include "Colas_dinamicas.h"

using namespace std;

template <class T>
class NodoA{
	T v;
	NodoA<T> *izq;
	NodoA<T> *der;
	public:
		NodoA(T valor, NodoA<T> *izquierda = NULL, NodoA<T> *derecha = NULL) : v(valor), izq(izquierda), der(derecha) {}	
		void setValor(T _valor) { v = _valor; }
	    void setIzquierda(NodoA<T> *p){izq = p;}
	    void setDerecha(NodoA<T> *p){der = p;}
	    T getValor(){return v;}
	    NodoA<T> *getIzquierda() {return izq;}
	    NodoA<T> *getDerecha() {return der;}
};

template <class T>
class ArbolBB{
	NodoA<T> *raiz,*p,*ant; //Nodo: inf,*izq,*der
	Colas_dinamicas<NodoA<T>*> *cola;
	int numeroNodos;
	int totalNiveles;
	int altura;
	int contIzq; //nodos Izq
	int contDer; //nodos Der
	public:
		ArbolBB(){p = raiz = NULL; cola=new Colas_dinamicas<NodoA<T>*>; numeroNodos = 0; totalNiveles = 0; contDer = 0; contIzq = 0;}
		int Agregar(T E);
		int Eliminar(T &E);
		bool Buscar(T E,NodoA<T> *pt=NULL);
		bool isVacio();
		bool Vacio(NodoA<T> *r);
		bool Hoja(NodoA<T> *r);
		NodoA<T> *getRaiz(){return raiz;}
		NodoA<T> *getIterador(){return p;} //posicion
		void reset(){p=raiz;}
		void Anchura(ArbolBB<T> &ob);
		void preOrden(NodoA<T> *pt,int nivel);
		void inOrden(NodoA<T> *pt,int nivel);
		void postOrden(NodoA<T> *pt,int nivel);
		int getSize(){return numeroNodos;}
		int nodoIzquierda(){return contIzq;}
		int nodoDerecha(){return contDer;}
		const int AlturaArbol();
		void nivel(int nivel);
		void NivelAux(NodoA<T> *nodoA,int n,int nivel);
		void Altura(NodoA<T> *nodoA, int alt);
		void contadorNodos(NodoA<T> *r);
		void desendientes(NodoA<T> *r);
		void nodosNivel(NodoA<T> *pt,int nivel,int nivelAux);
};

template <class T>
int ArbolBB<T>::Agregar(T E){
	NodoA<T> *nuevo;
	nuevo = new NodoA<T>(E);
	
	if(nuevo==NULL) return 0;
	
	if(raiz==NULL) {
		raiz=nuevo;
		//p=nuevo;
	}
	else{
		reset();
		ant=NULL;
			while(p!=NULL){
				if(E<p->getValor()){
					ant=p;
					p=p->getIzquierda();
				}else{
					ant=p;
					p=p->getDerecha();
				}
			}
		if(E<ant->getValor()) ant->setIzquierda(nuevo);
		else ant->setDerecha(nuevo);
	}
	
	numeroNodos++;
//	p = reset()
	return 1;
}

template <class T>
bool ArbolBB<T>::Buscar(T E,NodoA<T> *pt){
	if(raiz==NULL) return false;
	
	if(pt==NULL) {
		reset();  //|| p==NULL
		ant = NULL;
	}
	else p=pt;
	
	bool band=false;
	do{
		if(E==p->getValor()){
			band = true;
			E = p->getValor();	
		}else if(E<p->getValor()){
			ant = p;
			p=p->getIzquierda();
		}else{
			ant = p;
			p=p->getDerecha();
		}
	}while(!band && p);
	
	return band;
}

template <class T>
int ArbolBB<T>::Eliminar(T &E){
	if(raiz == NULL) return 0;
	
	bool band = Buscar(E);
	if(!band) return -1;
	if(raiz->getIzquierda()==NULL && raiz->getDerecha()==NULL){
		delete raiz;
		raiz=NULL;
	}else if(p->getIzquierda() == NULL && p->getDerecha() == NULL){
		if(p==ant->getIzquierda()){
			ant->setIzquierda(NULL);
		}else ant->setDerecha(NULL);
		delete p;
		reset();
	}
	/***/
	while(p){
		if(p->getValor() == E){
			E = p->getValor();
			break;
		}
		ant = p;
		if(E>p->getValor())
			p = p->getDerecha();
		else if(E<p->getValor())
			p = p->getIzquierda();
	}
	
	if(!p) return -1;
	
	if(p == ant){
		if((raiz->getDerecha() && !raiz->getIzquierda()) || (raiz->getIzquierda()&& !raiz->getDerecha())){
			raiz = raiz->getDerecha();
			p->setDerecha(NULL);
		}else if(raiz->getIzquierda() && !raiz->getDerecha()){
			raiz = raiz->getIzquierda();
			p->setIzquierda(NULL);
		}
	}
	
	if(p->getDerecha() && p->getIzquierda()){
		NodoA<T> *aux1 = p->getIzquierda();
		NodoA<T> *aux2 = NULL;
		T aux;
		while(aux1->getDerecha()){
			aux2 = aux1;
			aux1 = aux1->getDerecha(); 
		}
		aux = p->getValor();
		p->setValor(aux1->getValor());
		if(aux2)
			ant = aux2;
		else{ //Pendiente!! 
			if(ant->getDerecha() ==  p && ant->getIzquierda() == p)
				ant = p;
		}
		p = aux1;
	}
	
	if(p->getIzquierda() == NULL && p->getDerecha() == NULL){
		if(ant->getDerecha() == p)
			ant->setDerecha(NULL);
		else ant->setIzquierda(NULL);
	}else if((p->getDerecha() && !p->getIzquierda()) || (p->getIzquierda() && !p->getDerecha())){
		if(p->getDerecha() && !p->getIzquierda()){
			if(ant->getDerecha() == p){
				ant->setDerecha(p->getDerecha());
			}else{
				ant->setIzquierda(p->getDerecha());
			}
		}else if(p->getIzquierda() && !p->getDerecha()){
			if(ant->getDerecha() == p)
				ant->setDerecha(p->getIzquierda());
			else ant->setIzquierda(p->getIzquierda());
		}
	}
	
	numeroNodos--;
	delete p;
	return 1;
}

template <class T>
void ArbolBB<T>::Anchura(ArbolBB<T> &ob){
	NodoA<T> *pt = getRaiz();
	cola->Anadir(pt);
	while(!cola->isVacia()){
		pt = cola->Eliminar();
		cout<<pt->getValor()<<endl;
		if(pt->getIzquierda()) cola->Anadir(pt->getIzquierda());
		if(pt->getDerecha()) cola->Anadir(pt->getDerecha());
	}
}

template <class T>
void ArbolBB<T>::preOrden(NodoA<T> *pt,int nivel){
	if(isVacio()){
		cout<<"Arbol Vacio!";
		return;
	}
	for(int i=0;i<nivel;i++) cout<<"\t";
	
	cout<<pt->getValor()<<endl;
	
	if(pt->getIzquierda()) preOrden(pt->getIzquierda(),nivel+1);
	if(pt->getDerecha()) preOrden(pt->getDerecha(),nivel+1);
}

template <class T>
void ArbolBB<T>::inOrden(NodoA<T> *pt,int nivel){
	if(isVacio()){
		cout<<"Arbol Vacio!";
		return;
	}
	if(pt->getIzquierda()) preOrden(pt->getIzquierda(),nivel+1);
	for(int i=0;i<nivel;i++) cout<<"\t";
	
	cout<<pt->getValor()<<endl;
	
	if(pt->getDerecha()) preOrden(pt->getDerecha(),nivel+1);
}

template <class T>
void ArbolBB<T>::postOrden(NodoA<T> *pt,int nivel){
	if(isVacio()){
		cout<<"Arbol Vacio!";
		return;
	}
	if(pt->getIzquierda()) preOrden(pt->getIzquierda(),nivel+1);
	if(pt->getDerecha()) preOrden(pt->getDerecha(),nivel+1);	
	for(int i=0;i<nivel;i++) cout<<"\t";
	
	cout<<pt->getValor()<<endl;
}

template <class T>
void ArbolBB<T>::nodosNivel(NodoA<T> *pt,int nivel,int nivelAux){

	if(isVacio()){
		cout<<"Arbol Vacio!";
		return;
	}
	
	if(pt->getIzquierda()) nodosNivel(pt->getIzquierda(),nivel+1,nivelAux);
	if(pt->getDerecha()) nodosNivel(pt->getDerecha(),nivel+1,nivelAux);	
	
	if(nivel==nivelAux) cout<<pt->getValor()<<endl;

}

template <class T>
bool ArbolBB<T>::isVacio(){
	if(raiz==NULL){
		return true;
	}else return false;
}

template <class T>
bool ArbolBB<T>::Vacio(NodoA<T> *r){
	if(r==NULL){
		return true;
	}else return false;
}

template <class T>
bool ArbolBB<T>::Hoja(NodoA<T> *r){
	if(r->getIzquierda() == NULL && r->getDerecha() == NULL) return true;
	else return false;
}
template <class T>
const int ArbolBB<T>::AlturaArbol(){
	altura = 0;
	Altura(raiz,0);
	return altura;
}

template <class T>
void ArbolBB<T>::Altura(NodoA<T> *nodoA,int alt){
	if(nodoA->getIzquierda()) Altura(nodoA->getIzquierda(),alt+1);
	if(nodoA->getDerecha()) Altura(nodoA->getDerecha(),alt+1);
	if(Hoja(nodoA) && alt > altura) altura = alt;
}

template <class T>
void ArbolBB<T>::nivel(int nivel){
	NivelAux(raiz,0,nivel);
}

template <class T>
void ArbolBB<T>::NivelAux(NodoA<T> *nodoA,int n,int nivel){
	if(nodoA->getIzquierda()){
		if(n==nivel){
			cout<<nodoA->getValor()<<endl;
		}else NivelAux(nodoA->getIzquierda(),n+1,nivel);
	}
	if(nodoA->getDerecha()){
		if(n==nivel){
			cout<<nodoA->getValor()<<endl;
		}else NivelAux(nodoA->getDerecha(),n+1,nivel);
	}
	if(Hoja(nodoA) && n==nivel) cout<<nodoA->getValor()<<endl;
//	if(Hoja(nodoA) && alt > altura) altura = alt;
}

template <class T>
void ArbolBB<T>::contadorNodos(NodoA<T> *r){
	if(r->getIzquierda()){
		contIzq++;
		contadorNodos(r->getIzquierda());
	}
	if(r->getDerecha()){
		contDer++;
		contadorNodos(r->getDerecha());
	}
}

template <class T>
void ArbolBB<T>::desendientes(NodoA<T> *r){
	NodoA<T> *DesdIzq, *DesdDer;
	if(r->getIzquierda()) DesdIzq = r->getIzquierda();
	if(r->getDerecha()) DesdDer = r->getDerecha();
	
	cout<<"Descendientes de "<<r->getValor()<<" es:"<<endl;
	cout<<"Izquierda: "<<DesdIzq->getValor()<<endl;
	cout<<"Derecha: "<<DesdDer->getValor();
}

template <class T>
void gotoxy(int x,int y){
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X= x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}
#endif
