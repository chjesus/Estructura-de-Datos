#define sufpeq 2

#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

template <class T>
class Archivo{
	T *binarioArchivo;
	fstream ficheroTexto;
	fstream ficheroBinario;
	fstream ficheroBinario1;
	T leer;
	char nombre[40];
	int contA;
	string cadena;
	string auxCadena;
	
	public:
	Archivo(){}
	Archivo(char *nom){strcpy(nombre,nom);} //Recibe el nombre del Archivo
	
	void abrirFichero(); //Abre el Archivo
	void cerrarFichero(); //Cierra el Archivo
	void separarCadena(vector<T> &lista); //Separar Cadena del Archivo y lo guarda en el vector
	string devolverLinea(char *nombreArchivo,int max,int cont); //Devuelve Linea x Linea del Archivo
	T devolverObjeto(char *nombreArchivo,int max,int cont); //Devuelve Objeto x Objeto del Archivo
	void imprimirVector(vector<T> &lista); //Imprime el vector
	void ordenarVector(vector<T> &lista,int tipo); //Ordena el vector
	string crearArchivoBinario(string nombreArchivo);
	void imprimirArchivoBinario(string nombre);
	void compararAndImprimir(char *nombreDat,char *nombreTxt);
	void compararAndGuardar(int comparar,string nombreTxt);
	int tamArchivo(char *nombreArchivo); //Devuelve el Tamaño del Archivo
	
	/* Metodos de Ordenacion */
	
	void burbuja(vector<T> &v);
	void shell(vector<T> &v);
	void selecionDirecta(vector<T> &v,int tam);
	void inter(T &A, T &B);
	void MergeSort(vector<T> &m,int n);
	void Partir(vector<T> &v, T *x1, T *x2, int n);
	void Fusion(T *x1, T *x2, vector<T> &v, int n);
	void InsercionDirecta(vector<T> &v, int n);
	void Shaker(vector<T> &v, int n);
	void Quicksort(vector<T> &v, int inicio, int final);
	int Pivote(vector<T> &v, int inicio, int final);
	
	/* Tipos de Busqueda */
	int busquedaSecuencial(vector<T> &v,int tam,string nombre);
	int busquedaBinariaFinal(vector<T> &v, int tam, string nombre);

};

template <class T>
void Archivo<T>::abrirFichero(){
	ficheroTexto.open(nombre,ios::in | ios::binary);
}

template <class T>
void Archivo<T>::cerrarFichero(){
	ficheroTexto.close();
}

template <class T>
void Archivo<T>::separarCadena(vector<T> &lista){
	if(ficheroTexto.fail()){
		cout<<"Error al Abrir el Archivo"<<endl;
	}else{
		while(getline(ficheroTexto,cadena)){
			auxCadena = strtok(&cadena[0],",");
			string auxNumero = auxCadena;
			auxCadena = strtok(NULL,"\n");
			string auxNombre = auxCadena;
				
			T u(auxNumero,auxNombre);
			lista.push_back(u);
		}
	}
}

template <class T>
string Archivo<T>::devolverLinea(char *nombreArchivo,int max,int cont){
	cont=0;
	ficheroTexto.open(nombreArchivo,ios::in);
	if(ficheroTexto.fail()){
		cout<<"Error al Abrir el Archivo"<<endl;
	}else{
		while(getline(ficheroTexto,cadena)){
			if(max == cont){
				ficheroTexto.close();
				return cadena;
			}
			cont++;
		}
	}
}

template <class T>
T Archivo<T>::devolverObjeto(char *nombreArchivo,int max,int cont){
	cont=0;
	ficheroTexto.open(nombreArchivo,ios::in);
	if(ficheroTexto.fail()){
		cout<<"Error al Abrir el Archivo"<<endl;
	}else{
		while(getline(ficheroTexto,cadena)){
			if(max == cont){
				auxCadena = strtok(&cadena[0],",");
				int auxNumero = atoi(auxCadena.c_str());
				
				auxCadena = strtok(NULL,"\n");
				string auxNombre = auxCadena;
									
				T u(auxNumero,auxNombre);
				ficheroTexto.close();
				return u;
			}
			cont++;
		}
	}
}

