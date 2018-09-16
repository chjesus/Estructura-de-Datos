#ifndef PERSONAPOS_H
#define PERSONAPOS_H

using namespace std;
class PersonaPos{
	int cedula;
	int posicion;
	public:
		PersonaPos(){}
		PersonaPos(int ced,int pos){
			this->cedula = ced;
			this->posicion = pos;
		}
		bool operator<(const PersonaPos& datos){ 
			return this->cedula<datos.cedula;
		}
		bool operator>(const PersonaPos& datos){ 
			return this->cedula>datos.cedula;
		}
		friend ostream& operator<<(ostream& os, const PersonaPos& datos){  
	    	os<<"Cedula: "<<datos.cedula<<" | Posicion: "<<datos.posicion;
		    return os;  
		}
		bool operator==(const PersonaPos& datos){
			return this->cedula==datos.cedula;
		}
		
		int getPosicion(){return posicion;}
};

#endif
