#!/bin/bash



a="hello F"
b="q"
#硬转义 取消特殊字符含有
c='$a$b'
#软转义 
d="$a$b"
echo $a
echo $b
echo $c
echo $GRE$a$ENDC
echo -e "\033[031m hello LL \033[0m"
echo -e "\033[031m $a \033[0m"

# $$ 当前进程PID
# $! 上一个进程PID
# $? 接收返回值
# $0路径
# $n 第n个参数
# $* 将传入参数视为单个字符串 相当于“$1$2$3”
# $# 参数个数
# $@ 获取所有参数，并保留参数间空白 "$1" "$2" "$3"

