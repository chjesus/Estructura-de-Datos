#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include <conio.h>
#include <windows.h>

#define IZQUIERDO 0
#define DERECHO 1

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

template<class T> class ArbolAVL;

template<class T>
class NodoAVL {
		T dato;
		NodoAVL<T> *izquierdo;
		NodoAVL<T> *derecho;
		NodoAVL<T> *padre;
	public:
		NodoAVL(const T dat, NodoAVL<T> *pad = NULL, NodoAVL<T> *izq = NULL, NodoAVL<T> *der = NULL) :
			dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}
		int FE;
		void setValor(T v) { dato = v; }
		void setDerecho(NodoAVL<T> *p) { derecho = p; }
		void setIzquierdo(NodoAVL<T> *p) { izquierdo = p; }
		void setPadre(NodoAVL<T> *p) { padre = p; }
		T getValor() { return dato; }
		NodoAVL<T> *getDerecho() { return derecho; }
		NodoAVL<T> *getIzquierdo() { return izquierdo; }
		NodoAVL<T> *getPadre() { return padre; }
		friend class ArbolAVL<T>;
};

template<class T>
class ArbolAVL {
	private:
		int contador;
		int altura;
		NodoAVL<T> *raiz;
		NodoAVL<T> *actual;
		int clave;
		void Equilibrar(NodoAVL<T> *nodo, int, bool);
		void RSI(NodoAVL<T>* nodo);
		void RSD(NodoAVL<T>* nodo);
		void RCI(NodoAVL<T>* nodo);
		void RCD(NodoAVL<T>* nodo);
		
		void Podar(NodoAVL<T>* &);
		void auxContador(NodoAVL<T>*);
		void auxAltura(NodoAVL<T>*, int);
	public:
		ArbolAVL() : raiz(NULL), actual(NULL) {}
		~ArbolAVL() { Podar(raiz); }
		int Anadir(T dat);
		void Borrar(const T dat);
		bool Buscar(T dat);
		bool Vacio(NodoAVL<T> *r) { return r==NULL; }
		bool EsHoja(NodoAVL<T> *r) { return !r->getDerecho() && !r->getIzquierdo(); }
		const int NumeroNodos();
		const int AlturaArbol();
		int Nivel(T dat);
		T &ValorActual() { return actual->dato; }
		NodoAVL<T> *NodoActual() { return actual; }
		void Raiz() { actual = raiz; }
		void InOrden(NodoAVL<T> *nodo=NULL, bool r=true);
		void PreOrden(NodoAVL<T> *nodo=NULL, bool r=true);
		void PostOrden(NodoAVL<T> *nodo=NULL, bool r=true);
		void imprimir(int o);
		void imprimirSubArbol(NodoAVL<T> *nodo);
		void mostrar(int contador, int nivel, int factor, NodoAVL<T> *nodo=NULL);
		int SumaClaves(NodoAVL<T> *p=NULL, bool r=true);
};

template <class T>
int ArbolAVL<T>::SumaClaves(NodoAVL<T> *p, bool r)
{	
	if(r)
		clave = 0;
    if(p->getDerecho()){
        clave += p->getValor();
        SumaClaves(p->getDerecho(), false);
    }
    if(p->getIzquierdo()){
        clave += p->getValor();
        SumaClaves(p->getIzquierdo(), false);
    }
	return clave;
}



template <class T>
void ArbolAVL<T>::mostrar(int contador, int nivel, int factor, NodoAVL<T> *nodo) {
    if (!nodo) {
        nodo = raiz;
        gotoxy(contador, 2);
    }
    else {
        gotoxy(contador, nivel);
    }
   // cout << nodo->getInfo() << "(" << nivel << ")" << endl << endl;
    cout << "(" << nodo->FE << ")" << nodo->getValor() << endl;
    nivel++;

    bool validador = false;

    if (nodo && nodo->getDerecho()) {
        mostrar(contador - factor, nivel, factor / 2, nodo->getDerecho());
        validador = true;
    }

    validador = false;
    if (nodo && nodo->getIzquierdo()) {
        mostrar(contador + factor, nivel, factor / 2, nodo->getIzquierdo());
        validador = true;
    }

    if (!validador) return;
}

