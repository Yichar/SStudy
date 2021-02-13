/*************************************************************************
	> File Name: leecode448_找到所有消失的数字.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/13 10:30:41 2021
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums[i] - 1) % nums.size();
            nums[index] += nums.size();
        }
         for (int i = 0; i < nums.size(); i++) {
           if(nums[i] <= nums.size())
                res.push_back(i+1);
        }
        return res;
    }
};

//
