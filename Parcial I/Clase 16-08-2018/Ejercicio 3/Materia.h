#ifndef MATERIA_H
#define MATERIA_H

using namespace std;
class Materia{
	int codigo;
	char nombre[45];
	int unidCreditos;
	int cantEstudiantes;
	public:
		Materia(){}
		Materia(int cod,char *nom,int unidC,int cantEst){
			this->codigo = cod;
			strcpy(this->nombre,nom);
			this->unidCreditos = unidC;
			this->cantEstudiantes = cantEst;
		}
		void imprimir(){
			cout<<"Codigo: "<<codigo<<" Nombre: "<<nombre<<" UnidadCreditos: "<<unidCreditos<<" CantidadEstudinates: "<<cantEstudiantes<<endl;	
		}
		int getCodigo(){return codigo;}
		void setCantEstudiantes(int x){this->cantEstudiantes = x;}
};

#endif