template<class T>
void ArbolAVL<T>::Podar(NodoAVL<T>* &nodo) {
	if(nodo) {
		Podar(nodo->izquierdo);
		Podar(nodo->derecho);
		delete nodo;
		nodo = NULL;
	}
}

template<class T>
int ArbolAVL<T>::Anadir(T dat) {
	NodoAVL<T> *padre = NULL;
	NodoAVL<T> *NuevoNodo = new NodoAVL<T>(dat);
	NodoAVL<T> *p = raiz;
	
	if (Vacio(p)) {
		raiz = NuevoNodo;
	} else {
		while (!Vacio(p)) {
			if (dat < p->getValor()) {
				if (!Vacio(p->getIzquierdo()))
					p = p->getIzquierdo();
				else {
					NuevoNodo->setPadre(p);
					p->setIzquierdo(NuevoNodo);
					actual = p;
					Equilibrar(p, IZQUIERDO, true);
					return 1;				
				}
			} else if (dat > p->getValor()) {
				if (!Vacio(p->getDerecho())) 
					p = p->getDerecho();
				else {
					NuevoNodo->setPadre(p);
					p->setDerecho(NuevoNodo);
					actual = p;
					Equilibrar(p, DERECHO, true);
					return 1;
				}				
			} else
				return 0;
		}
	}
}

template<class T>
void ArbolAVL<T>::Equilibrar(NodoAVL<T> *nodo, int rama, bool nuevo) {
	bool salir = false;

	while (nodo && !salir) {
		if (nuevo)
			if (rama == IZQUIERDO)
				nodo->FE--;
			else
				nodo->FE++;
		else if (rama == IZQUIERDO)
			nodo->FE++;
		else
		    nodo->FE--;
		if (nodo->FE == 0)
			salir = true;
		else if (nodo->FE == -2) {
			if (nodo->getIzquierdo()->FE == 1) 
				RCD(nodo);
			else 
				RSD(nodo);
			salir = true;
		} else if (nodo->FE == 2) {
			if (nodo->getDerecho()->FE == -1) 
				RCI(nodo);
			else 
				RSI(nodo);
			salir = true;
		}
		if (nodo->getPadre())
			if (nodo->getPadre()->getDerecho() == nodo)
				rama = DERECHO;
			else 
				rama = IZQUIERDO;
		nodo = nodo->getPadre();
	}
}

template<class T>
void ArbolAVL<T>::RCD(NodoAVL<T>* nodo) {
//	cout << "RCD" << endl;
	NodoAVL<T> *Padre = nodo->getPadre();
	NodoAVL<T> *P = nodo;
	NodoAVL<T> *Q = P->getIzquierdo();
	NodoAVL<T> *R = Q->getDerecho();
	NodoAVL<T> *B = R->getIzquierdo();
	NodoAVL<T> *C = R->getDerecho();

	if (Padre)
		if (Padre->getDerecho() == nodo) 
			Padre->setDerecho(R);
		else 
			Padre->setIzquierdo(R);
	else 
		raiz = R;

	Q->setDerecho(B);
	P->setIzquierdo(C);
	R->setIzquierdo(Q);
	R->setDerecho(P);

	R->setPadre(Padre);
	P->setPadre(R);
	Q->setPadre(R);
	if(B)
		B->setPadre(Q);
	if(C)
		C->setPadre(P);

	switch(R->FE) {
		case -1: Q->FE = 0;  P->FE = 1; break;
		case 0:  Q->FE = 0;  P->FE = 0; break;
		case 1:  Q->FE = -1; P->FE = 0; break;
	}
	R->FE = 0;
}

