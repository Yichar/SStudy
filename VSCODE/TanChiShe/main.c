#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <math.h>


#define WIDE 60 //宽度
#define HIGH 20 //高度


struct  BODY {
    int X, Y;
};

struct SNAKE {
    int  size; //长度
    struct BODY body[WIDE * HIGH];
};

struct FOOD {
    int X, Y;
};
struct SNAKE snake;
struct FOOD food;
int score = 0;




//初始化食物
void initFood(void) {

    food.X = rand() % WIDE; // 0 - 59
    food.Y = rand() % HIGH; // 0 - 19
    return;
}




void TestArray(int arr[]){
	printf("TestArray arr size:%d\n",sizeof(arr));
}
void test03(){
	int arr[] = { 10, 20, 30, 40, 50 };
	printf("array size: %d\n",sizeof(arr));

	//数组名在某些情况下等价于指针
	int* pArr = arr;
	printf("arr[2]:%d\n",pArr[2]);
	printf("array size: %d\n", sizeof(pArr));

	//数组做函数函数参数，将退化为指针,在函数内部不再返回数组大小
	TestArray(arr);
}

int main()
{
    srand(time(NULL));
   
   unsigned int a = 10;
   //printf("%u",a - 20);
   test03();
   
    return 0;
}
