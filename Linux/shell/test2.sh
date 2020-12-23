#!/bin/bash


Start=2
End=1000


declare -a prime
for (( i=2; i<=${End}; i++ ));do
    if [[ ${prime[$i]}x == x ]]; then #空的
        prime[0]=$[${prime[0]} + 1]
        prime[${prime[0]}]=$i
    fi
    for((j=1;j<=${prime[0]}; j++ ));do
        if [[ $[ $i * ${prime[$j]} ] -gt ${End} ]];then
            break
        fi
        prime[$[ $i * ${prime[$j]} ]]=1
        if [[ $[ $i % ${prime[$j]} ] -eq 0 ]];then
            break
        fi
    done
done
read N
echo ${prime[$N]}
