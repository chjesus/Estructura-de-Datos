#include <iostream>
#include <time.h>
#include <stdlib.h>
#define sufpeq 5

using namespace std;

int Pivote(int v[], int inicio, int final);
void Quicksort(int v[], int inicio, int final);
void Burbuja(int v[], int n);
void Mostrar(int v[], int n);

int main(int args, char** argv) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	
	for(int i = 0;i < n; i++)
		v[i] = rand()%100+1;
	
	Mostrar(v, n);
	Quicksort(v, 0, n-1);
	Mostrar(v, n);
	
	return 0;
}

int Pivote(int v[], int inicio, int final) {
	int pivo;
	int izq;
	int der;
	int aux;
	
	pivo = v[inicio];
	izq = inicio;
	der = final;
	
	while (izq < der) {
		while ((v[izq] <= pivo) && (izq < der)) {
			izq++;	
		} 
		while (v[der] > pivo) {
			der--;	
		} 
		if (izq < der) {
			aux = v[izq];
			v[izq] = v[der];
			v[der] = aux;
			izq++; der--;
		}		
	}	
	aux = v[der];
	v[der] = v[inicio];
	v[inicio] = aux;
	
	return der;
}

void Quicksort(int v[], int inicio, int final){
	int pospiv;
	
	if (final <= sufpeq) {
		Burbuja(v, final);
	} else if (inicio < final) {
		pospiv = Pivote(v, inicio, final);
		Quicksort(v, inicio, pospiv-1);
		Quicksort(v, pospiv+1, final);		
	}	
}

void Burbuja(int v[], int n) {
	int aux;

	for (int i = 0; i < n; i++) {
		for (int j = 0 ; j < n-1; j++) {
			if (v[j] > v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;	
			}	
		}		
	}	
}

void Mostrar(int v[], int n) {
	for(int i = 0; i < n; i++) 
		cout << v[i] << " ";
	cout << endl;
}
