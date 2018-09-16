#ifndef ENCUESTA_H
#define ENCUESTA_H

#include <string.h>
#include <stdlib.h>
using namespace std;
class Encuesta{
	int codigoAsig;
	char sexo;
	int condicionAlu;
	float indice;
	public:
		Encuesta(){}
		Encuesta(int cod,char sex,int cond,float ind){
			this->codigoAsig = cod;
			this->sexo = sex;
			this->condicionAlu = cond;
			this->indice = ind;
		}
			
		friend ostream& operator<<(ostream& os, const Encuesta& datos){  
	    	os<<"Codigo: "<<datos.codigoAsig<<" Sexo: "<<datos.sexo<<" Condicion: "<<datos.condicionAlu<<" Indice: "<< datos.indice<<endl;
		    return os;  
		}
		
		int getCodigo(){return codigoAsig;}
		char getSexo(){return sexo;}
		int getCondicion(){return condicionAlu;}
		float getIndice(){return indice;}

};

#endif
