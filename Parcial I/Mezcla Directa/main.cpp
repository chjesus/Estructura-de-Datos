#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "Persona.h"
#include "MezclaDirecta.h"

using namespace std;

int main(int argc, char** argv) {
//
//	fstream archivo;
//	archivo.open("datos.txt", ios::in);
//	string linea;
//	char *separar;
//	
//	vector<Persona> lista;
//	
//	if(archivo.fail())
//		cout << "fallo" << endl;
//	else {
//		while(getline(archivo, linea)) {
//			separar = strtok(&linea[0], "\t");
//			int cedula = atoi(separar);
//			separar = strtok(NULL, "\t");
//			char apellido[20];
//			strcpy(apellido, separar);
//			separar = strtok(NULL, "\t");
//			char nombre[20];
//			strcpy(nombre, separar);
//			separar = strtok(NULL, "\t");
//			Persona temp(nombre, apellido, cedula);
//			lista.push_back(temp);	
//		}
//	}
//		
//	archivo.close();
//	archivo.open("data.dat", ios::out | ios::binary);
//	
//	for (int i = 0; i < lista.size(); i++)	
//		archivo.write((char*) &lista[i], sizeof(Persona));

	fstream archivo("data.dat", ios::in | ios::binary);
	vector<Persona> lista;

	while(true) {
		Persona temp;
		archivo.read((char*) &temp, sizeof(Persona));
		if (archivo.eof())
			break;
		lista.push_back(temp);
		temp.imprimir();
	}
	
	archivo.close();
	int tam = lista.size();
	
	cout << "----" << endl;
	
	MezclaDirecta<Persona> ordenar("data.dat");
	ordenar.Ordenar(tam);
	
	archivo.open("data.dat", ios::in | ios::binary);
	lista.clear();

	while(true) {
		Persona temp;
		archivo.read((char*) &temp, sizeof(Persona));
		if (archivo.eof())
			break;
		lista.push_back(temp);
		temp.imprimir();
	}
	
	
	return 0;
}
