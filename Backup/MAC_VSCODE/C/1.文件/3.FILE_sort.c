/*************************************************************************
	> File Name: 3.FILE_sort.c
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/14 17:24:01 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


FILE* Fopen(const char *path, const char *mode) {

    FILE *fp = fopen(path,mode);
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    return fp;
}
void bb_sort(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}
void write_read() {
    srand(time(NULL));
    FILE *fp = Fopen("text02.txt","w");
    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d\n",rand() % 100);
    }
    fclose(fp);

}
void read_rand() {
    FILE *fp = Fopen("text02.txt","r");
    int arr[10] ;
    int i = 0;
    while (1) {
        fscanf(fp, "%d\n",&arr[i]);
        i++;
        if (feof(fp)) break;
    }
    fclose(fp);

    bb_sort(arr,10);
    //清空文件
    fp = Fopen("text02.txt","w");
    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%d\n",arr[i]);
    }
    
    return;

}

int main() {

    write_read();
    read_rand();
    return 0;


}
