/*************************************************************************
	> File Name: leecode338_比特位计数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  3/ 3 10:21:54 2021
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
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0)
                dp[i] = dp[i/2];
            else
                dp[i] = dp[i/2] + 1;
        }
        return dp;
    }
};

