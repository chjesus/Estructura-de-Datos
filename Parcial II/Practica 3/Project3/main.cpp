#include <iostream>
#include "ListaEnlazada.h"
#include "Principal.h"
using namespace std;
int main(int argc, char** argv){
	ListaEnlazada<int> *lista1 = new ListaEnlazada<int>;
	ListaEnlazada<int> *lista2 = new ListaEnlazada<int>;

	Principal a;

	a.llenarListas(*lista1, *lista2);
	a.imprimirListasIntercalados(*lista1, *lista2);

	cin.get();
	return 0;
}