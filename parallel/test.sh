#!/bin/bash

for i in 2 4 6 8 16 24
do
  export OMP_NUM_THREADS=$i
  echo $( ./run 10 )
done
