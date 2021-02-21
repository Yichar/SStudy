/*************************************************************************
	> File Name: leecode1438_绝对差最长连续子数组.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  2/21 10:52:30 2021
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
    multiset<int,greater<int>> Hbig;
    multiset<int,less<int>> Hsmall;
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        if (nums.size() == 1) return 1;
        int Min = INT32_MIN, Max = INT32_MAX;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            Hbig.insert(nums[i]);
            Hsmall.insert(nums[i]);
            Min = *Hsmall.begin();
            Max = *Hbig.begin();
            if (Max - Min <= limit)
                ans = i - left + 1;
            else {
                Hsmall.erase(Hsmall.find(nums[left]));
                Hbig.erase(Hbig.find(nums[left]));
                left++;
            }
        }
        return ans;
    }
};

