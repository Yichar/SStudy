/*************************************************************************
	> File Name: leecode494_目标和.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  1/25 11:09:37 2021
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
    //子集A +  子集B -  =>  sumA - sumB = S
    // 2sumA = S + sumA + sumB = S + sum
    int sum = 0;
    int result = 0;

    void traceback(vector<int>& nums, int start, int sum, int target) {
        if (start == nums.size()) { 
            if (sum == target)
                result++;
            return;
        }
        //先加 搜索 撤销
        sum += nums[start];
        traceback(nums, start + 1, sum, target);
        sum -= nums[start];
        //再减 搜索 撤销
        sum -= nums[start];
        traceback(nums, start + 1, sum, target);
        sum += nums[start];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        for(auto i:nums) sum += i;
        if (sum < S) return 0;
        if ((S + sum)%2 == 1) return 0;
    
        traceback(nums,0,0,S);
        return result;
    }
};
