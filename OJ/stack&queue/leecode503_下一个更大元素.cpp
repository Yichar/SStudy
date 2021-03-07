/*************************************************************************
	> File Name: leecode503_下一个更大元素.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  3/ 6 10:24:09 2021
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
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> S;
        vector<int> ans(nums.size(),-1);
        int flag = 1;
        int last = -1;
        int len = nums.size();
        //滚动数组
        for (int i = 0; i < nums.size() * 2; i++) {
            if (S.empty() || nums[S.top()] >= nums[i % len]) {
                S.push(i % len );
            } else {
                while(!S.empty() && nums[S.top()] < nums[i % len]) {
                    ans[S.top()] = nums[i % len];
                    S.pop();
                }
                S.push(i % len);
            }
           
        }
        return ans;
    }
};

