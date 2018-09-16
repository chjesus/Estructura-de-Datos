#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void InsercionDirecta(int v[], int n);
void Mostrar(int v[], int n);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for (int i = 0; i < n; i++) 
		v[i] = rand()%100+1;
	
	cout << "Antes: ";
	Mostrar(v, n);
	InsercionDirecta(v, n);
	cout << "Despues: ";
	Mostrar(v, n);
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

void InsercionDirecta(int v[], int n) {
	int aux, pos;
	for (int i = 1; i < n; i++){
		pos = i;
		aux = v[i];
		while (pos > 0 && aux < v[pos-1]) {
			v[pos] = v[pos-1];
			pos--;
		}
		v[pos] = aux;
	}
}

void Mostrar(int v[], int n) { 
	for (int i = 0 ; i < n ; i++)
		cout << v[i] << " ";
	cout << endl;
}
