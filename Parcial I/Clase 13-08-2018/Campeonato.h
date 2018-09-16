#ifndef CAMPEONATO_H
#define CAMPEONATO_H
#include <iostream>
#include <string.h>

using namespace std;
class Campeonato{
	int cedula;
	string nombre;
	int nroCarril;
	int tiempo;
	public:
		Campeonato(){}
		Campeonato(int ced,string nom,int nro,int time){
			this->cedula = ced;
			this->nombre = nom;
			this->nroCarril = nro;
			this->tiempo = time;
		}
		bool operator>(const Campeonato& datos){ 
			return (this->tiempo < datos.tiempo);
		}
		friend ostream& operator<<(ostream& os, const Campeonato& datos){  
	    	os<<"Tiempo: "<<datos.tiempo<<"seg"<<"\t"<<" Nombre: "<<datos.nombre<<"\t"<<" Cedula: "<<datos.cedula<<"\t"<<" Nro Carril: "<<datos.nroCarril<<endl;
		    return os;  
		}
		string getNombre(){
			return nombre;
		}
		void setTiempo(int time){
			this->tiempo = time;
		}
	
};

#endif
