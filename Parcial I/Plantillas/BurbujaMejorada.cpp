#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Burbuja(int v[], int n);
void BurbujaMejorada(int v[], int n);
void Mostrar(int v[], int n);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for (int i = 0; i < n; i++) 
		v[i] = rand()%100+1;
	
	cout << "Antes: ";
	Mostrar(v, n);
	BurbujaMejorada(v, n);
	cout << "Despues: ";
	Mostrar(v, n);
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

void Burbuja(int v[], int n) {
	int aux;
	for (int i = 0; i < n; i++){
		for (int j = 0 ; j < n-1; j++){
			if (v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;	
			}	
		}		
	}	
}

void BurbujaMejorada(int v[], int n) {
	int aux;
	bool band; 
	
	for (int i = n-1 ; i > 0 ; i--){
		band = true;
		for (int j = 0 ; j < i ; j++){
			if (v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				band = false;
			}
		}
		if (band == true)
			break;
	}
}


void Mostrar(int v[], int n) { 
	for (int i = 0 ; i < n ; i++)
		cout << v[i] << " ";
	cout << endl;
}
