#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

#include "NodoDir.h"

using namespace std;
class Grafo{
	ListDinSimple<NodoDir> *listaAdy;
	char Matriz[8][9];
	bool direcional;
	int tam;
	int Longitud;
	
	float **M;
	float **R;
	public:
		Grafo(){}
		Grafo(char *nombreArchivo,bool direc = true,bool pond = true);
		void imprimirRuta();
		void imprimirMapa();
		void crearLista();
		void Imprimir();
		void crearM();
		void Warshall(int n);
		void FloyD();
};

Grafo::Grafo(char *nombreArchivo,bool direc,bool pond){
	fstream ficheroTexto;
	string cadena;
	char *split;
	
	tam = 0;
	direcional = direc;
	listaAdy = new ListDinSimple<NodoDir>;
	int i=0;
	int letra = 65;
	ficheroTexto.open(nombreArchivo,ios::in);
		if(ficheroTexto.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(ficheroTexto,cadena)){
				for(int x=0;x<cadena.size();x++){
					if(cadena[x]=='0'){
						Matriz[i][x] = (char)letra;
						letra++;
					}else{
						Matriz[i][x]= cadena[x];
					}
				}
				i++;
			}
		}
	ficheroTexto.close();
	imprimirMapa();
	crearLista();
	crearM();
}

void Grafo::imprimirMapa(){
	for(int i=0;i<8;i++){
		for(int j=0;j<9;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}	
}

void Grafo::crearLista(){
	for(int x = 1; x < 7; x++) {
		for(int y = 1; y < 8; y++) {
			if((Matriz[x][y] != '#' && Matriz[x][y+1] != '#') && x<8) {
				//cout << matriz[x][y] << " " << matriz[x][y+1] << " ";
				char origen = Matriz[x][y];
				char destino = Matriz[x][y+1];
				NodoDir nuevo1(origen),nuevo2(destino);
				
				if(listaAdy->buscar(nuevo1)!=1) tam += listaAdy->agregar(nuevo1);
				if(listaAdy->buscar(nuevo2)!=1)	tam += listaAdy->agregar(nuevo2);
			
				NodoAdy nuevo3(destino);
				if(listaAdy->buscar(nuevo1)!=-1) nuevo1.AgregarAdy(nuevo3);				
			}
			if((Matriz[x][y] != '#' && Matriz[x][y-1] != '#') && x>0) {
				//cout << matriz[x][y] << " " << matriz[x][y-1] << " ";
				char origen = Matriz[x][y];
				char destino = Matriz[x][y-1];
				NodoDir nuevo1(origen),nuevo2(destino);
				
				if(listaAdy->buscar(nuevo1)!=1) tam += listaAdy->agregar(nuevo1);
				if(listaAdy->buscar(nuevo2)!=1)	tam += listaAdy->agregar(nuevo2);
			
				NodoAdy nuevo3(destino);
				if(listaAdy->buscar(nuevo1)!=-1) nuevo1.AgregarAdy(nuevo3);		
			}
			if((Matriz[x][y] != '#' && Matriz[x+1][y] != '#') && y<9) {
				//cout << matriz[x][y] << " " << matriz[x+1][y] << " ";
				char origen = Matriz[x][y];
				char destino = Matriz[x+1][y];
				NodoDir nuevo1(origen),nuevo2(destino);
				
				if(listaAdy->buscar(nuevo1)!=1) tam += listaAdy->agregar(nuevo1);
				if(listaAdy->buscar(nuevo2)!=1)	tam += listaAdy->agregar(nuevo2);
			
				NodoAdy nuevo3(destino);
				if(listaAdy->buscar(nuevo1)!=-1) nuevo1.AgregarAdy(nuevo3);		
			}
			if((Matriz[x][y] != '#' && Matriz[x-1][y] != '#') && y>0) {
				//cout << matriz[x][y] << " " << matriz[x-1][y] << " ";
				char origen = Matriz[x][y];
				char destino = Matriz[x-1][y];
				NodoDir nuevo1(origen),nuevo2(destino);
				
				if(listaAdy->buscar(nuevo1)!=1) tam += listaAdy->agregar(nuevo1);
				if(listaAdy->buscar(nuevo2)!=1)	tam += listaAdy->agregar(nuevo2);
			
				NodoAdy nuevo3(destino);
				if(listaAdy->buscar(nuevo1)!=-1) nuevo1.AgregarAdy(nuevo3);		
			}
		}
		
	}
}

void Grafo::crearM(){
	M = new float*[tam];
	R = new float*[tam];
	
	for(int i=0;i<tam;i++){
        M[i] = new float[tam];
        R[i] = new float[tam];
  	}
  	for(int i=0;i<tam;i++){
    	for(int j=0;j<tam;j++)
      		M[i][j]=99;
  	}
  	if(listaAdy){
  		Nodo<NodoDir> *p = listaAdy->getCab();
  		Nodo<NodoAdy> *q;
  		int i=0,j;
  		while(p){
  			q = p->getInfo().getCabecera();
			  	while(q){
			  		NodoDir aux(q->getInfo().getVertice(),false);
					j = listaAdy->buscar(aux,false);
					M[i][j] = q->getInfo().getValor();
					if(!direcional) M[j][i]=M[i][j];
					q = q->getSig();
				}
			i++;
			p = p->getSig();
		}
	}

}

void Grafo::Warshall(int n){
	float **Z;  
    int i,j,k,l;
    Z= new float*[tam];
    for ( i=0; i<tam; i++ )
        Z[i]= new float[tam]; 
    for (i=0; i<tam; i++)
        for (j=0; j<tam; j++)
           R[i][j]= Z[i][j]= M[i][j];
    for (l=2; l<=n; l++)
    {
       for (i=0; i<tam; i++)
         for (j=0; j<tam; j++)
           for (k=0,R[i][j]=0;k<tam; k++)
                R[i][j]= R[i][j] || Z[i][k] && M[k][j];
       for (i=0; i<tam; i++)
         for (j=0; j<tam; j++)
           Z[i][j]= R[i][j];
       cout<<endl<<"\nWarshall M^"<<l<<":"<<endl;
       for ( i=0; i<tam; i++ )
       { cout<<endl;
         for ( j=0; j<tam; j++ )
            cout<<R[i][j]<<"   ";
       }
    }//Fin for l
}

void Grafo::FloyD(){
	for(int k=0;k<tam;k++){
		for(int i=0;i<tam;i++){
			for(int j=0;j<tam;j++){
				if(i!=j && i!=k && j!=k)
				if(M[i][k]+M[k][j]<M[i][j]) M[i][j]=M[i][k]+M[k][j];
			}
		}
	}
	
	cout<<endl<<endl<<"Matriz: "<<endl;
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	Longitud = M[0][1];
}

void Grafo::imprimirRuta(){
	cout<<"Longitud: "<<Longitud;
}

void Grafo::Imprimir(){
	if(listaAdy!=NULL) listaAdy->imprimir();
	
//	if(M!=NULL){
//		cout<<endl<<"Matriz de ADyacencia:"<<endl;
//      for (int i=0; i<tam; i++ )
//      {
//        cout<<endl;
//        for (int j=0; j<tam; j++ )
//            cout<<setiosflags(ios::fixed) <<setprecision(0)<<M[i][j]<<" ";
//      }
//	}
}
#endif
