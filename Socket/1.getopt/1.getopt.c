/*************************************************************************
	> File Name: test1.c
	> Author: 
	> Mail: 
	> Created Time: 五  1/ 1 10:07:34 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//optarg 参数的字符串指针
//optind 下一个搜索的选项序号 
//optopt 保存错误选项
//opterr 为1 会输出错误
int main(int argc, char **argv) {
    int opt;
    while ( (opt = getopt(argc,argv, "alm:o::")) != -1)  {
        switch (opt) {
        case 'a':
            printf("found a\n");
            break;
        case 'l':
            printf("found l\n");
            break;
        case 'm':
            printf("%s",optarg);
            break;
        case 'o':
            printf("%s",optarg);
            break;
        default:
            fprintf(stderr,"Usage: %s -al \n",argv[0]);
//            exit(1);
        }
// printf("optind = %d, opterr = %d \n",optind,opterr);
        //
    }
    printf("optind = %d,argc=%d",optind,argc);
    while(optind++ < argc)  {
        printf("%s",argv[optind-1]);
    }
    return 0;
}
