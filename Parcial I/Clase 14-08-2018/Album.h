#ifndef ALBUM_H
#define ALBUM_H
/**
	Ordenacion por Album
*/
using namespace std;
class Album{
	string genero;
	string album;
	string artista;
	string cancion;
	string tam;
	public:
		Album(){}
		Album(string gen,string alb,string art,string canc,string tam){
			this->genero = gen;
			this->album = alb;
			this->artista = art;
			this->cancion = canc;
			this->tam = tam;
		}
		
		bool operator>(const Album& datos){ 
			return (strcmpi(this->album.c_str(),datos.album.c_str())>0);
		}
		bool operator<(const Album& datos){ 
			return (strcmpi(this->album.c_str(),datos.album.c_str())<0);
		}
		
		friend ostream& operator<<(ostream& os, const Album& datos){  
			os<<"Album: "<<datos.album<<endl;
//	    	os<<"Genero: "<<datos.genero<<" \t"<<" Artista: "<<datos.artista<<" \t"<<" Album: "<<datos.album<<" \t"<<" Cancion: "<<datos.cancion<<endl;
		    return os;  
		}
};

#endif
