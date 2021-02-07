/*************************************************************************
	> File Name: leecode665_非递减数列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  2/ 7 10:32:15 2021
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
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size() ; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
                //情况1：4，2，5 把大的改小
                if (i - 1 == 0)
                    nums[i-1] = nums[i];
                //情况2：1 4 2 5 把大改小
                else if (i - 1 > 0 && nums[i] >= nums[i - 2] )
                    nums[i - 1] = nums[i];
                //情况3：3 4 2 5 把小的改成大的
                else 
                    nums[i] = nums[i-1]; 
            }
           
        }
        return count <= 1;
    }
};
