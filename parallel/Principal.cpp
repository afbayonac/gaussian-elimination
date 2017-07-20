#include <omp.h>
#include "sistema-lineal.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

/* retorna "a - b" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}


int hilos = 0;

int main(int argc, char *argv[]){
	int size;
	struct timeval t_ini, t_fin;
	double secs;

	if(argc != 3){
		cout << "./run <tamano> <hilos>" << endl;
		return 1;
	}else{
    
		// init sistema de ecuacicones lineales
		size = atoi(argv[1]);
    hilos = atoi(argv[2]);
		Sl  sl(size);
		sl.Inicializar(100);

		// start time countes
		gettimeofday(&t_ini, NULL);

		sl.Resolve();

		// end time counter
		gettimeofday(&t_fin, NULL);

		// resultado en milliseconds que demoro la solucion del sistema
		secs = timeval_diff(&t_fin, &t_ini);
		printf("%.16g", secs * 1000.0);

		return 0;
	}
}
