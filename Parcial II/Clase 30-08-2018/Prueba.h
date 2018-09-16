#ifndef PRUEBA_H
#define PRUEBA_H

#include <string.h>
using namespace std;
class Prueba{
	public:
	int cedula;
	char nombre[40];
	public:
		Prueba(){}
		Prueba(int ced, char *nom){
			this->cedula = ced;
			strcpy(this->nombre,nom);
		}
		friend ostream& operator<<(ostream& os, const Prueba& dt) {  
	    os << "Cedula: "<<dt.cedula << " Nombre: " << dt.nombre << endl;
		    return os;  
		} 
};

#endif
