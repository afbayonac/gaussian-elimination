#!/bin/bash
#OAR -n prueba
#PARA LANZAR UNA TAREA CON ESTE SCRIPT EJECUTE
#  oarsub -l core=24 "./matrizOAR.sh 1000"


cd ~/MatrizFloat
if [ $# -ne 2 ]
then
        echo "oarsub -l core=N matriz.sh <tamano>"
        exit
else
	for i in 2 4 6 8 14 18 24
	do
		echo working with $i
		export OMP_NUM_THREADS=$i
        	(time ./matriz $1) &> salida$i-$1
	done
fi
