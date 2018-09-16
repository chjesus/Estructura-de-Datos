#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "Materia.h"
/**
	Dado el codigo de una materia modificar el numero de estudiantes inscritos
*/
using namespace std;
int main(int argc, char** argv) {
	fstream archivo;
	int numero,cant;
	Materia *leer = new Materia();

	cout<<"Ingrese el codigo para modificar: ";
	cin>>numero;
	cout<<endl<<"Ingre la cantidad de estudiantes Inscritos:";
	cin>>cant;
	archivo.open("materia.dat",ios::binary | ios::in);
		while(!archivo.eof() && archivo.read(reinterpret_cast<char*>(leer),sizeof(Materia))){
			if(leer->getCodigo() == numero){
				leer->setCantEstudiantes(cant);
			}
		}
	archivo.close();

	return 0;
}
