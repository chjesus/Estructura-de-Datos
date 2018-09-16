#ifndef MP3_H
#define MP3_H

#include <string.h>

using namespace std;
class Mp3{
	char titulo[30];
	char autor[30];
	int tamKb;
	char album[30];
	char genero[30];
	public:
		Mp3(){}
		Mp3(char *tit,char *aut,int tam,char *alb,char *gen){
			strcpy(this->titulo,tit);
			strcpy(this->autor,aut);
			this->tamKb = tam;
			strcpy(this->album,alb);
			strcpy(this->genero,gen);
		}
		
		friend ostream& operator<<(ostream& os, const Mp3& datos){  
	    	os<<"Titulo: "<<datos.titulo<<" Auto: "<<datos.autor<<" Tamaño: "<<datos.tamKb<<" Kb"<< " Album: "<<datos.album<<" Genero: "<<datos.genero<<endl;
		    return os;  
		}
		
		int getTam(){return tamKb;}
};

#endif
