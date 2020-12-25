/*************************************************************************
	> File Name: 1.生产者消费者.c
	> Author: 
	> Mail: 
	> Created Time: 五 12/25 10:34:12 2020
 ************************************************************************/

#include<stdio.h>

#define N 10
int count = 0;

//生产者

void producer(void){
    int item;
    while(true){
        iterm = produce_item();
        if(count == N)
            sleep();
        inserrt_item(item);
        count++;
        if(count == 1)  //可以唤醒消费者了
            wakeup(consumer);
    }

}

//消费者
void consumer(void){
    int item;
    while(true){
        if(count == 0)
            sleep();
        item = remove_item();
        count--;
        if(count == N - 1)  //如果缓冲区有位置
            wakeup(producer);
        consumer_item(item);  // 打印数据
    }


}
