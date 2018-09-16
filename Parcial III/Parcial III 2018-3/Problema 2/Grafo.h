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
	bool direcional;
	int tam;
	
	float **M;
	float **R;
	public:
		Grafo(){}
		Grafo(char *nombreArchivo,bool direc = true,bool pond = true);
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
	
	ficheroTexto.open(nombreArchivo,ios::in);
		if(ficheroTexto.fail()){
			cout<<"Error al Abrir el Archivo"<<endl;
		}else{
			while(getline(ficheroTexto,cadena)){
				split = strtok(&cadena[0],",");
				string origen = split;
				
				split = strtok(NULL,",");
				string destino = split;
				
				split = strtok(NULL,"\n");
				float pes = atof(split);
//				cout<<"Origen: "<<origen<<" Destino: "<<destino<<" Peso: "<<pes<<endl;
				NodoDir nuevo1(origen),nuevo2(destino);
				if(listaAdy->buscar(nuevo1)!=1) tam += listaAdy->agregar(nuevo1);
				if(listaAdy->buscar(nuevo2)!=1)	tam += listaAdy->agregar(nuevo2);
				if(pond){
					NodoAdy nuevo3(destino,pes);
					if(listaAdy->buscar(nuevo1)!=-1) nuevo1.AgregarAdy(nuevo3);
				}else{
					NodoAdy nuevo3(destino);
					if(listaAdy->buscar(nuevo1)!=-1) nuevo1.AgregarAdy(nuevo3);
				}
			}
		}
	ficheroTexto.close();
	cout<<"Tamaño: "<<tam;
	crearM();
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
      		M[i][j]=0;
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
			cout<<M[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void Grafo::Imprimir(){
	if(listaAdy!=NULL) listaAdy->imprimir();
	
	if(M!=NULL){
		cout<<endl<<"Matriz de ADyacencia:"<<endl;
      for (int i=0; i<tam; i++ )
      {
        cout<<endl;
        for (int j=0; j<tam; j++ )
            cout<<setiosflags(ios::fixed) <<setprecision(2)<<M[i][j]<<"   ";
      }
	}
}
#endif
