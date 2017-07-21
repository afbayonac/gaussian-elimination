#!/bin/bash

for i in 1 2 3 4 
do
  export OMP_NUM_THREADS=$i
  echo $( ./run 10 )
done
