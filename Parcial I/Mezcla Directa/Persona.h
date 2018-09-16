#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
		char nombre[20];
		char apellido[20];
		int cedula;	
	public:
		bool operator<( Persona &x ) { 
			return cedula<x.cedula; 
		}
//		bool operator<( Persona &x){
//			return strcmpi(nombre, x.nombre) < 0;
//		}
		Persona(){}
		Persona(char nombre[], char apellido[], int cedula){
			strcpy(this->nombre, nombre);
			strcpy(this->apellido, apellido);
			this->cedula = cedula;
		}
		void imprimir() {
			std::cout << cedula << " " << nombre << " " << apellido << std::endl;
		}
//		void setValue(char value[]) { strcpy(this->nombre, value); };
		void setValue(int value) { this->cedula = value; };

};

#endif
