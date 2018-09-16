#ifndef ARTISTA_H
#define ARTISTA_H
/**
	Ordenacion por Artista
*/
using namespace std;
class Artista{
	string genero;
	string album;
	string artista;
	string cancion;
	string tam;
	public:
		Artista(){}
		Artista(string gen,string alb,string art,string canc,string tam){
			this->genero = gen;
			this->album = alb;
			this->artista = art;
			this->cancion = canc;
			this->tam = tam;
		}
		
		bool operator>(const Artista& datos){ 
			return (strcmpi(this->artista.c_str(),datos.artista.c_str())>0);
		}
		bool operator<(const Artista& datos){ 
			return (strcmpi(this->artista.c_str(),datos.artista.c_str())<0);
		}
		
		friend ostream& operator<<(ostream& os, const Artista& datos){  
			os<<"Artista: "<<datos.artista<<endl;
//	    	os<<"Genero: "<<datos.genero<<"\t"<<"Artista: "<<datos.artista<<"\t"<<"Album: "<<datos.album<<"\t"<<"Cancion: "<<datos.cancion<<endl;
		    return os;  
		}
};

#endif
