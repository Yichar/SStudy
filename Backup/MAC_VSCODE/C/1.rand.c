/*************************************************************************
	> File Name: 1.rand.c
	> Author: Yichar
	> Mail: 
	> Created Time: 三  1/13 21:21:46 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(1);
    for(int i = 0; i < 10; i++) 
        printf("%d ",rand() % 10);

    return 0;

}
