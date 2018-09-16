#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string.h>

using namespace std;

class Usuario{
	int number;
	string Nombre;
	public:
		Usuario(){}
		Usuario(int num,string nombre){
			this->number = num;
			this->Nombre = nombre;
		}
		int getNumber(){
			return number;
		}
		bool operator==(Usuario &a) { return this->number==a.number; }
		friend ostream & operator<<(  ostream &os, Usuario  imp ) { 
        	os<< " "<<imp.number<<"  "<<imp.Nombre; 
        	return os;
      	} 
};

#endif
