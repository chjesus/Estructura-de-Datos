#include <iostream>
#include "Prueba.h"
#include "ListaDobCircular.h"
int main(int argc, char** argv) {
//	Prueba a(12,"Hola");
//	Prueba b(32,"asd");
//	Prueba c(41,"rr");
//	Prueba d(1,"rr");
//	ListaDobCircular<Prueba> list;
//	
//	list.AgregarSinOrden(a);
//	list.AgregarSinOrden(b);
//	list.AgregarSinOrden(c);
//	list.Imprimir(1);
//	list.eliminar();
//	cout<<endl<<endl;
//	list.AgregarSinOrden(d);
//	list.Imprimir(1);
	ListaDobCircular<int> list;
	list.Agregar(2);
	list.Agregar(3);
	list.Imprimir(1);
	list.eliminar();
	list.Imprimir(1);
	return 0;
}
