/*************************************************************************
	> File Name: leecode283_移动零.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  1/30 19:20:10 2021
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
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        int L = 0,R = 1;
        while ( R < nums.size()) {
            //慢指针若为0，必须找到一个值替换他，
            if(nums[L] == 0) {
                while(nums[R] == 0 && R < nums.size() - 1 ) R++;
                nums[L] = nums[R];
                nums[R] = 0; 
            }
            L++;
            R++;
        }
    }
};
