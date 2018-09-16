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
class ListaDobCircular{
    nodo<T> *cab, *p;
    int numeroNodos;
  public:
    ListaDobCircular() { cab=NULL; numeroNodos = 0; }
    bool isVacia()    { return cab==NULL; }
    T    GetActual(){ return p->getValor(); }
    nodo<T>* GetNodoActual() { return p; }
    int  Agregar (T ele);
    int  AgregarSinOrden (T ele);
    int EliminarEle(T &ele);
    int Buscar(T &ele);
//    int Ultimo(){ return p = p->getAnterior();}
//    int Primero(){return p = cab;}
    void Mover   (int pos, int band=1);
    void Imprimir(int band=1);  
    void eliminar();
    void eliminarPos();
	int getTam() { return numeroNodos; }
}; 



template <class T>
int ListaDobCircular<T>::Agregar (T ele){
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
int ListaDobCircular<T>::AgregarSinOrden (T ele){
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
int ListaDobCircular<T>::EliminarEle(T &ele){
	nodo<T> *ant = cab->getAnterior();
	nodo<T> *sig = cab;
	
	if(isVacia()) return 0;

	if(sig->getValor()==ele){
		cab = cab->getSiguiente();
		ant->setSiguiente(cab);
		cab->setAnterior(ant);
		numeroNodos--;
	}else if(ant->getValor()==ele){
		ant = ant->getAnterior();
		cab->setAnterior(ant);
		ant->setSiguiente(cab);
		numeroNodos--;
	}else{
		do{
			sig = sig->getSiguiente();
			if(sig->getValor() == ele){
				ant = sig->getSiguiente();
				sig = sig->getSiguiente();
				ant->setSiguiente(sig);
				sig->setAnterior(ant);
				numeroNodos--;
			}
		}while(sig != cab);
	}
	return 0;
}

template <class T>
int ListaDobCircular<T>::Buscar(T &ele){
	nodo<T> *buscar = cab;
	if(isVacia()) return 0;
	
	if(cab){
		do{
			if(buscar->getValor()==ele) return 1;
			buscar = buscar->getSiguiente();
		}while(buscar != cab);
	}
	return 0;
}
template <class T>
void ListaDobCircular<T>::Imprimir(int band){
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
      cout<<p->getValor()<<endl;
      p = p->getAnterior();            
    } while (p != cab);
  }
}

template <class T>
void ListaDobCircular<T>::eliminar(){
	nodo<T> *ant = cab->getAnterior();
	if ( isVacia() )
		return;
	numeroNodos--;
	if(numeroNodos>0) {
	
		cab = cab->getSiguiente();
		ant->setSiguiente(cab);
		cab->setAnterior(ant);
	}
}

template <class T>
void ListaDobCircular<T>::eliminarPos(){
//	nodo<T> *ant = p;
//	if ( isVacia() )
//		return;
//	numeroNodos--;
//	if(numeroNodos>0){
//        p = p->getSiguiente();
//        ant->setSiguiente(p);
//        p->setAnterior(ant);
//        //p->setAnterior(ant);
////        delete p;
////		ant->setSiguiente(p->getSiguiente());
////		p->getSiguiente()->setAnterior(ant);
//	}
}
template <class T>
void ListaDobCircular<T>::Mover(int pos, int band){
  for (int i=0; i<pos; i++)
   if (!band) 
    p = p->getSiguiente();
   else
    p = p->getAnterior(); 
}

#endif
