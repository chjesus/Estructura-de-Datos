#include <iostream>
#include "ArbolAVL.h"

using namespace std;
int main(int argc, char** argv) {
	ArbolAVL<int> arbol;
	
	arbol.Anadir(1);
	arbol.Anadir(2);	
	arbol.Anadir(3);
	arbol.Anadir(4);
	arbol.Anadir(5);
	arbol.Anadir(6);
	arbol.Anadir(7);
	arbol.Anadir(8);
	arbol.Anadir(9);
	arbol.Anadir(10);
	arbol.imprimir(2);
	return 0;
}
