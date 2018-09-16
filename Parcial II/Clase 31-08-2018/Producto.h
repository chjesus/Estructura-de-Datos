#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string.h>

using namespace std;
class Producto{
	int codigo;
	char descripcion[30];
	float precio;
	public:
		Producto(){}
		Producto(int codigo,char *des,float pre){
			this->codigo = codigo;
			strcpy(this->descripcion,des);
			this->precio = pre;
		}

		int getCodigo(){return codigo;}
		char *getDescripcion(){return descripcion;}
		float getPrecio(){return precio;}
		
		void setCodigo(int cod){this->codigo = cod;}
		void setDescripcion(char *des){strcpy(this->descripcion,des);}
		void setPrecio(float pre){this->precio = pre;}
		
		bool operator<(const Producto& datos){
			return this->codigo<datos.codigo;
		}
		bool operator==(const Producto& datos){
			return this->codigo==datos.codigo;
		}
		friend ostream& operator<<(ostream& os, const Producto& datos){
			os<<"Codigo: "<<datos.codigo<<" Descripcion: "<<datos.descripcion<<" Precio: "<<datos.precio<<endl;
			return os;
		}
};

#endif
