#ifndef VEHICULO_H
#define VEHICULO_H

#include <string.h>

using namespace std;
class Vehiculo{
	char placa[40];
	char marca[40];
	bool activo;
	public:
		Vehiculo(){}
		Vehiculo(char *pla,char *mar,bool act){
			strcpy(this->placa,pla);
			strcpy(this->marca,mar);
			this->activo = act;
		}
		friend ostream& operator<<(ostream& os, const Vehiculo& datos){  
			if(datos.activo){
				os<<"Placa: "<<datos.placa<<" Marca: "<<datos.marca<<" Estatus: Libre.";
			}else{
				os<<"Placa: "<<datos.placa<<" Marca: "<<datos.marca<<" Estatus: En Proceso.";
			}
		    return os;  
		}	
		bool operator<(const Vehiculo& datos){ 
			return (strcmpi(this->marca,datos.marca)<0);
		}
	char *getPlaca(){return placa;}
	char *getMarca(){return marca;}
	
	void setActivo(bool act){activo = act;}
};

#endif
