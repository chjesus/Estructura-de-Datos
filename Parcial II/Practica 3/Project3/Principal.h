#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ListaEnlazada.h"
class Principal{
	vector<int> vectList1;
	vector<int> vectList2;
	vector<int> vectFinal;

	ListaEnlazada<int> *lista = new ListaEnlazada<int>;
	int numeroDatos;
	int codigo;
	public:
		Principal(){}
		~Principal(){}
		void llenarListas(ListaEnlazada<int> &lista1, ListaEnlazada<int> &lista2){
			int aux=1;
			srand(time(NULL));
			numeroDatos = rand() % 100 + 20;
			cout << "Tamaño de la Lista creada: " << numeroDatos*2 << endl << endl;
			for (int i = 0; i < numeroDatos; i++){
				codigo = rand() % 1000 + 100;
				lista1.Anadir(codigo);
			}

			for (int i = 0; i < numeroDatos; i++){
				codigo = rand() % 1000 + 100;
				lista2.Anadir(codigo);
			}

			lista1.concat(lista2);
			lista->concat(lista1);


			for (int i = 0; i < numeroDatos*2; i++){
				if (aux == 1){
					lista1.Leer();
					vectList1.push_back(lista->Leer());
					aux = 0;
				}
				if (aux == 0){
					lista2.Leer();
					vectList2.push_back(lista->Leer());
					aux = 1;
				}
			}
		}
		void imprimirListasIntercalados(ListaEnlazada<int> &lista1, ListaEnlazada<int> &lista2){
			cout << "Particion Intercalada 1" << endl << endl;
			for (int i = 0; i < vectList1.size()/2; i++){
				cout << vectList1[i] << " ";
				if (i % 10 == 0) cout << endl;
				lista1.Anadir(vectList1[i]);
			}
			cout << endl << endl << "Particion Intercalada 2" << endl << endl;
			for (int i = 0; i < vectList2.size() / 2; i++){
				cout << vectList2[i] << " ";
				if (i % 10 == 0) cout << endl;
				lista2.Anadir(vectList2[i]);
			}

			for (int i = 0; i < vectList1.size() / 2; i++){
				lista->Anadir(vectList1[i]);
				lista->Anadir(vectList2[i]);
			}
			cout << "Total:" << endl;
			//lista->Imprimir();

			for (int i = 0; i < numeroDatos*2; i++){
				vectFinal.push_back(lista->Leer());
			}
			inicioBusquedaBinaria(vectFinal,vectFinal.size());
		}
		void inicioBusquedaBinaria(vector<int> &vectFinal, int tam){
			int codigo;
			bool band = false;
			bool bandAux = true;
			int Iarriba = tam - 1;
			int Iabajo = 0;
			int Icentro;

				if (numeroDatos * 2 >= 100){
					cout << endl << "Ingrese el Codigo a buscar: ";
					cin >> codigo;

					while (Iabajo <= Iarriba){
						Icentro = (Iabajo + Iarriba) / 2;
						if (codigo == vectFinal[Icentro]){
							Icentro;
							band = true;
							break;
						}
						else if (codigo < vectFinal[Icentro]){
							Iarriba = Icentro - 1;
						}
						else{
							Iabajo = Icentro + 1;
						}
					}
				}else{
					cout << endl << "No inicia la busqueda binaria" << endl;
					bandAux = false;
				}

				if (bandAux == true){
					if (band == true){
						cout << "Dato Encontrado: " << vectFinal[Icentro] << endl << endl;
					}
					else{
						cout << endl << "Dato no Encontrado" << endl << endl;
					}
				}
			system("PAUSE");
		}
		
};
