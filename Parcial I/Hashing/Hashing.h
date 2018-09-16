#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

#include "Usuario.h"
using namespace std;
class Hashing{
	
	fstream fic;
	
	int pos;	
	double colisiones;
	
	string auxNumero;
	string auxNombre;
	string cadena;
	
	string nombre;

	vector<Usuario> list;
	
	public:
		Hashing();
		Hashing(string n);
		
		void abrirFichero();
		void cerrarFichero();
		void numeroLinea(int &cont);
		void crearVector(int cont,Usuario user);
			
		void extraerDatos(Usuario user,int cont);

		void imprimir();
		void buscar(Usuario busqueda);
		
		int casillasVacias(Usuario user);
		
		int hashRaiz(int valor);
		inline string to_string(int x);
		int hashMod(int valor);
		int hashCuadratico(int valor);
		int hashDensidad(int valor,int nroVacias);
};


#endif
