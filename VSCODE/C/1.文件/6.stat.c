/*************************************************************************
	> File Name: 6.stat.c
	> Author: Yichar
	> Mail: 
	> Created Time: 五  1/15 22:59:38 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {

    struct stat buf;
    int ret = stat("./File_100M",&buf);

    printf("文件大小为：%lld\n", buf.st_size);

    return 0;


}
