/*************************************************************************
	> File Name: leecode354_俄罗斯套娃信封.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  3/ 4 20:21:16 2021
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
        static bool cmp(vector <int> & a, vector <int> & b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        else
            return a[1] < b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //先按后面的值排序
        sort(envelopes.begin(), envelopes.end(), cmp);
        //排序完之后，按照贪心思想，得到的序列应该是在evelopes[i][1]相同情况下，按从小到大顺序排          // 序的数组
        int n = envelopes.size();
        //寻找最长的连续子数组
        vector <int> dp(n + 1, 1);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])    
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            int res = 0;
            for(int i = 0; i < dp.size(); ++i)
                res = max(res, dp[i]);
        return res;
    }
};

