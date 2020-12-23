#!/bin/bash


Start=$1
End=$2

function Usage(){
    echo "Usage : $0 start_num end_num"
    exit
}

function is_prime(){
    num=$1
    local i
    for (( j=2;j<$num;j++ ));do
        if [[ $[ $num % $j ] -eq 0 ]];then
            return 1
        fi
    done
    return 0
}

if [[ $# -ne 2 ]];then
    Usage
fi
if [[ $Start -lt 2 ]]; then
    Start=2
fi
for (( i=$Start; i<=$End; i++ ));do
    is_prime $i
#    set +x   #调试
    if [[ $? -eq 0 ]];then
        echo $i
    fi
 #   set -x
done
