#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
		char nombre[20];
		char apellido[20];
		int cedula;	
	public:
		bool operator<( Persona &x ) { 
			return /*strcmpi(cedula, x.cedula) < 0*/cedula<x.cedula; 
		}
		Persona(){
		}
		Persona(char nombre[], char apellido[], int cedula){
			strcpy(this->nombre, nombre);
			strcpy(this->apellido, apellido);
			this->cedula = cedula;
		}
		void imprimir() {
			std::cout << cedula << " " << nombre << " " << apellido << std::endl;
		}
//		void setValue(char value[]) { strcpy(this->apellido, value); };
		void setValue(int value) { this->cedula = value; };

};

#endif
