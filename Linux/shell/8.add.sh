#!/bin/bash


for i in `seq 1 100`;do
    if [[ $[ $i % 2] -eq 0 ]];then
        sum=$[ $sum +$i ]
    fi
done
echo $sum
