#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


void SeleccionDirecta(int v[], int n);
void Mostrar(int v[], int n);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for (int i = 0; i < n; i++) 
		v[i] = rand()%100+1;
	
	cout << "Antes: ";
	Mostrar(v, n);
	SeleccionDirecta(v, n);
	cout << "Despues: ";
	Mostrar(v, n);
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

void SeleccionDirecta(int v[], int n) {
	int i, j, mayor, pos = 0, aux;
	
	for (i = n-1; i >= 0; i--) {
		mayor = v[0];
		pos = 0;
		for (j = 0; j <= i; j++) {
			if (v[j] > mayor) {
				mayor = v[j];
				pos = j;
			}
		}
		aux = v[i];
		v[i] = v[pos];
		v[pos] = aux;
	}
}

void Mostrar(int v[], int n) { 
	for (int i = 0 ; i < n ; i++)
		cout << v[i] << " ";
	cout << endl;
}
