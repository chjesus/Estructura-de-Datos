#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Shell(int v[], int n);
void ShellMejorado(int v[], int n);
void Mostrar(int v[], int n);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int n = 25;
	int v[n];
	for (int i = 0; i < n; i++) 
		v[i] = rand()%100+1;
	
	cout << "Antes: ";
	Mostrar(v, n);
	ShellMejorado(v, n);
	cout << "Despues: ";
	Mostrar(v, n);
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

void Shell(int v[], int n) {
	int aux;
	
	for (int i = n/2; i > 0; i /= 2){
		for (int j = i; j < n; j++){
            for (int k = j - i; k >= 0; k = k - i){
                if (v[k+i] >= v[k])
                    break;
                else {
                    aux = v[k];
                    v[k] = v[k+i];
                    v[k+i] = aux;
                }
            }
        }		
	}
}

void ShellMejorado(int v[], int n) {
	bool band;
	int inc = n/2, aux;
	
	while (inc > 0){
		band = false;
		for (int i = 0; i+inc < n; i++) {
			if (v[i] > v[i+inc]) {
				aux = v[i];
				v[i] = v[i+inc];
				v[i+inc] = aux;
				band = true;
			}
		}
		if (!band)
			inc /= 2;
	}
}

void Mostrar(int v[], int n) { 
	for (int i = 0 ; i < n ; i++)
		cout << v[i] << " ";
	cout << endl;
}
