/*************************************************************************
	> File Name: 6.线程.c
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/ 5 10:50:34 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func1(void *data) {
    printf("hello geek\n");
    return NULL;
}

void *func2(void *data) {
    printf("hello world\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
