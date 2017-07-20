#!/bin/bash

iteraciones=`expr 5`

for (( n = 100; n <= 3000; n = n + 100 ))
  do
    sum=`expr 0`
    echo n=$n hilos=&>> salida
    for (( i = 0; i <= iteraciones; i++ ))
      do
        echo $(./run $n) >> salida
      done
  done
