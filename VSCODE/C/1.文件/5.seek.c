/*************************************************************************
	> File Name: 5.seek.c
	> Author: Yichar
	> Mail: 
	> Created Time: 五  1/15 21:51:42 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct student {
    int age;
    char name[10];
    int num;
} stu_t;

int main(void) {
    stu_t stu[4] = {
        18, "afei", 10,
        20, "andy", 20,
        30, "lily", 30,
        16, "james", 40
    };

    FILE *fp = fopen("test05.txt","w+");
    if (!fp) {
        perror("fopen");
        return -1;
    }


    stu_t s1;
    //写入数组
    fwrite(&stu[0], 1, sizeof(stu), fp);
    //偏移一个结构体
    fseek(fp, sizeof(stu_t), SEEK_SET);
    fread(&s1, 1, sizeof(stu_t) * 2, fp);
    printf("age = %d, name = %s, num = %d \n", s1.age, s1.name, s1.num);

    int len = ftell(fp); //当前偏移量
    printf("len = %d \n", len);


    rewind(fp); //回卷
    fread(&s1, 1, sizeof(stu_t), fp);
    printf("起始:age = %d, name = %s, num = %d \n", s1.age, s1.name, s1.num);
    
    //获取文件大小
    //
    //
    fseek(fp, 0, SEEK_END);
    len  = ftell(fp);
    printf("文件大小为：%d\n", len);
    



    fclose(fp);
    return 0;




}
