#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <iostream>
#include <string.h>

using namespace std;
class Alumnos{
	int codigoAlumno;
	string nombreAlumno;
	public:
		Alumnos(){}
		Alumnos(int cod,string nom){
			this->codigoAlumno = cod;
			this->nombreAlumno = nom;
		}
		
		int getCodigo(){
			return codigoAlumno;
		}
		void setCodigo(int n){
			this->codigoAlumno = n;
		}
		string getNombre(){
			return nombreAlumno;
		}
		void setNombre(string n){
			this->nombreAlumno = n;
		}
};

#endif
