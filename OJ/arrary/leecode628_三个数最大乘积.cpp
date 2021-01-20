/*************************************************************************
	> File Name: leecode628_三个数最大乘积.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  1/20 10:42:43 2021
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
    int T[3];
    int maximumProduct(vector<int>& nums) {
        int lens = nums.size();
        sort(nums.begin(),nums.end());
        int sum1 = nums[lens-1] * nums[lens-2] * nums[lens-3];
        int sum2 = nums[0] * nums[1] * nums[lens-1];
        
        return sum1 > sum2 ? sum1 : sum2;
    }
};
