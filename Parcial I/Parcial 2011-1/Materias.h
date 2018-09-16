#ifndef MATERIAS_H
#define MATERIAS_H
#include <iostream>
#include <string.h>

using namespace std;
class Materias{
	int codigoMateria;
	string nombreMateria;
	public:
		Materias(){}
		Materias(int cod,string nom){
			this->codigoMateria = cod;
			this->nombreMateria = nom;
		}
		int getCodigo(){
			return codigoMateria;
		}
		void setCodigo(int n){
			this->codigoMateria = n;
		}
		string getNombre(){
			return nombreMateria;
		}
		void setNombre(string n){
			this->nombreMateria = n;
		}
};

#endif
