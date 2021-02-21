/*************************************************************************
	> File Name: leecode268_丢失的数字.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/20 20:08:17 2021
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
    int missingNumber(vector<int>& nums) {
       int ans = 0 ^ nums[0]; //0 ~ n 异或 nums[0] ~ nums[size-1]
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
            ans ^= i; 
        }
        ans ^= nums.size();
     return ans;
    }
};
