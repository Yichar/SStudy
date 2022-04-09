/*************************************************************************
	> File Name: 1.打印任意类型.c
	> Author: Yichar
	> Mail: 
	> Created Time: 二  1/19 21:42:05 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


void printText(void *data, void(*myprint)(void *)) {
    myprint(data);

}
void myprintInt(void *data) {

    int *num = data;
    printf("%d\n",*num);
}
void test01() {

    int a = 10;
    printText(&a, myprintInt);

}


int main() {

    test01();

}
