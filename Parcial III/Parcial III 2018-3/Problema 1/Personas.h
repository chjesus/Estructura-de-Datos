#ifndef PERSONAS_H
#define PERSONAS_H

#include <string.h>

using namespace std;
class Personas{
	int cedula;
	char apellido1[20];
	char apellido2[20];
	char nombre1[20];
	char noombre2[20];
	int codigo;
	char vacio[10];
	public:
		Personas(){}
		Personas(int ced,char *ape1,char *ape2,char *nom1,char *nom2,int cod,char *va){
			this->cedula = ced;
			strcpy(this->apellido1,ape1);
			strcpy(this->apellido2,ape2);
			strcpy(this->nombre1,nom1);
			strcpy(this->noombre2,nom2);
			this->codigo = cod;
			strcpy(this->vacio,va);
		}
		friend ostream& operator<<(ostream& os, const Personas& datos){  
	    	os<<"Cedula: "<<datos.cedula<<" Apellido 1: "<<datos.apellido1<<" Apellido 2: "<<datos.apellido2<<" Nombre 1: "<<datos.nombre1<<" Nombre 2: "<<datos.noombre2<<" Codigo: "<<datos.codigo<<" Basura: "<<datos.vacio<<endl;
		    return os;  
		}
		int getCedula(){return cedula;}
};

#endif
