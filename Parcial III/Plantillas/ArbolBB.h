#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <iostream>
#include <cstring>

#define IZQUIERDO 0
#define DERECHO 1

using namespace std;

template<class T> class ArbolBB;

template<class T>
class NodoABB {
	private:
		T dato;
		NodoABB<T> *padre;
		NodoABB<T> *izquierdo;
		NodoABB<T> *derecho;
	public:
		NodoABB(const T dat, NodoABB<T> *izq = NULL, NodoABB<T> *der = NULL, NodoABB<T> *pad = NULL) 
			: dato(dat), izquierdo(izq), derecho(der), padre(pad), FE(0) {}
		int FE;
		void setValor(T v) { dato = v; }
		void setDerecho(NodoABB<T> *p) { derecho = p; }
		void setIzquierdo(NodoABB<T> *p) { izquierdo = p; }
		void setPadre(NodoABB<T> *p) { padre = p; }
		T getValor() { return dato; }
		NodoABB<T> *getDerecho() { return derecho; }
		NodoABB<T> *getIzquierdo() { return izquierdo; }
		NodoABB<T> *getPadre() { return padre; }
	friend class ArbolBB<T>;
};

template<class T>
class ArbolBB {
	private:
		int contador;
		int altura;
		NodoABB<T> *raiz;
		NodoABB<T> *actual;
		
		void Podar(NodoABB<T>* &);
		void auxContador(NodoABB<T>*);
		void auxAltura(NodoABB<T>*, int);
	public:
		ArbolBB() : raiz(NULL), actual(NULL) {}
		~ArbolBB() { Podar(raiz); }
		int Anadir(const T dat);
		void Borrar(const T dat);
		bool Buscar(const T dat);
		int Nivel(const T dat);
		int Lugar(int n, bool r, NodoABB<T> *p = NULL);
		bool Vacio(NodoABB<T> *r) { return r == NULL; }
		bool EsHoja(NodoABB<T> *r) { return !r->getDerecho() && !r->getIzquierdo(); }
		const int NumeroNodos();
		const int AlturaArbol(NodoABB<T> *nodo = NULL);
		T &ValorActual() { return actual->getValor(); }
		NodoABB<T> *NodoActual() { return actual; }
		void Raiz() { actual = raiz; }
		void InOrden(NodoABB<T> *nodo = NULL, bool r = true);
		void PreOrden(NodoABB<T> *nodo = NULL, bool r = true);
		void PostOrden(NodoABB<T> *nodo = NULL, bool r = true);
		void imprimir(int o = 1);
		void CalcularFE(NodoABB<T> *nodo, bool r);
		int EsAVL(int&, bool r, NodoABB<T> *nodo = NULL);
};

template<class T>
int ArbolBB<T>::EsAVL(int &a, bool r, NodoABB<T> *nodo) {
	if(r)
		nodo = raiz;
	
	if (nodo->FE > 1 || nodo->FE < -1)
		a++;
	if (nodo->getDerecho())
		EsAVL(a, false, nodo->getDerecho());
	if (nodo->getIzquierdo())
		EsAVL(a, false, nodo->getIzquierdo());
	return a;
}

template<class T>
void ArbolBB<T>::Podar(NodoABB<T> *&nodo) {
	if(nodo) {
		Podar(nodo->izquierdo);
		Podar(nodo->derecho);
		delete nodo;
		nodo = NULL;
	}
}

template<class T>
int ArbolBB<T>::Anadir(const T dat) {	
	NodoABB<T> *NuevoNodo = new NodoABB<T>(dat);
	NodoABB<T> *p = raiz;
	
	if (Vacio(raiz))
		raiz = NuevoNodo;
	else {
		while (!Vacio(p)) {
			if (dat < p->getValor()) {
				if (!Vacio(p->getIzquierdo()))
					p = p->getIzquierdo();
				else {
					NuevoNodo->setPadre(p);
					p->setIzquierdo(NuevoNodo);
					actual = p;
					CalcularFE(raiz, true);
					return 1;				
				}
			} else if (dat > p->getValor()) {
				if (!Vacio(p->getDerecho())) 
					p = p->getDerecho();
				else {
					NuevoNodo->setPadre(p);
					p->setDerecho(NuevoNodo);
					actual = p;
					CalcularFE(raiz, true);
					return 1;
				}				
			} else
				return 0;
		}	
	}
}

