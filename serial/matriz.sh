#!/bin/bash
#SBATCH --job-name=OpenMPtest
#SBATCH --output=openmp.out
#SBATCH --error=openmp.err
#SBATCH --time=01:00:00
#SBATCH --partition=manycores24

cd ~/MatrizFloat
for tam in 10 20 30 40
do
	for hilo in 4 8 16
	do
		export OMP_NUM_THREADS=$hilo
		echo H=$hilo tam=$tam &>> salida
		{ time ./matriz $tam ; } 2>&1 | grep real >> salida
	done
done
