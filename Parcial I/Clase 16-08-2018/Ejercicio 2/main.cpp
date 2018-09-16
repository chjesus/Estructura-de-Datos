#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "Materia.h"
/**
	Programa para Eliminar un registro de materia cuyo codigo es dado por teclado
*/
using namespace std;
int main(int argc, char** argv) {
	fstream archivo,arcNew;
	int numero;
	bool band = false;
	Materia *leer = new Materia();

	cout<<"Ingrese el codigo del dato a eliminar: ";
	cin>>numero;
	arcNew.open("materiaNew.dat",ios::binary | ios::out);
		archivo.open("materia.dat",ios::binary | ios::in);
			while(!archivo.eof() && archivo.read(reinterpret_cast<char*>(leer),sizeof(Materia))){
				if(leer->getCodigo() != numero){
					arcNew.write(reinterpret_cast<char*>(leer),sizeof(Materia));
				}
			}
		archivo.close();
	arcNew.close();
	remove("materia.dat");
	rename("materiaNew.dat","materia.dat");
	return 0;
}
