#include "sistema-lineal.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int hilos = 0;

int main(int argc, char *argv[]){
	int size;

	if(argc != 2){
		cout << "sistema-lineal <tamano> => " << endl;
		return 1;
	}else{
		size = atoi(argv[1]);
		hilos = size;

		Sl  sl(size);
		sl.Inicializar(100);
		cout << sl;
		cout << endl;
		sl.Resolve();
		cout << sl;

		return 0;
	}
}
