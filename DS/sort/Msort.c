/*************************************************************************
	> File Name: Msort.c
	> Author: Yichar
	> Mail: 
	> Created Time: 五  1/15 14:29:56 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) {\
        a ^= b; b ^= a; a ^= b;\
    }

#define TEST(arr, n, func, args...) {\
                            int *num = (int *)malloc(sizeof(int) * n);\
                            memcpy(num, arr, sizeof(int) * n);\
                            output(num, n);\
                            printf("%s= ", #func);\
                            func(args);\
                            output(num, n);\
                            free(num);\
                        }
void select_sort(int *num, int n) {
    if (n <= 1) return;
    int i, j, indx;
    for (i = 0; i < n - 1; i++) {
        indx = i;
        for ( int j = i + 1; j < n; j++) {
            if (num[j] < num[indx])
                indx = j;
        }
        if (indx != i)
            swap(num[indx], num[i]);
    }
    return;

}

void quick_sort(int *num, int L, int R) {
    if (L >= R)
        return;
    int base = num[L], low = L, high = R;
    while (low < high) {
        while (low < high && num[high] >= base) high--;
        num[low] = num[high];
        while (low < high && num[low] <= base) low++; 
        num[high] = num[low];
    }
    quick_sort(num, L, low - 1);
    quick_sort(num, low + 1, R);
}

int quick_choose(int *num,int L,int R,int k){
    if(L >= R) {
        printf("the %d largeis %d\n", k, num[L]);
        return num[L];
    }
    int base = num[L], low = L, high = R;
    while(low < high){
        while (low < high && num[high] >= base ) high--;
        num[low] = num[high];
        while (low < high && num[low] <= base ) low++;
        num[high] = num[low];
    }
    if(high + 1 - L >= k){
        return quick_choose(num, L, high, k);
    }else{
        return quick_choose(num, high + 1, R, k - (high + 1 - L));
    }
       
}


//n^2  有序 + 无序 从有序区中找到合适位置
void insert_sort(int *num, int n) {
    if (n <= 1) return;
    int i,j,temp;
    for (i = 1; i < n; i++) {
        temp = num[i];
        for (j = i - 1; j >= 0 && num[j] > temp; j--) {
            num[j + 1] = num[j];
        }
        num[j + 1] = temp;
    }
    return;
}

void bubble_sort(int *num, int n) {
    if (n <= 1) return;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (num[j] > num[j + 1])
                swap(num[j],num[j + 1]);
        }
    }
    return;
}

void merge(int *num, int L, int mid, int R) {
    int *temp = (int *)malloc(sizeof(int) * (R - L + 1));
    int x = L, y = mid + 1, count = 0;
    while( x <= mid && y <= R) {
        temp[count++] = num[x] > num[y] ? num[y++] : num[x++];
    }
    while (x <= mid) temp[count++] = num[x++];
    for (int i = 0; i < count; i++) {
        num[L + i] = temp[i];
    }
    free(temp);
}

void merge_sort(int *num,int L, int R) {
    if (R == L) return;
    int mid = (L + R) >> 1;
    merge_sort(num, L, mid);
    merge_sort(num, mid + 1, R);
    merge(num, L, mid, R);
}


void randint(int *num, int n) {
        while (n--) num[n] = rand() % 100;
        return ;

}

void output(int *num, int n) {
        printf("[");
    for (int i = 0; i < n; i++) {
                printf("%d ", num[i]);

    }
        printf("]\n");
        return ;
}

int main() {
        srand(time(0));
        #define max_n 20
        #define test_n 4
        int arr[max_n];
        randint(arr, max_n);
        TEST(arr, max_n, insert_sort, num, max_n);
        TEST(arr, max_n, bubble_sort, num, max_n);
        TEST(arr, max_n, merge_sort, num, 0, max_n - 1);
        TEST(arr, max_n, select_sort, num, max_n);
        TEST(arr, max_n, quick_sort, num, 0, max_n - 1);
        TEST(arr, max_n, quick_choose, num, 0, max_n - 1, max_n - 2);
        #undef max_n
        return 0;

}
