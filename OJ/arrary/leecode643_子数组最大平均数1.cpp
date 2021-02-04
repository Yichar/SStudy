/*************************************************************************
	> File Name: leecode643_子数组最大平均数1.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/ 4 09:51:59 2021
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
    int ans =INT32_MIN;
    double findMaxAverage(vector<int>& nums, int k) {
        int temp = 0;
        if (nums.size() == 1) return nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                temp += nums[i];
                if (k > nums.size()) 
                    return (temp * 1.0) / k;
            }
            else {
                temp += nums[i];
                ans = max(temp,ans);
                temp -= nums[i-k+1];
            }
        }
            return (ans * 1.0) / k;
        }
    
};
