/*************************************************************************
	> File Name: leecode485_连续1个数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  2/15 09:49:21 2021
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            while(i < nums.size() && nums[i] == 1) {temp++; i++;}
            ans = max(ans,temp);
            temp = 0;

        }
        return ans;
    }
};
