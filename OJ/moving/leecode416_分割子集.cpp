/*************************************************************************
	> File Name: leecode416_分割子集.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/21 10:57:51 2021
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
    int sum = 0;
    bool canPartition(vector<int>& nums) {
        for (auto a:nums)
            sum += a;
        if (sum % 2 == 1) return false;
        sum = sum / 2;
        vector<int> dp(sum + 1,0);
        //背包的体积为sum / 2
        //背包要放入的商品（集合里的元素）重量为 元素的数值，价值也为元素的数值
        //背包如果正好装满，说明找到了总和为 sum / 2 的子集。（不可能超过sum/2 价值和重量相等）
        //背包中每一个元素是不可重复放入。    
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
            }
        }
        for (int i = 0; i <= sum; i++)
             cout << dp[i] << " ";
        return dp[sum] == sum;

    }
};
