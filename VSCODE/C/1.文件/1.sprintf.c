/*************************************************************************
	> File Name: 1.sprintf.c
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/14 16:20:18 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {


    int n= 1;
    char c[100] ;
    scanf("%[^\n]s",c);
    FILE *fp = fopen("abc.txt","w+");
    if (!fp) perror("fopen");
    
    fprintf(fp,"您写入了：%s",c);
    fclose(fp);


}
