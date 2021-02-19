/*************************************************************************
	> File Name: leecode877_鸡蛋掉落.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/18 13:08:50 2021
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
    
    int superEggDrop(int n, int m) {
        vector<vector<int>> dp(n + 1,vector<int>(m+1));

        for(int i = 1; i <= m; i++) dp[1][i] = i;
        
        for (int i = 2; i <= n; i++) {
            int k = 1; // k 是两条分支的拐点的下一个楼层。
            dp[i][1] = 1;
            for (int j = 2; j <= m; j++) {
                dp[i][j] = j;
                //前者递增 后者递减，找到两者最近的一个k
                while (k < j && dp[i-1][k-1] < dp[i][j-k]) ++k;
                dp[i][j] = max(dp[i-1][k-1],dp[i][j-k]) + 1;
            }
        }
        return dp[n][m];
     }
};
