#ifndef ITUNES_H
#define ITUNES_H
/**
	Ordenacion por Genero
*/
using namespace std;
class Genero{
	string genero;
	string album;
	string artista;
	string cancion;
	string tam;
	public:
		Genero(){}
		Genero(string gen,string alb,string art,string canc,string tam){
			this->genero = gen;
			this->album = alb;
			this->artista = art;
			this->cancion = canc;
			this->tam = tam;
		}
		
		bool operator>(const Genero& datos){ 
			return (strcmpi(this->genero.c_str(),datos.genero.c_str())>0);
		}
		bool operator<(const Genero& datos){ 
			return (strcmpi(this->genero.c_str(),datos.genero.c_str())<0);
		}
		
		friend ostream& operator<<(ostream& os, const Genero& datos){  
			os<<"Genero: "<<datos.genero<<endl;
//			os<<"Genero: "<<datos.genero<<" \t"<<" Artista: "<<datos.artista<<" \t"<<" Album: "<<datos.album<<" \t"<<" Cancion: "<<datos.cancion<<endl;
		    return os;  
		}
};

#endif
