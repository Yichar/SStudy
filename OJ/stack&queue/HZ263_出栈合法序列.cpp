/*************************************************************************
	> File Name: HZ263_出栈合法序列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/19 21:32:06 2021
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



int a[30],s[30],top;
bool is_valid(int *a, int n) {
	int j = 0; //入栈最大值
	for (int i = 0; i < n; i++) {
		while(j < a[i]) {S.push(++j);} //把小于入栈元素的 值都入栈
		if(S.top() - a[i]) return false; //若栈顶不等于当前元素 则必然不合法
		S.pop();
	}
	return true;
}

bool is_valid(int *a, int n) {
    int j = 0; //入栈最大值,注意j只增不减
    top = -1; //栈顶指针
    for (int i = 0; i < n; i++) {
        //要入栈的值a[i] 大于当前入栈的最大值。 j一直增加到a[i]的值，并且把这些值都入栈
        while (j < a[i]) {s[++top] = (++j);}
        
        //如果j小于当前值，如果栈空 或者 栈顶值 和 当前值不一致则 必然不合法
        if (top == -1 || s[top] - a[i]) return false;
        --top; // 至此为止还是合法的，出栈
    }
    return true;
}
int main() {


    int ans = 20;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    do {
        //若不合法
        if (!is_valid(a,n)) continue;
        //打印合法
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
        ans--;
    }
    while (ans && next_permutation(a,a + n));
    return 0;
}

