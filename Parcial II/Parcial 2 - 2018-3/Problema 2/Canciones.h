#ifndef CANCIONES_H
#define CANCIONES_H

#include <string.h>

using namespace std;
class Canciones{
	char titulo[30];
	char autor[30];
	int tama;
	char album[30];
	char genero[30];
	public:
		Canciones(){}
		Canciones(char *ti,char *aut,int tam,char *alb,char *gen){
			strcpy(this->titulo,ti);
			strcpy(this->autor,aut);
			this->tama = tam;
			strcpy(this->album,alb);
			strcpy(this->genero,gen);
		}
		
		char *getTitulo() {	return titulo;}
		char *getAutor() {	return autor;}
		int getTama(){return tama;}
		char *getAlbum() {	return album;}
		char *getGenero() {	return genero;}
		
		void setTitulo(char *ti) {	strcpy(this->titulo,ti);}
		void setAutor(char *aut) {	strcpy(this->autor,aut);}
		void setTama(int tam){	this->tama = tam;}
		void setAlbum(char *alb) {	strcpy(this->album,alb);}
		void setGenero(char *gen) {	strcpy(this->genero,gen);}
		
		bool operator<(const Canciones& datos){
			return strcmpi(this->titulo,datos.titulo)<0;
		}
		bool operator==(const Canciones& datos){
			return (strcmpi(this->titulo,datos.titulo)==0);
		}
		friend ostream& operator<<(ostream& os, const Canciones& datos){
			os<<"Titulo: "<<datos.titulo<<" Autor: "<<datos.autor<<" Tamaño: "<<" KB"<<datos.tama<<" Album: "<<datos.album;
			return os;
		}
};

#endif
