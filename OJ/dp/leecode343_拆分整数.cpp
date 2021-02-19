/*************************************************************************
	> File Name: leecode343_拆分整数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  1/13 10:56:57 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int dp[100] = {0};
    int integerBreak(int n) {
        dp[2] = 1; //初始化
        for (int i = 3; i <=n; i++) {
            for (int j = 1; j < i; j++) {
                //转移函数= 自身，不拆分i-j，拆分i-j
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            
            }
        }
        return dp[n];
    }
};
