#include <iostream>
#include <vector>

#include "Archivo.h"
#include "Datos.h"
#include "Alumnos.h"
#include "Materias.h"

using namespace std;
int main(int argc, char** argv) {
	/* Declaracion del Programa */
	fstream fichero,ficheroAlum;
	char nombreArchivo[40] = "evaluacion.txt";
	Archivo<Datos> *leer = new Archivo<Datos>(nombreArchivo);
	vector<Alumnos> listaAlum;
	vector<Materias> listaMat;
	vector<Datos> listaDatos;
	Datos data;
	
	Materias *datMat;
	Alumnos *datAlum;
	Datos *datos = new Datos();
	int cont,tam,enc;
	float notaAux,notaFinal;
	
	/* Inicio del Programa */
	/*Parte A*/
	leer->abrirFichero();
	tam = leer->tamArchivo();
	leer->cerrarFichero();
	
	leer->abrirFichero();
	leer->crearArchivoBinario();
	leer->cerrarFichero();
	
	Alumnos aux(0,"");
	listaAlum.push_back(aux);
	for(int i=0;i<tam;i++){
		leer->abrirFichero();
		data = leer->devolverObjeto(i,cont);
			for(int j=0;j<listaAlum.size();j++){
				if(listaAlum[j].getCodigo() == 0){
					listaAlum[j].setCodigo(data.getCodigoAlum());
					listaAlum[j].setNombre(data.getNombreAlum());
				}
				if(data.getCodigoAlum() == listaAlum[j].getCodigo()){
					enc = 1;
				}
			}
			if(!enc){
				Alumnos d(data.getCodigoAlum(),data.getNombreAlum());
				listaAlum.push_back(d);
			}enc=0;
		leer->cerrarFichero();
	}
	
	enc = 0;
	Materias auxM(0,"");
	listaMat.push_back(auxM);
	for(int i=0;i<tam;i++){
		leer->abrirFichero();
		data = leer->devolverObjeto(i,cont);
			for(int j=0;j<listaMat.size();j++){
				if(listaMat[j].getCodigo() == 0){
					listaMat[j].setCodigo(data.getCodigoMat());
					listaMat[j].setNombre(data.getNombreMat());
				}
				if(data.getCodigoMat() == listaMat[j].getCodigo()){
					enc = 1;
				}
			}
			if(!enc){
				Materias m(data.getCodigoMat(),data.getNombreMat());
				listaMat.push_back(m);
			}enc=0;
		leer->cerrarFichero();
	}
	
	fichero.open("alumno.dat",ios::out);
	for(int j=0;j<listaAlum.size();j++){
		datAlum = new Alumnos(listaAlum[j].getCodigo(),listaAlum[j].getNombre());
		fichero.write(reinterpret_cast<char*>(datAlum),sizeof(Alumnos));
	}
	fichero.close();
	
	fichero.open("materia.dat",ios::out);
	for(int j=0;j<listaMat.size();j++){
		datMat = new Materias(listaMat[j].getCodigo(),listaMat[j].getNombre());
		fichero.write(reinterpret_cast<char*>(datMat),sizeof(Materias));
	}
	fichero.close();
	
	/*Parte B*/
	listaMat.clear();
	fichero.open("materia.dat",ios::binary | ios::in);
		while(!fichero.eof() && fichero.read(reinterpret_cast<char*>(datMat),sizeof(Materias))){
			listaMat.push_back(*datMat);
		}
	fichero.close();
	
	listaAlum.clear();
	fichero.open("alumno.dat",ios::binary | ios::in);
		while(!fichero.eof() && fichero.read(reinterpret_cast<char*>(datAlum),sizeof(Alumnos))){
			listaAlum.push_back(*datAlum);
		}
	fichero.close();
	
	listaDatos.clear();
	fichero.open("datos.dat",ios::binary | ios::in);
		while(!fichero.eof() && fichero.read(reinterpret_cast<char*>(datos),sizeof(Datos))){
			listaDatos.push_back(*datos);
		}
	fichero.close();
	
	/*Resultado Final*/
	notaAux=0.0;
	notaFinal=0.0;
	for(int i=0;i<listaMat.size();i++){
		cout<<listaMat[i].getNombre()<<endl;
			for(int j=0;j<listaAlum.size();j++){
				for(int k=0;k<listaDatos.size();k++){
					if(listaDatos[k].getCodigoAlum()==listaAlum[j].getCodigo() && listaDatos[k].getCodigoMat()==listaMat[i].getCodigo()){
						notaAux=listaDatos[k].getNota()*listaDatos[k].getPorcentaje();
						notaFinal +=(notaAux/100);
					}
				}
				if(notaFinal>50.0){
					cout<<listaAlum[j].getCodigo()<<" "<<listaAlum[j].getNombre()<<" "<<notaFinal<<endl;
				}notaFinal=0.0;
			}
	}
	return 0;
}
