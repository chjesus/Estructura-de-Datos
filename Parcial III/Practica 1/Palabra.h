#ifndef PALABRA_H
#define PALABRA_H

using namespace std;
class Palabra{
	char palabra[50];
	int contador;
	public:
		Palabra(){}
		Palabra(char *pal,int cont){
			strcpy(this->palabra,pal);
			this->contador = cont;
		}
		bool operator<(const Palabra& datos){ 
			return (strcmpi(this->palabra,datos.palabra)<0);
		}
		bool operator>(const Palabra& datos){ 
			return (strcmpi(this->palabra,datos.palabra)>0);
		}
		friend ostream& operator<<(ostream& os, const Palabra& datos){  
	    	os<<"Palabra: "<<datos.palabra<<" | Repeticiones: "<<datos.contador;
		    return os;  
		}
		bool operator==(const Palabra& datos){
			return this->contador==datos.contador;
		}
		char *getPalabra(){return palabra;}
		int getContador(){return contador;}
		
		void setPalabra(char *pal){strcpy(this->palabra,pal);}
		void setContador(int cont){this->contador += cont;}
};

#endif
