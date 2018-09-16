#include <iostream>
#include "Campeonato.h"
/** 
-----Actividad Nro 1-----
	En un campeonato de natacion se inscribieron 8 participantes, con cedula de identidad, nombre y numero de carril asignado 
	acorde de su tiempo de marca personal. Se requiere un programa para ingresar por teclado el tiempo en segundos de cada uno
	de los competidores, carril por carril e imprimir la tabla de posiciones en pantalla.

	Nota: Aplicar el metodo de ordenacion seleccion directa.
	Para agilizar la entrada utilizar un arreglo inicializado, con los datos de la inscripcion.
*/
void Seleccion(Campeonato v[],int N);
using namespace std;
int main(int argc, char** argv) {
	int tiempo;
	Campeonato v[]={Campeonato(24148477,"Jesus",4,0),
					Campeonato(12468878,"Juan",3,0),
					Campeonato(68763196,"Luis",5,0),
					Campeonato(13368979,"Carlos",7,0),
					Campeonato(32177988,"Pablo",1,0),
					Campeonato(51412415,"Pedro",6,0),
					Campeonato(63453534,"Maria",5,0),
					Campeonato(12312455,"Ana",2,0)};
					
	for(int i=0;i<sizeof(v)/sizeof(Campeonato);i++){
		cout<<"Ingrese el Tiempo de "<<v[i].getNombre()<<" en segundos: ";
		cin>>tiempo;
		v[i].setTiempo(tiempo);
	}
	Seleccion(v,sizeof(v)/sizeof(Campeonato));
	return 0;
}

void Seleccion(Campeonato v[],int N){
	Campeonato may(0,"",0,0);
	int aux;
	int i,j,posMay;
	
	for(j=N;j>1;j--){
		may=v[0];
		posMay=0;
		for(i=1;i<j;i++){
			if(v[i]>may){
				may=v[i];
				posMay=i;
			}
		}
		if(posMay!=j-1){
			v[posMay]=v[j-1];
			v[j-1]=may;
		}
	}
	
	cout<<endl<<"Ordenado"<<endl;
	
	for(int a=0;a<N;a++){
		cout<<v[a];
	}
}
