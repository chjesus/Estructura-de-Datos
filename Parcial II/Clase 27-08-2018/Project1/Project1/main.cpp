#include <iostream>
#include "ListaEnlazada.h"
#include "Archivo.h"

using namespace std;
int main(){
	char nombre1[40] = "lista1.txt";
	char nombre2[40] = "lista2.txt";
	bool band = true;

	vector<int> listaVector1;
	vector<int> listaVector2;

	ListaEnlazada<int> lista1;
	ListaEnlazada<int> lista2;

	Archivo<int> a;

	a.separarCadena(nombre1, listaVector1);
	for (int i = 0; i<listaVector1.size(); i++){
		lista1.Anadir(listaVector1[i]);
	}

	a.separarCadena(nombre2, listaVector2);
	for (int i = 0; i<listaVector2.size(); i++){
		lista2.Anadir(listaVector2[i]);
	}

	cout << "Lista 1: " << endl << endl;
	lista1.Imprimir();
	cout << endl << endl << "Lista 2: " << endl << endl;
	lista2.Imprimir();

	lista2.Leer();

	for (int i = 0; i<listaVector1.size(); i++){
		band = true;
		for (int j = 0; j<listaVector2.size() && band == true; j++){
			if (listaVector1[i] == listaVector2[j]){
				lista2.Anadir(listaVector1[i]);
				band = false;
			}
		}
	}

	cout << endl << endl << "Lista Final: " << endl << endl;
	lista2.Imprimir();
	cin.get();
	return 0;
}
