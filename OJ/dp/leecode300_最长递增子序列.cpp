/*************************************************************************
	> File Name: leecode300_最长递增子序列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  1/20 20:41:59 2021
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
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        vector<int> dp(nums.size() + 1,1);
        int mmax = INT32_MIN;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                //如果第i位的数大于第j位，则dp[i] 更新为dp[j] + 1
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
            mmax = max( mmax, dp[i]);
        }
        return mmax;
    }
};
