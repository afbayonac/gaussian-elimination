#include <omp.h>
#include "sistema-lineal.h"
#include <iostream>
#include<time.h>
#include <stdlib.h>     /* srand, rand */

using namespace std;

extern int hilos;

// Sl hace referencia al sistema lineal generado
//Constructor por omisi�n
Sl::Sl(){
	filas = 0;
	columnas = 0;
	elementos = NULL;
}

//Constructor por copia
Sl::Sl(const Sl& mat){
	int i,j;
	filas = mat.filas;
	columnas = mat.columnas;
	elementos = new double * [filas];
	for(i=0; i<filas; i++){
		elementos[i] = new double[columnas];
		for(j=0; j<columnas; j++){
			elementos[i][j] = mat.elementos[i][j];
		}
	}
}
Sl::Sl(const int n){
	int i, j;
	filas = n;
	columnas = n + 1;
	elementos = new double * [filas];
	for(i=0; i<filas; i++){
		elementos[i] = new double[columnas];
	}
}

//Destructor
Sl::~Sl(){
	delete [] elementos;
}

//M�todos de acceso
double Sl::Elemento(const int i, const int j){
	return this->elementos[i][j];
}

int Sl::Filas(){
	return filas;
}

int Sl::Columnas(){
	return columnas;
}

void Sl::Mostrar(){
	int i, j;
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			cout<<elementos[i][j]<<" ";
		}
		cout<<endl;
	}
}

//M�todos de modificaci�n
void Sl::asignarElemento(const int i, const int j,
  const double val){
	elementos[i][j] = val;
}

void Sl::Inicializar(const int valor){
	int i, j;
	srand(time(NULL));
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			elementos[i][j] = rand() % valor;
		}
	}
}

// Metodo de eliminacion gaussiana pivote
void Sl::Resolve(){
	int i;
	int j = 0;
	int k = 0;
	double c;

	for(k = 0; k < columnas - 1; k++ ){
		for(i = k + 1; i < filas; i++){
			// s i  i-s*(i/s)
			c = elementos[i][k] / elementos[k][k];
			elementos[i][k] = 0;
			for(j = k + 1; j < columnas; j++){
				elementos[i][j] -= (elementos[k][j] * c);
			}
		}
	}

	for(k = filas -1; k >= 0 ; k-- ){
		for(j = columnas-2; j > k; j--) {
			elementos[k][columnas - 1] -= elementos[k][j] * elementos[j][columnas - 1];
			elementos[k][j] = 0;
		}
		elementos[k][columnas -1]  /= elementos[k][k];
		elementos[k][k] = 1;
	}
}


ostream& operator << (ostream& out, const Sl &m){
	int i,j;
	for(i=0; i<m.filas; i++){
		for(j=0; j<m.columnas; j++){
			cout << m.elementos[i][j] << " ";
		}
		cout << endl;
	}
}
