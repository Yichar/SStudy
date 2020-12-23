#!/bin/bash



declare -a Str
read -a Str
echo ${Str[*]}|tr ' ' '\n'|sort |uniq -c|sort -rn|head -n 3
