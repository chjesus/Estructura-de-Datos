#ifndef MATERIA_H
#define MATERIA_H

#include <stdlib.h>
using namespace std;
class Materia{
	int codigoAsig;
	char descripcion[80];
	char uc;
	public:
		Materia(){}
		Materia(int cod,char *desc,char uc){
			this->codigoAsig = cod;
			strcpy(this->descripcion,desc);
			this->uc = uc;
		}
		friend ostream& operator<<(ostream& os, const Materia& datos){  
	    	os<<"Codigo: "<<datos.codigoAsig<<" Descripcion: "<<datos.descripcion<<" UC: "<<datos.uc<<endl;
		    return os;  
		}
		int getCodigo(){return codigoAsig;}
		char *getDescripcion(){return descripcion;}
		char getUC(){return uc;}
};

#endif
