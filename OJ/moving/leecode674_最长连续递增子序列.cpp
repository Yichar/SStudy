/*************************************************************************
	> File Name: leecode674_最长连续递增子序列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  1/24 00:17:51 2021
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
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int temp = 1;
        if(nums.size() == 1) return 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1])
                temp = 0;
            temp++;
            ans = max(ans,temp);
        }
        return ans;
    }
};
