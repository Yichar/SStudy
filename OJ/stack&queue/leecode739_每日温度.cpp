/*************************************************************************
	> File Name: leecode739_每日温度.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  2/21 23:04:42 2021
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

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> S; // 递减栈，找顶最大，栈顶出栈时，必然遇到了保存i - S.top 即可
        vector<int> ans(T.size());
        if (T.size() == 1) return {0};
        S.push(0);
        int temp = 0;
        for (int i = 1; i < T.size(); i++) {
            while(!S.empty() && T[i] > T[S.top()]) {
                ans[S.top()] = i - S.top();
                S.pop();
            }
            S.push(i);
        }
        //末尾必然为0
        return ans;
    }
};
