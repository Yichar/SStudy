/*************************************************************************
	> File Name: 7.fflush.c
	> Author: Yichar
	> Mail: 
	> Created Time: 五  1/15 23:21:31 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {

    FILE *fp = fopen("test07.txt", "w+");
    
    char m = 0;
    while (1) {

        scanf("%c", &m);
        if (m == ':') break;
        
        fflush(fp); //手动刷新缓冲区到磁盘
        fputc(m,fp);

    }
    fclose(fp);


    return 0;
}
