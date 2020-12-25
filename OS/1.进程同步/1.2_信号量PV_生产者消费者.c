/*************************************************************************
	> File Name: 1.2_信号量PV_生产者消费者.c
	> Author: 
	> Mail: 
	> Created Time: 五 12/25 17:52:55 2020
 ************************************************************************/

#include<stdio.h>
```jsx
struct semaphore{
	int value; //资源数
	PCB* queue; //等待的进程队列
}
//P(semaphore s); //消费资源
//V(semaphore s); //产生资源

P（semaphore s）{
	s.value--;
	if(s.value < 0)  //资源不够用了
		sleep(s.queue);
}
V（seamphore s）{
	s.value++;
	if(s.value <= 0)  //存在睡眠的进程
		wakeup(s.quque);
}

semaphore full = 0; // 缓冲区可用数
semaphore empty = BUFFER_SIZE; //缓冲区空闲数
semaphore mutex = 1; //读写互斥锁

void Producer(item){
	int item;
	while(ture){
		item = producer_item();
		P(empty); //空闲
		P(mutex);
		insert_item(item); //写入缓冲区
		V(mutex);
		V(full);
}

void consumer(void){
	int item;
	P(full);
	P(mutex);
	item = remove_item();
	V(mutex);
	V(empty);
	consumer_item(item);  // 打印数据
}

