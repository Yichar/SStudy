/*************************************************************************
	> File Name: leecode724_数组中心索引.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/28 09:09:33 2021
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
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int lens = nums.size();
        vector<int> N(lens + 1);
        N[0] = 0;
        //计算1~lens前缀和
        for (int i = 1; i < lens + 1; i++) {
            N[i] = N[i - 1] + nums[i-1];
        }
        for (int i = 1; i < lens + 1; i++) {
            if (N[i-1] == N[lens] - N[i])
                return i-1;
        }
        return -1;

    }
};
