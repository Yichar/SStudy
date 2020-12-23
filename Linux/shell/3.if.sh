#!/bin/bash
#man test

read a
if [[ $a -gt 10 ]];then
    echo "$a > 10"
elif [[ $a -le 5 ]];then
    echo "$a <= 5"
else
    echo "$a well"
fi