template<class T>
void ArbolAVL<T>::RCI(NodoAVL<T>* nodo) {
//	cout << "RCI" << endl;
	NodoAVL<T> *Padre = nodo->getPadre();
	NodoAVL<T> *P = nodo;
	NodoAVL<T> *Q = P->getDerecho();
	NodoAVL<T> *R = Q->getIzquierdo();
	NodoAVL<T> *B = R->getIzquierdo();
	NodoAVL<T> *C = R->getDerecho();
	
	if (Padre) 
		if(Padre->getDerecho() == nodo) 
			Padre->setDerecho(R);
	else 
		Padre->setIzquierdo(R);
	else 
		raiz = R;
	
	P->setDerecho(B);
	Q->setIzquierdo(C);
	R->setIzquierdo(P);
	R->setDerecho(Q);
	
	R->setPadre(Padre);
	P->setPadre(R);
	Q->setPadre(R);
	
	if (B) 
		B->setPadre(P);
	if (C) 
		C->setPadre(Q);

	switch(R->FE) {
		case -1: P->FE =  0; Q->FE = 1; break;
		case 0:  P->FE =  0; Q->FE = 0; break;
		case 1:  P->FE = -1; Q->FE = 0; break;
	}
	R->FE = 0;
}

template<class T>
void ArbolAVL<T>::RSD(NodoAVL<T>* nodo) {
//	cout << "RSD" << endl;
	NodoAVL<T> *Padre = nodo->getPadre();
	NodoAVL<T> *P = nodo;
	NodoAVL<T> *Q = P->getIzquierdo();
	NodoAVL<T> *B = Q->getDerecho();

	if (Padre)
		if (Padre->getDerecho() == P)
			Padre->setDerecho(Q);
		else 
			Padre->setIzquierdo(Q);
	else 
		raiz = Q;

	P->setIzquierdo(B);
	Q->setDerecho(P);

	P->setPadre(Q);
	if (B) 
		B->setPadre(P);
	Q->setPadre(Padre);

	P->FE = 0;
	Q->FE = 0;
}

template<class T>
void ArbolAVL<T>::RSI(NodoAVL<T>* nodo) {
//	cout << "RSI" << endl;
	NodoAVL<T> *Padre = nodo->getPadre();
	NodoAVL<T> *P = nodo;
	NodoAVL<T> *Q = P->getDerecho();
	NodoAVL<T> *B = Q->getIzquierdo();

	if (Padre)
		if (Padre->getDerecho() == P) 
			Padre->setDerecho(Q);
		else 
			Padre->setIzquierdo(Q);
	else 
		raiz = Q;

	P->setDerecho(B);
	Q->setIzquierdo(P);

	P->setPadre(Q);
	if (B) 
		B->setPadre(P);
	Q->setPadre(Padre);

	P->FE = 0;
	Q->FE = 0;
}

template<class T>
void ArbolAVL<T>::Borrar(const T dat) {
	NodoAVL<T> *padre = NULL;
	NodoAVL<T> *nodo;
	NodoAVL<T> *p = raiz;
	T aux;

	while (!Vacio(p)) {
		if (dat == p->getValor()) {
			if (EsHoja(p)) {
				if (padre)
					if (padre->getDerecho() == p) 
						padre->setDerecho(NULL);
					else if (padre->getIzquierdo() == p) 
						padre->setIzquierdo(NULL);
				delete p;
				p = NULL;
				if ((padre->getDerecho() == p && padre->FE == 1) ||
				        (padre->getIzquierdo() == p && padre->FE == -1)) {
					padre->FE = 0;
					p = padre;
					padre = p->getPadre();
				}
				if (padre)
					if (padre->getDerecho() == p) 
						Equilibrar(padre, DERECHO, false);
					else
						Equilibrar(padre, IZQUIERDO, false);
				actual = p;
				return;
			} else {
				padre = p;
				if (p->getDerecho()) {
					nodo = p->getDerecho();
					while (nodo->getIzquierdo()) {
						padre = nodo;
						nodo = nodo->getIzquierdo();
					}
				} else {
					nodo = p->getIzquierdo();
					while (nodo->getDerecho()) {
						padre = nodo;
						nodo = nodo->getDerecho();
					}
				}
				aux = p->getValor();
				p->setValor(nodo->getValor());
				nodo->setValor(aux);
				p = nodo;
			}
		} else {
			padre = p;
			if(dat > p->getValor()) 
				p = p->getDerecho();
			else if (dat < p->getValor())
				p = p->getIzquierdo();
		}
	}
}

