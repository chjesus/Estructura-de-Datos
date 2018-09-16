#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "Materia.h"
/**
	Programa para crear un archvio bianrio titulado materia.dat para guardar 
	*Codigo (int)
	*Nombre 45 caracteres
	*Unidad de credito (int)
	*Cantidad de etudiantes inscriptos de las asignaturas aperturada en el intesivo 2018-3
*/

/**
	Dado el codigo de una materia imprimir los datos de la misma
*/

/**
	Programa para Eliminar un registro de materia cuyo codigo es dado por teclado
*/

using namespace std;
int main(int argc, char** argv) {
	int numero;
	bool band = false;
	Materia *leer = new Materia();
	Materia v[] = {	Materia(542547,"Estructura de Datos",4,12),
					Materia(123671,"Computacion I",3,15),
					Materia(512356,"Compiladores",4,15),
					Materia(512671,"Base de Datos",4,10),
					};

	fstream archivo;

	
	archivo.open("materia.dat",ios::binary | ios::out);
	archivo.write(reinterpret_cast<char*>(&v),sizeof(Materia)*4);
	archivo.close();
	
	archivo.open("materia.dat",ios::binary | ios::in);
		while(!archivo.eof() && archivo.read(reinterpret_cast<char*>(leer),sizeof(Materia))){
			leer->imprimir();	
		}
	archivo.close();
	
	cout<<endl<<endl;
	cout<<"Ingrese el codigo de la materia a mostrar: ";
	cin>>numero;
	
	archivo.open("materia.dat",ios::binary | ios::in);
		while(!archivo.eof() && archivo.read(reinterpret_cast<char*>(leer),sizeof(Materia))){
			if(leer->getCodigo() == numero){
				leer->imprimir();
				band = true;
			}
		}
	archivo.close();
	
	if(!band){
		cout<<"Dato No Encontrado!";
	}
	return 0;
}
