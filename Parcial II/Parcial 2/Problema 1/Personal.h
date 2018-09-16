#ifndef PERSONAL_H
#define PERSONAL_H

#include <string.h>

using namespace std;
class Personal{
	int id;
	char nombre[40];
	bool activo;
	int precio;
	public:
		Personal(){}
		Personal(int id,char *nom,bool act,int pre){
			this->id = id;
			strcpy(this->nombre,nom);
			this->activo = act;
			this->precio = pre;
		}
		friend ostream& operator<<(ostream& os, const Personal& datos){  
			if(datos.activo == true && datos.precio==0){
				os<<"ID: "<<datos.id<<" | Nombre: "<<datos.nombre<<" | Estatus: Libre";
			}else if(datos.activo == true && datos.precio>0){
				os<<"ID: "<<datos.id<<" | Nombre: "<<datos.nombre<<" | Estatus: Libre"<<" | Monto Recaudado: "<<datos.precio;
			}else{
				os<<"ID: "<<datos.id<<" | Nombre: "<<datos.nombre<<" | Estatus: Ocupado";
			}
		    return os;  
		}
		bool operator<(const Personal& datos){ 
			return this->id < datos.id;
		}
		bool operator==(const Personal& datos){
			return this->id==datos.id;
		}
		int getId(){return id;}
		char *getNombre(){return nombre;}
		bool getActivo(){return activo;}
		int getPrecio(){return precio;}
		
		void setPrecio(int pre){ precio += pre;}
		void setActivo(bool act){activo = act;}
};

#endif
