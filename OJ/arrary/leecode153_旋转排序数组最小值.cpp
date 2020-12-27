/*************************************************************************
	> File Name: leecode153_旋转排序数组最小值.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/27 18:04:37 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int find(vector<int> nums){
        int L = 0, R = nums.size() - 1;
        while( L != R){
            int mid = L + R >> 1;
            if(nums[mid] < nums[R]) // 如果mid 比右侧值小，显然旋转点在左侧
                R = mid;  //右侧边界缩小
            else
                L = mid + 1;
        }
        return L;
    }
    int findMin(vector<int>& nums) {
        return nums[find(nums)];

    }
};
