#include <iostream>

#include "Principal.h"
#include "Personas.h"

using namespace std;
int main(int argc, char** argv) {
	Principal<Personas> inicio;
	inicio.Menu();
	return 0;
}
