#!/bin/bash


read L M

declare -a tree
while [[ $M -gt 0 ]];do
    read st en
    for((i=$st; $i <= $en; i++));do
        tree[$i]=1
    done
    M=$[$M - 1]
done

sum=0
for((i=0; $i <= $L; i++));do
    if [[ tree[$i] -eq 1 ]];then
        sum=$[$sum + 1]
    fi
done
L=$[$L + 1]
echo $[$L - $sum]
