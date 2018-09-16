#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ordenar(int v[]);
int main(int argc, char** argv) {
	int v[10];
	srand (time(NULL));
	
	for(int i=0;i<10;i++){
		v[i]=rand()%51;
	}
	ordenar(v);

	return 0;
}

void ordenar(int v[]){
	int aux,i,j;
	for(i=0;i<10;i++){
		cout<<"\n"<<v[i];
	}
	cout<<"\n";
	for(i=0;i<10;i++){
		for(j=0;j<10-1;j++){
			if(v[j]>v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
	cout<<"\n";
	for(i=0;i<10;i++){
		cout<<"\n"<<v[i];
	}
}
