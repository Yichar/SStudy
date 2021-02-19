/*************************************************************************
	> File Name: leecode1004_最大连续1的个数III.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/19 10:17:30 2021
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
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        int left = 0;
        int w_0 = 0;
        int ans = 0;
        for (int right = 0; right < len; right++) {
            if (A[right] == 0) w_0++;
            //如果0超过K，就必须处理掉一个0
            if (w_0 > K ) {
                while(A[left] == 1) left++;
                left++;
                w_0--;
            }
            ans = max(ans,right - left+1);

        }
        return ans;
    }
};
