#include "Hashing.h"

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

#include "Usuario.h"
using namespace std;

Hashing::Hashing()
{
}

Hashing::Hashing(string a){
	this->nombre = a;	
}

void Hashing::abrirFichero(){
	fic.open(nombre.c_str(),ios::in);
}

void Hashing::cerrarFichero(){
	fic.close();
}

void Hashing::numeroLinea(int &cont){
	cont=0;
	
	if(fic.fail()){
		cout<<"Error al cargar Archivo";
	}else{
		while(getline(fic,cadena)){
			cont++;
		}
	}
}

void Hashing::extraerDatos(Usuario user,int cont){
	colisiones = 0;
	if(fic.fail()){
		cout<<"Error al cargar Archivo";
	}else{
		while(getline(fic,cadena)){
			auxNumero = strtok(&cadena[0],",");
			auxNombre = strtok(NULL,"\n");
						
			int numAux = atoi(auxNumero.c_str());
			Usuario guardar(numAux,auxNombre);

			pos = Hashing::hashMod(numAux);
				if(list[pos] == user){
					list[pos] = guardar;
				}else{
					pos = Hashing::hashRaiz(numAux);
					if (list[pos] == user){
						list[pos] = guardar;
					}else{
						pos = Hashing::hashCuadratico(numAux);
						if (list[pos] == user){
							list[pos] = guardar;
						}else{
							pos = Hashing::casillasVacias(user);
							pos = Hashing::hashDensidad(numAux,pos);
							if(list[pos] == user){
								list[pos] = guardar;
							}else{
								colisiones++;		
							}
						}
					}
				}

		}
	}
	cout << "colisiones "  << (colisiones / cont) * 100 << "%"<<endl;
}
void Hashing::crearVector(int cont,Usuario user){
	for(int i=0;i<cont;i++){
		list.push_back(user);
	}
}

void Hashing::imprimir(){
	for(int i=0;i<list.size();i++){
		cout<<list[i]<<endl;
	}

}

void Hashing::buscar(Usuario b){
	bool band = false;
	int i;
	for(i=0;i<list.size();i++){
		if(list[i] == b){
			band = true;
			break;
		}
	}
	
	if(band) cout<<endl<<"Busqueda Finalizada correctamente!: "<<list[i];
	else cout<<"Valor no encontrado";
}

int Hashing::hashRaiz(int valor){
	double resultado;
	string ret;
	resultado = sqrt(valor);
	resultado *= 100;

	ret += Hashing::to_string((int)resultado%10);
	resultado/=10;
	ret += Hashing::to_string((int)resultado%10);
	reverse(ret.begin(),ret.end());

	return (atoi(&ret[0]))%list.size();
}
string Hashing::to_string(int x){
	string l;
		while(x) {
			l.push_back(x%10 + '0');
			x/=10;
		}
	reverse(l.begin(), l.end());
	return l;
}

int Hashing::hashMod(int valor){
	return valor%list.size();
}

int Hashing::hashCuadratico(int valor){
	int inc = 0;
	valor = (valor+inc+1)%list.size();
	inc+=2;
	return valor;
}

int Hashing::hashDensidad(int valor,int nroVacias){
	return (valor/nroVacias)%list.size(); 
}

int Hashing::casillasVacias(Usuario user){
	int contAux=0;
	for(int i = 0;i < list.size()-1;i++){
		if(list[i] == user){
			contAux++;
		}
	}
	return contAux;
}

