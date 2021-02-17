/*************************************************************************
	> File Name: leecode566_reshape矩阵.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  2/17 23:32:09 2021
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
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int Line = nums.size();
        int Row = nums[0].size();
        if ((r * c) != (Line * Row)) return nums;
        vector<vector<int>> ans(r,vector<int>(c));
        for (int i = 0; i < Line; i++) {
            for (int j = 0; j < Row; j++) {
                int temp = i * Row + j;
                ans[temp/c][(temp % c)] = nums[i][j];
            }
        }
        return ans;
    }
};
