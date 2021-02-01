/*************************************************************************
	> File Name: 11.c
	> Author: Yichar
	> Mail: 
	> Created Time: 六  1/30 20:36:20 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main() {


    int sum = 0;
    for( int i = 1; i <= 1000; i++) {
        if( i % 2 == 0 && i % 3 == 0)
            sum++;
    }
    printf("%d",sum);

}