template <class T>
int Archivo<T>::tamArchivo(char *nombreArchivo){
	ficheroTexto.open(nombreArchivo,ios::in);
	while(getline(ficheroTexto,cadena)){contA++;}
	ficheroTexto.close();
	return contA;
}

template <class T>
void Archivo<T>::imprimirVector(vector<T> &lista){
	for(int i = 0;i<lista.size();i++){
		cout<<lista[i];
	}
}

template <class T>
void Archivo<T>::ordenarVector(vector<T> &lista,int tipo){
	int tam = lista.size();
	
	switch(tipo){
		case 0:
			burbuja(lista);
			break;
		case 1:
			shell(lista);
			break;
		case 2:
			selecionDirecta(lista,tam);
			break;
		case 3:
			MergeSort(lista,tam); //REVISAR!!!!
			break;
		case 4:
			InsercionDirecta(lista,tam);
			break;
		case 5:
			Shaker(lista,tam);
			break;
		case 6:
			Quicksort(lista,0,tam-1);
			break;
	}
}

template <class T>
string Archivo<T>::crearArchivoBinario(string nombreArchivo){
	
	ficheroBinario.open(nombreArchivo.c_str(),ios::out);
		
	if(ficheroTexto.fail()){
		cout<<"Error al Abrir el Archivo"<<endl;
	}else{
		while(getline(ficheroTexto,cadena)){
			auxCadena = strtok(&cadena[0],",");
			int auxNumero = atoi(auxCadena.c_str());
			auxCadena = strtok(NULL,"\n");
			string auxNombre = auxCadena;
			
			binarioArchivo = new T(auxNumero,auxNombre);
			
			ficheroBinario.write(reinterpret_cast<char*>(binarioArchivo),sizeof(T));
		}
	}
	ficheroBinario.close();
	return nombreArchivo;
}

template <class T>
void Archivo<T>::imprimirArchivoBinario(string nombreDat){
	T *leer2 = new T();
	ficheroBinario.open(nombreDat.c_str(),ios::binary | ios::in);
		while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(leer2),sizeof(T))){
			cout<<"Cedula: "<<leer2->getNumero()<<" Nombre: "<<leer2->getNombre()<<endl;
		}
	ficheroBinario.close();
}

template <class T>
void Archivo<T>::compararAndImprimir(char *nombreDat,char *nombreTxt){
	
	ficheroBinario.open(nombreDat,ios::binary | ios::in);
		while(!ficheroBinario.eof() && ficheroBinario.read(reinterpret_cast<char*>(&leer),sizeof(T))){
			ficheroTexto.open(nombreTxt,ios::in);
				if(ficheroTexto.fail()){
					cout<<"Error al Abrir el Archivo"<<endl;
				}else{
					while(getline(ficheroTexto,cadena)){
						auxCadena = strtok(&cadena[0],",");
						int auxNumero = atoi(auxCadena.c_str());
						auxCadena = strtok(NULL,",");
						string auxNombre = auxCadena;
						auxCadena = strtok(NULL,"\n");
						string auxApellido = auxCadena;		
						
						if(leer.getNumero() == auxNumero){
							cout<<"Numero: "<<auxNumero<<" Nombre: "<<auxNombre<<" Apellido: "<<auxApellido<<endl;
						}
					}
				}
			ficheroTexto.close();
		}
	ficheroBinario.close();
}

template <class T>
void Archivo<T>::compararAndGuardar(int comparar,string nombreTxt){
	T *leer2 = new T();

	ficheroBinario.open("prueba.dat",ios::out);
		ficheroTexto.open(nombreTxt.c_str(),ios::in);
			if(ficheroTexto.fail()){
				cout<<"Error al Abrir el Archivo"<<endl;
			}else{
				while(getline(ficheroTexto,cadena)){
					auxCadena = strtok(&cadena[0],",");
					int auxNumero = atoi(auxCadena.c_str());
					auxCadena = strtok(NULL,",");
					string auxNombre = auxCadena;
					auxCadena = strtok(NULL,"\n");
					string auxApellido = auxCadena;		
					
					if(comparar == auxNumero){
						binarioArchivo = new T(auxNumero,auxNombre,auxApellido);
						ficheroBinario.write(reinterpret_cast<char*>(binarioArchivo),sizeof(T));
					}
				}
			}
		ficheroTexto.close();
	ficheroBinario.close();		
}
/* Metodos de Ordenacion */

