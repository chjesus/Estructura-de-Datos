#ifndef ALUMNOS_H
#define ALUMNOS_H

using namespace std;
class Alumnos{
	public:
	int cedula;
	char nombre[40];
	int tel_celular;
	float indice;
	char carrera[40];
	public:
		Alumnos(){}
		Alumnos(int ced,char *nom,int tel,float ind,char *car){
			this->cedula = ced;
			strcpy(this->nombre,nom);
			this->tel_celular = tel;
			this->indice = ind;
			strcpy(this->carrera,car);
		}
		bool operator<( Alumnos &x ) { 
			return strcmpi(nombre, x.nombre) < 0; 
		}
		void setValue(char value[]) { strcpy(this->nombre, value); };
		void imprimir(){
			cout<<"Cedula: "<<cedula<<" Nombre: "<<nombre<<" Celular: "<<tel_celular<<" Indice: "<<indice<<endl;
		}
		
		char *getNombre(){return nombre;}
		int getCedula(){return cedula;}
		int getCelular(){return tel_celular;}
};

#endif
