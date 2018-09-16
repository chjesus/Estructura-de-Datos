#ifndef LISTADOBCIRCULAR_H
#define LISTADOBCIRCULAR_H
#include <iostream>
using namespace std;

template <class T> class ListaDobCircular;

template<class T>
class nodo {
	private:
		T valor;
		nodo<T> *siguiente;
		nodo<T> *anterior;
	public:
    nodo(T v, nodo<T> *sig = NULL, nodo<T> *ant = NULL) : valor(v), siguiente(sig), anterior(ant) {}
    void setValor(T _valor) { valor = _valor; }
    void setSiguiente(nodo<T> *p) { siguiente = p; }
    void setAnterior(nodo<T> *p) { anterior = p; }
    T getValor() { return valor; }
    nodo<T> *getSiguiente() { return siguiente;	}
    nodo<T> *getAnterior() { return anterior;	}
	friend class ListaDobCircular<T>;
};

template <class T>
class ListaDobCircular
{
    nodo<T> *cab, *p;
    int numeroNodos;
  public:
    ListaDobCircular() { cab=NULL; numeroNodos = 0; }
    bool isVacia()    { return cab==NULL; }
    T    GetActual(){ return p->getValor(); }
    nodo<T>* GetNodoActual() { return p; }
    int  Agregar (T ele);
    int  AgregarSinOrden (T ele);
    void Mover   (int pos, int band=1);
    void Imprimir(int band=1);  
    void eliminar();
	int getTam() { return numeroNodos; }
}; 



template <class T>
int ListaDobCircular<T>::Agregar (T ele)
{
      nodo<T> *nuevo;
      nuevo = new nodo<T>(ele);
      if (!nuevo)  return 0; // Se agoto la memoria din.
      nuevo->setValor(ele);
      
      if (isVacia()) {
           cab = nuevo;
           cab->setSiguiente( cab );
           cab->setAnterior( cab ); 
           numeroNodos++;
           return 1;
      }
      p = cab;
      do {
          if ( ele < p->getValor() ) 
		  	break;
          p = p->getSiguiente();
      } while ( p!=cab );
      if ( ele < cab->getValor() ) cab = nuevo;
      nuevo->setSiguiente(p);
      nuevo->setAnterior(p->getAnterior());       
      p->getAnterior()->setSiguiente(nuevo);
      p->setAnterior(nuevo);
      numeroNodos++;
      return 1;
}

template <class T>
int ListaDobCircular<T>::AgregarSinOrden (T ele)
{
      nodo<T> *nuevo;
      nuevo = new nodo<T>(ele);
      if (!nuevo)  return 0; // Se agoto la memoria din.
      nuevo->setValor(ele);
      
      if (isVacia()) {
           cab = nuevo;
           cab->setSiguiente( cab );
           cab->setAnterior( cab ); 
           numeroNodos++;
           return 1;
      }
      p = cab;
      nuevo->setSiguiente(p);
      nuevo->setAnterior(p->getAnterior());       
      p->getAnterior()->setSiguiente(nuevo);
      p->setAnterior(nuevo);
      numeroNodos++;
      return 1;
}

template <class T>
void ListaDobCircular<T>::Imprimir(int band)
{
  if (isVacia()) 
    return;
  p = cab;
  if (!band) {
//    cout<<"Recorrido hacia addelante:\n";
    do {
      cout<<p->getValor()<<endl;
      p = p->getSiguiente();
    } while (p != cab);
  } else {
//    cout<<"Recorrido hacia atras:\n";
    do {      
      p = p->getAnterior();            
      cout<<p->getValor()<<endl;
    } while (p != cab);
  }
}

template <class T>
void ListaDobCircular<T>::eliminar()
{
	nodo<T> *aux = p;
	if ( isVacia() )
		return;
	numeroNodos--;
	if(numeroNodos>0) {
		p->getAnterior()->setSiguiente(p->getSiguiente());
		p->getSiguiente()->setAnterior(p->getAnterior());
		p = aux->getSiguiente();	
	}
	delete(aux);
}

template <class T>
void ListaDobCircular<T>::Mover(int pos, int band)
{
  for (int i=0; i<pos; i++)
   if (!band) 
    p = p->getSiguiente();
   else
    p = p->getAnterior(); 
}

#endif
