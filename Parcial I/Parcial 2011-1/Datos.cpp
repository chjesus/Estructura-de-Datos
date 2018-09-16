#include <iostream>

#include "Datos.h"

using namespace std;
Datos::Datos(){}

Datos::Datos(int codAlumno,string nomAlumno,int codMateria,string nomMateria,float nota,float porc){
	this->codigoAlumno = codAlumno;
	this->nombreAlumno = nomAlumno;
	this->codigoMateria = codMateria;
	this->nombreMateria = nomMateria;
	this->notaParcial = nota;
	this->porcentaje = porc;
}

