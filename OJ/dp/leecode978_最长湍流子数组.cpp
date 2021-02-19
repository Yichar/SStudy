/*************************************************************************
	> File Name: leecode978_最长湍流子数组.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  2/ 8 11:32:52 2021
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
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        if (len == 1) return 1;
        vector<int> up(len,1);
        vector<int> down(len,1);
        int ans = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1])
                down[i] = up[i-1] + 1;
            else if (arr[i] < arr[i-1])
                up[i] = down[i-1] + 1;
            else
                up[i] = down[i] = 1;
            ans = max(down[i] > up[i] ? down[i] : up[i],ans);
        }
        return ans;

    }
};

