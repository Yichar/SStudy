/*************************************************************************
	> File Name: leecode189_旋转数组.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/ 8 09:52:17 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return; 
        k = k % nums.size();
        reverse(nums.begin(),nums.begin()+nums.size() - k);
        reverse(nums.begin()+nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
        return;

    }
};
