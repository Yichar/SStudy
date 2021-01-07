/*************************************************************************
	> File Name: leecode746_爬楼梯.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  1/ 7 11:39:15 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int dp[1005] = {0};
    int minCostClimbingStairs(vector<int>& cost) {
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[cost.size()];
    }
};
