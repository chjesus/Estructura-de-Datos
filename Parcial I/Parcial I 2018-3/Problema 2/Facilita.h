#ifndef FACILITA_H
#define FACILITA_H

#include <stdlib.h>

using namespace std;
class Facilita{
	int codigoAsig;
	int cedula;
	public:
		Facilita(){}
		Facilita(int cod,int ced){
			this->codigoAsig = cod;
			this->cedula = ced;
		}
		
		friend ostream& operator<<(ostream& os, const Facilita& datos){  
	    	os<<"Codigo: "<<datos.codigoAsig<<" Cedula: "<<datos.cedula<<endl;
		    return os;  
		}
		
		int getCodigo(){return codigoAsig;}
		int getCedula(){return cedula;}
};

#endif
