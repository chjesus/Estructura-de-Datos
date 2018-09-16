#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Shaker(int v[], int n);
void Mostrar(int v[], int n);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for (int i = 0; i < n; i++) 
		v[i] = rand()%100+1;
	
	cout << "Antes: ";
	Mostrar(v, n);
	Shaker(v, n);
	cout << "Despues: ";
	Mostrar(v, n);
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

void Shaker(int v[], int n) {
	int inicio = 0, final = n-1;
	int aux;
	bool band = false;
	int cont = 0;
	
	do {	
		if (!band) {
			for (int i = 0; i < final; i++) {
				if (v[i] > v[i+1]) {
					aux = v[i];
					v[i] = v[i+1];
					v[i+1] = aux;
				}
			}
			band = true;
			final--;		
		}
		if (band) {	   
			for (int i = final ; i > inicio; i--) {
				if (v[i] < v[i-1]) {
					aux = v[i];
					v[i] = v[i-1];
					v[i-1] = aux;
				}
			}
			band = false;
			inicio++;		
		}	
		cont++;
	} while (cont < n/2);	
}

void Mostrar(int v[], int n) { 
	for (int i = 0 ; i < n ; i++)
		cout << v[i] << " ";
	cout << endl;
}