template<class T>
void ArbolBB<T>::CalcularFE(NodoABB<T> *nodo, bool r) {
	if (r)
		nodo = raiz;
	if (nodo->getDerecho() == NULL && nodo->getIzquierdo() == NULL)	 {
		nodo->FE = 0;
		return;
	}
	nodo->FE = (AlturaArbol(nodo->getDerecho()) - AlturaArbol(nodo->getIzquierdo())) +1;
	if (nodo->getDerecho())
		CalcularFE(nodo->getDerecho(), false);
	if (nodo->getIzquierdo())
		CalcularFE(nodo->getIzquierdo(), false);		
}

template<class T>
void ArbolBB<T>::Borrar(const T dat) {
	NodoABB<T> *padre = NULL;
	NodoABB<T> *nodo;
	NodoABB<T> *p = raiz;
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
				actual = padre;
				CalcularFE(raiz, true);
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
			if (dat > p->getValor()) 
				p = p->getDerecho();
			else if (dat < p->getValor()) 
				p = p->getIzquierdo();
		}
	}
}

template<class T>
void ArbolBB<T>::InOrden(NodoABB<T> *nodo, bool r) {
	if (r) 
		nodo = raiz;
	if (nodo->getIzquierdo()) 
		InOrden(nodo->getIzquierdo(), false);
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << "    ";
	cout << nodo->getValor() << "(" << nodo->FE << ")" <<  endl;
	if (nodo->getDerecho()) 
		InOrden(nodo->getDerecho(), false);
}

template<class T>
void ArbolBB<T>::PreOrden(NodoABB<T> *nodo, bool r) {
	if (r) 
		nodo = raiz;
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << "    ";
	cout << nodo->getValor() << "(" << nodo->FE << ")" <<  endl;
	if (nodo->getIzquierdo()) 
		PreOrden(nodo->getIzquierdo(), false);
	if (nodo->getDerecho())
		PreOrden(nodo->getDerecho(), false);
}

template<class T>
void ArbolBB<T>::PostOrden(NodoABB<T> *nodo, bool r) {
	if (r) 
		nodo = raiz;
	if (nodo->getIzquierdo()) 
		PostOrden(nodo->getIzquierdo(), false);
	if (nodo->getDerecho()) 
		PostOrden(nodo->getDerecho(), false);
	for (int i = 0; i < Nivel(nodo->getValor()); i++)
		cout << "    ";
	cout << nodo->getValor() << "(" << nodo->FE << ")" <<  endl;
}

template<class T>
void ArbolBB<T>::imprimir(int o) {
	if (raiz == NULL)
		return;
	if (o == 1) 
		PreOrden();
	else if(o == 2) 
		InOrden();
	else
		PostOrden();
}

template<class T>
bool ArbolBB<T>::Buscar(const T dat) {
	NodoABB<T> *p = raiz;
		
	while (!Vacio(p)) {
		if (dat == p->getValor()) {
			actual = p;
			return true;
		} else if (dat > p->getValor()) 
			p = p->getDerecho();
		else if (dat < p->getValor()) 
			p = p->getIzquierdo();
	}
	return false;
}

template<class T>
int ArbolBB<T>::Nivel(const T dat) {
	int altura = 0;
	NodoABB<T> *p = raiz;
	
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
int ArbolBB<T>::Lugar(int n, bool r, NodoABB<T> *p) {
	if (r) 
		p = raiz;
	if (Nivel(p->getValor()) == n) {
		cout << p->getValor() << " ";
	}
	if (p->getIzquierdo()) 
		Lugar(n, false, p->getIzquierdo());
	if (p->getDerecho())
		Lugar(n, false, p->getDerecho());	
}

template<class T>
const int ArbolBB<T>::NumeroNodos() {
	contador = 0;
	if (!raiz)
		return 0;
	auxContador(raiz);
	return contador;
}

template<class T>
void ArbolBB<T>::auxContador(NodoABB<T> *nodo) {
	contador++;
	if (nodo->getIzquierdo()) 
		auxContador(nodo->getIzquierdo());
	if (nodo->getDerecho())   
		auxContador(nodo->getDerecho());
}

template<class T>
const int ArbolBB<T>::AlturaArbol(NodoABB<T> *nodo) {
	altura = 0;
	if (nodo == NULL)
		nodo = raiz;
	if (!raiz)
		return -1;
	auxAltura(nodo, 0);
	return altura;
}

template<class T>
void ArbolBB<T>::auxAltura(NodoABB<T> *nodo, int a) {
	if (nodo->getIzquierdo()) 
		auxAltura(nodo->getIzquierdo(), a+1);
	if (nodo->getDerecho())   
		auxAltura(nodo->getDerecho(), a+1);
	if (EsHoja(nodo) && a > altura) 
		altura = a;
}
#endif