template<class T>
void ArbolAVL<T>::InOrden(NodoAVL<T> *nodo, bool r) {
	if (r) 
		nodo = raiz;
	if (nodo->getIzquierdo()) 
		InOrden(nodo->getIzquierdo(), false);
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << "  ";
	cout << nodo->getValor() << " (" << nodo->FE << ") "<< endl;
	if (nodo->getDerecho()) 
		InOrden(nodo->getDerecho(), false);
}

template<class T>
void ArbolAVL<T>::PreOrden(NodoAVL<T> *nodo, bool r) {
	if (r) 
		nodo = raiz;
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << "  ";
	cout << nodo->getValor() << " (" << nodo->FE << ") "<< endl;
	if (nodo->getIzquierdo()) 
		PreOrden(nodo->getIzquierdo(), false);
	if (nodo->getDerecho())
		PreOrden(nodo->getDerecho(), false);
}

template<class T>
void ArbolAVL<T>::PostOrden(NodoAVL<T> *nodo, bool r) {
	if (r) 
		nodo = raiz;
	if (nodo->getIzquierdo()) 
		PostOrden(nodo->getIzquierdo(), false);
	if (nodo->getDerecho()) 
		PostOrden(nodo->getDerecho(), false);
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << "  ";
	cout << nodo->getValor() << " (" << nodo->FE << ") "<< endl;
}

template<class T>
void ArbolAVL<T>::imprimir(int o) {
	if (raiz == NULL)
		return;
	if (o == 1) 
		PreOrden();
	else if (o == 2) 
		InOrden();
	else
		PostOrden();
}

template<class T>
void ArbolAVL<T>::imprimirSubArbol(NodoAVL<T> *nodo) {
	if (nodo == NULL)
		return;
				
	if (nodo->getIzquierdo())
		imprimirSubArbol(nodo->getIzquierdo());
		
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << " ";
	cout << nodo->getValor() << " (" << nodo->FE << ") " << endl;	
	
	if (nodo->getDerecho()) 
		imprimirSubArbol(nodo->getDerecho());
		
}

template<class T>
bool ArbolAVL<T>::Buscar(T dat) {
	NodoAVL<T> *p = raiz;
	
	while (!Vacio(p)) {
		if (dat == p->getValor()) {
			actual = p;
			return true;
		} else if (dat > p->getValor()) 
			p = p->derecho;
		else if (dat < p->getValor()) 
			p = p->getIzquierdo();
	}
	return false;
}

template<class T>
int ArbolAVL<T>::Nivel(T dat) {
	int altura = 0;
	NodoAVL<T> *p = raiz;
	
	while (!Vacio(p)) {
		if (dat == p->getValor()) 
			return altura;
		else {
			altura++;
			if (dat > p->getValor()) 
				p = p->getDerecho();
			else if (dat < p->getValor()) 
				p = p->getIzquierdo();
		}
	}
	return -1;
}

template<class T>
const int ArbolAVL<T>::NumeroNodos() {
	contador = 0;
	if(!raiz)
		return 0;
	auxContador(raiz);
	return contador;
}

template<class T>
void ArbolAVL<T>::auxContador(NodoAVL<T> *nodo) {
	contador++;
	if (nodo->getIzquierdo()) 
		auxContador(nodo->getIzquierdo());
	if (nodo->getDerecho())   
		auxContador(nodo->getDerecho());
}

template<class T>
const int ArbolAVL<T>::AlturaArbol() {
	altura = 0;
	if (!raiz)
		return -1;
	auxAltura(raiz, 0);
	return altura;
}

template<class T>
void ArbolAVL<T>::auxAltura(NodoAVL<T> *nodo, int a) {
	if (nodo->getIzquierdo()) 
		auxAltura(nodo->getIzquierdo(), a+1);
	if (nodo->getDerecho())   
		auxAltura(nodo->getDerecho(), a+1);
	if (EsHoja(nodo) && a > altura) 
		altura = a;
}

#endif
