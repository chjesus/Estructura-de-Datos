#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;
class Datos{
	int codigoAlumno;
	string nombreAlumno;
	int codigoMateria;
	string nombreMateria;
	float notaParcial;
	int porcentaje;
	
	public:
		Datos();
		Datos(int codAlumno,string nomAlumno,int codMateria,string nomMateria,float nota,float porc);
		
		/*SobreCarga para Burbuja y shell */
		bool operator>(const Datos& datos){ 
			return (this->nombreAlumno > datos.nombreAlumno);
		}

		/*SobreCarga para Selecion y Inserccion Directa */
		bool operator<(const Datos& datos){ 
			return (this->codigoAlumno < datos.codigoAlumno);
		}
		/*SobreCargar para MergeSort*/
		bool operator<=(const Datos& datos){ 
			return (this->codigoAlumno <= datos.codigoAlumno);
		}
		
		friend ostream& operator<<(ostream& os, const Datos& datos){  
	    	os<<"Numero: "<<datos.codigoAlumno<<" Nombre: "<<datos.nombreAlumno<<" Materia: "<<datos.nombreMateria<<" CodigoMat"<<datos.codigoMateria<<endl;
		    return os;  
		}
		int getCodigoAlum(){
			return codigoAlumno;
		}
		string getNombreAlum(){
			return nombreAlumno;
		}
		int getCodigoMat(){
			return codigoMateria;
		}
		string getNombreMat(){
			return nombreMateria;
		}
		float getNota(){
			return notaParcial;
		}
		int getPorcentaje(){
			return porcentaje;
		}
};

#endif
