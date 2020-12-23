#!/bin/bash



#read -a A

# ${A[1]} 元素
# ${#A[*]} 长度
# ${A[*]} 输出所有元素
# ${!A[*]} 输出所有下标
# A+=(2 3 4) 追加
# sort
# unset A 删除数组元素
#   unset A[1]
declare -a A
A=(`seq 1 100`)
#files=(`ls`)



function is_prime() {
    Start=0
    End=$1
    declare -a P
    #初始化
    for ((i=$Start;i<=$End;i++));do
        P[i]=0
    done
    
    for ((i=2;i<=$End;i++));do
        if [[ ${P[$i]} -eq 0 ]];then
            P[0]=$[ ${P[0]} + 1 ]
            P[${P[0]}]=$i
            
        fi
        P_one=${P[i]}
        for ((j=0;j<=$End;j++));do
            echo ${P[$j]}
        done
    done

}


is_prime $1
