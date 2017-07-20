#include <omp.h>
#include "sistema-lineal.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;


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
	elementos = new float * [filas];
	for(i=0; i<filas; i++){
		elementos[i] = new float[columnas];
		for(j=0; j<columnas; j++){
			elementos[i][j] = mat.elementos[i][j];
		}
	}
}
Sl::Sl(const int n){
	int i, j;
	filas = n;
	columnas = n + 1;
	elementos = new float * [filas];
	for(i=0; i<filas; i++){
		elementos[i] = new float[columnas];
	}
}

//Destructor
Sl::~Sl(){
	delete [] elementos;
}

//M�todos de acceso
float Sl::Elemento(const int i, const int j){
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
  const float val){
	elementos[i][j] = val;
}

void Sl::Inicializar(const int valor){
	int i, j;
	#pragma omp parallel for private(j)
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

	for(k = 0; k < filas; k++ ){

		#pragma omp parallel for  private(i, j, c) 
		for(i = k; i < filas - 1; i++){
			// s i  i-s*(i/s)
			c = elementos[i+1][k] / elementos[k][k];
			elementos[i + 1][k] = 0;
			for(j=k+1; j < columnas; j++){
				elementos[i + 1][j] -= elementos[k][j] * c;
			}
		}
	}

	for(k = filas -1; k >= 0 ; k-- ){
		double sum = 0.0;
		for(j = columnas-2; j > k; j--) {
			sum = sum + elementos[k][j] * elementos[j][columnas - 1];
			elementos[k][j] = 0;
		}
		elementos[k][columnas - 1] = elementos[k][columnas - 1] - sum;
		elementos[k][columnas - 1] = elementos[k][columnas - 1] / elementos[k][k];
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
