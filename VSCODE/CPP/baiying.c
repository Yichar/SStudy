/*************************************************************************
	> File Name: 1.c
	> Author: Yichar
	> Mail: 
	> Created Time: 二  1/26 14:43:24 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {


    int n;
    int sum = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n; i++) {
        int temp = i;
        if (temp % 2 == 1) 
            sum += temp + 1;
        else if (temp % 10 ==0)
            sum += temp / 10;
        else
            sum += temp;
    }
    printf("%d",sum);


}
