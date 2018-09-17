#ifndef ITUNES_H
#define ITUNES_H

using namespace std;
class iTunes{
	string genero;
	string album;
	string artista;
	string cancion;
	string tam;
	public:
		iTunes(){}
		iTunes(string gen,string alb,string art,string canc,string tam){
			this->genero = gen;
			this->album = alb;
			this->artista = art;
			this->cancion = canc;
			this->tam = tam;
		}
		
//		bool operator>(const Genero& datos){ 
//			return (strcmpi(this->genero.c_str(),datos.genero.c_str())>0);
//		}
//		bool operator<(const Genero& datos){ 
//			return (strcmpi(this->genero.c_str(),datos.genero.c_str())<0);
//		}
		
		friend ostream& operator<<(ostream& os, const iTunes& datos){  
			os<<"Genero: "<<datos.genero<<" | Artista: "<<datos.artista<<" | Album: "<<datos.album<<" | Cancion: "<<datos.cancion<<endl;
		    return os;  
		}

		string getGenero(){return genero;}
		string getArtista(){return artista;}
		string getAlbum(){return album;}
		string getCancion(){return cancion;}
		string getTam(){return tam;}
		
		void setGenero(string g){this->genero = g;}
		void setArtista(string a){this->artista = a;}
		void setAlbum(string al){this->album = al;}
		void setCancion(string c){this->cancion = c;}
};

#endif
