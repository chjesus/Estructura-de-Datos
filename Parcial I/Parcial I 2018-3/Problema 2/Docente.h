#ifndef DOCENTE_H
#define DOCENTE_H

#include <stdlib.h>

using namespace std;
class Docente{
	int cedula;
	char nombre[30];
	public:
		Docente(){}
		Docente(int ced, char *nom){
			this->cedula = ced;
			strcpy(this->nombre,nom);
		}
		
		friend ostream& operator<<(ostream& os, const Docente& datos){  
	    	os<<"Cedula: "<<datos.cedula<<" Nombre: "<<datos.nombre<<endl;
		    return os;  
		}

		int getCedula(){return cedula;}
		char *getNombre(){return nombre;}
};

#endif
