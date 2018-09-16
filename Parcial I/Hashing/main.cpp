#include <iostream>
#include <string.h>

#include "Hashing.h"
#include "Usuario.h"

using namespace std;

int main(int argc, char** argv) {
	string nombreArchivo="claves.txt";
	int cont;
	
	Hashing *a = new Hashing(nombreArchivo);
		a->abrirFichero(); //abre el archivo.
		a->numeroLinea(cont); //cuenta cuantos datos (lineas) tiene el archivo
		a->cerrarFichero(); //cierra el archivo.
	
		Usuario *user = new Usuario(-1,"sin nombre");
		a->crearVector(cont,*user); //crea el vector y lo llena por defecto.
		//a.imprimir();
	
		a->abrirFichero();	
		a->extraerDatos(*user,cont); //extrae los datos del archivo.
		a->cerrarFichero();
		cout<<"--------------------------------------------------------------------"<<endl;
		a->imprimir(); //muestra en pantalla el vector lleno por hash.
		Usuario *busqueda = new Usuario(54354267,"sin nombre"); //dato a buscar en el vector.
		a->buscar(*busqueda); //metodo que hace la busqueda.
	return 0;
}
