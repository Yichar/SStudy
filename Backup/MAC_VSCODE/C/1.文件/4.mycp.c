/*************************************************************************
	> File Name: 4.mycp.c
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/14 21:32:18 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main(int argc,char **argv) {

    FILE *fp = fopen("./Wechar.mp4","r");
    FILE *nfp = fopen("./new.mp4","w");
    size_t temp;
    char buff[2048];
    while ((temp = fread(buff, 1, sizeof(buff) * 1, fp)) > 0 ) {
        fwrite(buff, 1, temp, nfp);
        buff[0] = '\0';
    }
    fclose(fp);
    fclose(nfp);
    return 0;






}
