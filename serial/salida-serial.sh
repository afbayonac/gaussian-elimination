##!/bin/bash

iteraciones=`expr 2`

for (( tam = 10; tam <= 200; tam = tam + 10 ))
  do
    sum=`expr 0`
    echo tam=$tam &>> salida
    for (( i = 0; i <= iteraciones; i++ ))
      do
        echo $(./run $tam) >> salida
      done
  done
