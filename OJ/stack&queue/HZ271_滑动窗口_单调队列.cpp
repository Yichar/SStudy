/*************************************************************************
	> File Name: HZ271_滑动窗口_单调队列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/20 11:25:34 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 300000
int q[MAX_N + 5], head = 0, tail = 0; //存数据流的下标
int val[MAX_N + 5];

int main() {
    int n, k ;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i <= n; i++) {
        // 移除大于当前值的元素
        while (tail - head && val[q[tail - 1]] > val[i]) --tail;
        q[tail++] = i; // 存入合法下标
        //队首出窗
        if (q[head] <= i - k) head++;
        if ( i >= k  ) { //窗满了 可以输出了
            i > k && cout << " ";
            cout << val[q[head]]; 
        }
    }
    head = tail = 0;
    cout << endl;    
    for (int i = 1; i <= n; i++) {
        // 移除小于当前值的元素
        while (tail - head && val[q[tail - 1]] < val[i]) --tail;
        q[tail++] = i; // 存入合法下标
        //队首出窗
        if (q[head] <= i - k) head++;
        if ( i >= k  ) {
            i > k && cout << " ";
            cout << val[q[head]]; 
        }
    }

    return 0;
}