template <class T>
void Archivo<T>::burbuja(vector<T> &v){
	T aux;
	for(int i = 0;i<v.size();i++){
		for(int j=0;j<v.size()-1;j++){
			if(v[j]>v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}	

template <class T>
void Archivo<T>::shell(vector<T> &v){
	bool band;
	int inc = v.size()/2;
	T aux;
			
	while (inc > 0){
		band = false;
		for (int i = 0; i+inc < v.size(); i++) {
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

template <class T>
void Archivo<T>::selecionDirecta(vector<T> &r,int tam){
	T men(0,"","");
	int pmen; 
	int i, j;			
	
	for(int j=1; j<tam; j++){		
		men=r[j-1];
		pmen=j-1;
		for(int i=j;i<tam;i++){		
			if(r[i] < men){
				men=r[i];
				pmen=i;
			}
		}
		if(pmen != j-1) Archivo::inter(r[j-1],r[pmen]);
	}
}

template <class T>
void Archivo<T>::inter(T &A, T &B){
	T aux(0,"","");
	aux=A;
	A=B;
	B=aux;
}

template <class T>
void Archivo<T>::MergeSort(vector<T> &m,int n){
	if (n<=sufpeq)
		selecionDirecta(m,n);
	else{
		T *x1, *x2;
		x1= new T[n/2];
		x2= new T[n-n/2];
		Archivo::Partir(m,x1,x2,n);
		Archivo::MergeSort(m,n/2);
		Archivo::MergeSort(m,n-n/2);
		Archivo::Fusion(x1,x2,m,n);
	}
}
	
template <class T>	
void Archivo<T>::Partir( vector<T> &v, T *x1, T *x2, int n){
	int i;
	for (i=0; i<n/2; i++)  x1[i]= v[i];
	for (;i<n; i++)        x2[i-n/2]=v[i];
}

template <class T>
void Archivo<T>::Fusion(T *x1, T *x2, vector<T> &v, int n){
	int i,j,k;
	i=j=k=0;
	for (;k<n;k++){
		if ( i==n/2 && j<n-n/2){
		    v[k]= x2[j];
		    j++;
	    }else if ( j==n-n/2 && i<n/2){
		    v[k]= x1[i];
		    i++;
	    }else if (  i<n/2 && j<n-n/2 && x1[i]<x2[j] ){ 
		   v[k]=x1[i];
		   i++;
		}else{
		   v[k]=x2[j];
		   j++;
		}
    }//fin for k
}

template <class T>	
void Archivo<T>::InsercionDirecta(vector<T> &v, int n) {
	int pos;
	T aux;
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
	
template <class T>	
void Archivo<T>::Shaker(vector<T> &v, int n) {
	int inicio = 0, final = n-1;
	T aux;
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
	
template <class T>
void Archivo<T>::Quicksort(vector<T> &v, int inicio, int final){
	int pospiv;
	if(final <= sufpeq){
		burbuja(v);
	}else if(inicio < final){
		pospiv = Pivote(v, inicio, final);
		Quicksort(v, inicio, pospiv-1);
		Quicksort(v, pospiv+1, final);		
	}	
}

template <class T>	
int Archivo<T>::Pivote(vector<T> &v, int inicio, int final) {
	T pivo;
	int izq;
	int der;
	T aux;
	
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

/* Tipos de Busqueda */

template <class T>
int Archivo<T>::busquedaBinariaFinal(vector<T> &v, int tam, string nombre){
	int Iarriba = tam-1;
	int Iabajo = 0;
	int Icentro;
  		while (Iabajo <= Iarriba){
    		Icentro = (Iabajo + Iarriba)/2;
      			if ((strcmp(nombre.c_str(),v[Icentro].getNombre().c_str()))!=0){
      				return Icentro;	
				}else if (nombre < v[Icentro].getNombre()){
					Iarriba=Icentro-1;
				}else{
					Iabajo=Icentro+1;
				}
    	}
  	return -1;
}

template <class T>
int Archivo<T>::busquedaSecuencial(vector<T> &v,int tam,string nombre){
	for(int i=0;i<tam;i++){
		if((strcmp(nombre.c_str(),v[i].getNombre().c_str()))!=0){
			return i;
		}
	}
	return -1;
}
