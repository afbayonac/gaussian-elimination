#!/bin/bash
#SBATCH --job-name=OpenMPtest
#SBATCH --output=openmp.out
#SBATCH --error=openmp.err
#SBATCH --time=01:00:00
#SBATCH --partition=manycores24
#SBATCH --men=34000

iteraciones=`expr 2`

for j in 2 4 #
6 8 14 18 24
  do
  export OMP_NUM_THREADS=$j
  for (( n = 100; n <= 30000; n = n + 100 ))
    do
      sum=`expr 0`
      echo n=$n hilos=$j &>> salida_$j
      for (( i = 0; i <= iteraciones; i++ ))
        do
          echo $( ./run $n ) >> salida_$j
        done
    done
  done
