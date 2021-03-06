#!/bin/bash
#SBATCH --job-name=gaussian
#SBATCH --partition=manycores24
#SBATCH --mem=34000

iteraciones=`expr 2`

for j in 2 4 8 16 24
  do
  export OMP_NUM_THREADS=$j
  for (( n = 100; n <= 3000; n = n + 100 ))
    do
      echo n=$n hilos=$j &>> salida_$j
      for (( i = 0; i <= iteraciones; i++ ))
        do
          echo $( ./run $n ) >> salida_$j
        done
    done
  done
