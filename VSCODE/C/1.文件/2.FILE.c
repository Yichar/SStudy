/*************************************************************************
	> File Name: 2.FILE.c
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/14 11:39:20 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() {

    FILE *fp = fopen("test1.txt","w+");
    if( fp == NULL){
        perror("fopen");
        return -1;
    }
    char buff[128];
    while(1) {
        fgets(buff,128,stdin);
        if (strcmp(buff,":wq\n") == 0)
            break;
        fputs(buff,fp);


    }
    fclose(fp);
    return 0;

}
