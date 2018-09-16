#ifndef CANCION_H
#define CANCION_H
/**
	Ordenacion por Cancion
*/
using namespace std;
class Cancion{
	string genero;
	string album;
	string artista;
	string cancion;
	string tam;
	public:
		Cancion(){}
		Cancion(string gen,string alb,string art,string canc,string tam){
			this->genero = gen;
			this->album = alb;
			this->artista = art;
			this->cancion = canc;
			this->tam = tam;
		}
		
		bool operator>(const Cancion& datos){ 
			return (strcmpi(this->cancion.c_str(),datos.cancion.c_str())>0);
		}
		bool operator<(const Cancion& datos){ 
			return (strcmpi(this->cancion.c_str(),datos.cancion.c_str())<0);
		}
		
		friend ostream& operator<<(ostream& os, const Cancion& datos){  
			os<<"Cancion: "<<datos.cancion<<endl;
//	    	os<<"Genero: "<<datos.genero<<" \t"<<" Artista: "<<datos.artista<<" \t"<<" Album: "<<datos.album<<" \t"<<" Cancion: "<<datos.cancion<<endl;
		    return os;  
		}
};

#endif
