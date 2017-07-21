#ifndef SL_H
#define Sl_H
#include <omp.h>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
using namespace std;

class Sl {

	friend ostream& operator << (ostream& out, const Sl &m);

private:
	int filas, columnas;
	double **elementos;

public:
	//Constructores
	Sl();
	Sl(const Sl&);
	Sl(const int);
	//Destructor
	~Sl();

	//Métodos de acceso
	double Elemento(const int, const int);
	int Filas();
	int Columnas();
	void Mostrar();

	//Métodos de modificación
	void asignarElemento(const int, const int, const double);
	void Inicializar(const int);
	void Resolve();
	void Leer();

	//Métodos miscelaneos
	void sumarMatrices(const Sl& m);

	//Sobrecarga de operadores
	Sl operator = (const Sl&);
	Sl operator + (const Sl&);
	Sl operator * (const Sl&);

};
#endif
