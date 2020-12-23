#!/bin/bash

function Usage(){
    echo "Usage : $0 start_num end_num"
    exit
}





if [[ $# -ne 2 ]];then
    Usage
fi

Start=$1
End=$2


declare -a prime
sum=0
for (( i=2; i<=${End}; i++ ));do
    if [[ ${prime[$i]}x == x ]]; then #空的
        prime[0]=$[${prime[0]} + 1]
        prime[${prime[0]}]=$i
        sum=$[ ${sum} + $i ]
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

echo $sum
