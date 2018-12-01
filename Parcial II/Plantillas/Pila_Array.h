#ifndef PILA_ARRAY_H
#define PILA_ARRAY_H
#include <iostream>

using namespace std;

template <class T>
class Pila_Array {
	
	private:
		T *v;
		int size, tope,colx;		
	public:		
		Pila_Array(int tam){
			size = tam;
			v = new T [size];
			tope =- 1;
		}	
		int Anadir(T &in);
		int Leer(T &in);
		void Imprimir();	
};

template<class T>
int Pila_Array<T>::Anadir(T &in) {
	if (tope<(size-1)) {
		tope++;
		v[tope] = in;
		return tope;
	}
	cout <<"PILA LLENA"<<endl;
	return -1;
}

template<class T>
int Pila_Array<T>::Leer(T &in) {
	if(tope!=-1){
		in = v[tope];
		tope--;
		return tope;
	}
	cout<<"PILA VACIA"<<endl;
	return -1;
}

template<class T>
void Pila_Array<T>::Imprimir() {
	for(int i=0; i<=tope;i++)
		cout<<"  "<<v[i]<<"  ";
}

#endif
