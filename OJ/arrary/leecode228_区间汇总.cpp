/*************************************************************************
	> File Name: leecode228_区间汇总.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  1/10 12:10:44 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        nums.push_back(-1); //末尾添加一位比较方便
        int start = nums[0];
  
         for (int i = 0; i < nums.size() - 1; i++) {
            if ( nums[i]   == nums[i+1] - 1 ) continue;
            else {
                //判断开始和结束区间
                if (nums[i] == start)
                    ans.push_back(to_string(start));
                else  {
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                //更新start
                if (i< nums.size()) start = nums[i+1];
                    else break;
            }  
         }
    return ans;
        }
    
};
