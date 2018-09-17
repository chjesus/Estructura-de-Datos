#ifndef PERSONAS_H
#define PERSONAS_H

class Personas{
	int clave;
	string cedula;
	string nombre;
	int taquilla;
	public:
		Personas(){}
		Personas(int cla,int taq){
			this->clave = cla;
			this->taquilla = taq;
		}
		Personas(string ced,string nom){
			this->cedula = ced;
			this->nombre = nom;
		}
		Personas(int cla,string ced,string nom){
			this->clave = cla;
			this->cedula = ced;
			this->nombre = nom;
		}
		friend ostream& operator<<(ostream& os, const Personas& datos){  
			os<<"Clave: "<<setfill('0')<<setw(3)<<datos.clave<<" | Cedula: "<<datos.cedula<<" | Nombre: "<<datos.nombre<<endl;
		    return os;  
		}
		bool operator<(const Personas& datos){ 
			return (this->clave < datos.clave);
		}
		int getClave(){return clave;}
		string getCedula(){return cedula;}
		string getNombre(){return nombre;}
		int getTaquilla(){return taquilla;}
};

#endif
