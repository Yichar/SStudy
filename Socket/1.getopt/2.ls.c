/*************************************************************************
	> File Name: test1.c
	> Author: 
	> Mail: 
	> Created Time: 五  1/ 1 10:07:34 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
//optarg 参数的字符串指针
//optind 下一个搜索的选项序号 
//optopt 保存错误选项
//opterr 为1 会输出错误
int optnum = 0;
int aflag = 0;
int lflag = 0;
char this_dir[100];
char up_dir[100];
char temp_dir[100];
//getcwd(this_dir); 
//printf("%s",this_dir);
int ls_dir(int aflag, int lflag,char* dir){
    struct dirent *direntp;
    struct stat sb;
    DIR *dirp;
    char filename[128];
    getcwd(this_dir,sizeof(this_dir));
    chdir(dir); 
    printf("we do %s\n",dir);
    if ((dirp = opendir(dir)) == NULL) {
        perror("opendir");
        return 1;
    }
    while ((direntp = readdir(dirp)) != NULL) {
        sprintf(filename, "%s",direntp->d_name);
        if (lstat(filename, &sb) == -1) {
            perror("lstat");
            return 2;
        }
        printf("%s\n",direntp->d_name);
    }
    closedir(dirp);

    chdir(this_dir);
    return 0;
}
int main(int argc, char **argv) {
    //初始化选项标记
    opterr = 0;
    int opt;
    while ( (opt = getopt(argc,argv, "alm:o::")) != -1)  {
        switch (opt) {
        case 'a':
            aflag = 1;
            break;
        case 'l':
            lflag = 1;
            break;
        default:
            fprintf(stderr,"Usage: %s -al \n",argv[0]);
             exit(1);
        }
    }
    //计算命令跟的参数
    if( optind == argc ) 
        optnum = 0;
    else
        optnum = argc - optind;
    //开始干活
    if(optnum == 0) {
        ls_dir(aflag,lflag,"./");

    } else {
        while(optnum) {
            ls_dir(aflag,lflag,argv[optind]);
            optind++;
            optnum--;
        }
    }

//    printf("optind = %d,argc=%d,optnum = %d",optind,argc,optnum);
    return 0;
}
