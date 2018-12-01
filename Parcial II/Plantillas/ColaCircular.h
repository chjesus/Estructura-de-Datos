#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H
#include <iostream>
using namespace std;

template <class T>
class ColaCircular
{
	T *p;
	int inicio, final, size;
	public:
		ColaCircular(int n);
		bool isVacia();
		bool isLLena();
		void Anadir(T v);
		T Leer();
		void sort();
		void Imprimir();
};

template <class T>
ColaCircular<T>::ColaCircular(int n)
{
	size = n;
	inicio = final = -1;
	p = new T[size];
}

template <class T>
void ColaCircular<T>::Anadir(T v)
{
	int vfinal = (final + 1) % size;

	if (!isLLena()) {
		if (inicio == -1)
			inicio = 0;

		p[vfinal] = v;
		final = vfinal;
	}
}

template <class T>
T ColaCircular<T>::Leer()
{
	T v;
	if(!isVacia()) {
		v = p[inicio];
		if (inicio == final)
			inicio = final = -1;
		else
			inicio = (inicio + 1) % size;
		return v;
	}
}

template <class T>
void ColaCircular<T>::sort()
{
    T temp;
    for (int i = 0; i < size; i++) {
        for (int j = i-1; j >= 0 && p[j+1] < p[j]; j--) {
            temp = p[j+1];
            p[j+1] = p[j];
            p[j] = temp;
        }
    }
}

template <class T>
bool ColaCircular<T>::isLLena()
{
	if ((inicio == 0 && final == size-1) || ((final+1) == inicio)) {
		cout << "Cola llena" << endl;
		return 1;
	}
	return 0;
}

template <class T>
bool ColaCircular<T>::isVacia()
{
	if (inicio == -1 && final == -1) {
		cout << "Cola vacia" << endl;
		return 1;
	}
	return 0;
}

template <class T>
void ColaCircular<T>::Imprimir()
{
	if (!isVacia()) {
		if (inicio <= final)
			for (int i = inicio; i <= final; i++)
				cout << p[i] << endl;
		if (final < inicio) {
			for (int i = inicio; i < size; i++)
				cout << p[i] << endl;
			for (int i = 0; i <= final; i++)
				cout << p[i] << endl;
		}
	}
}
#endif
