/*************************************************************************
	> File Name: leecode_不同的二叉搜索树.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/14 14:07:02 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
//dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]


    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
