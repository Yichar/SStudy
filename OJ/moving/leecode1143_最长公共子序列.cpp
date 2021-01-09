/*************************************************************************
	> File Name: leecode1143_最长公共子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  1/ 9 22:17:30 2021
 ************************************************************************/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1005][1005] = {0};
        // dp[i][j] s1取i位 s2取j位 的最长串
	    for (int i = 1; i <= text1.size(); i++) {
		    for (int j = 1; j <= text2.size(); j++) {
			//前一种情况取大的
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if (text1[i - 1] == text2[j - 1])
				dp[i][j] = max(dp[i-1][j-1]+ 1,dp[i][j]);
		}
	}
	return dp[text1.size()][text2.size()] ;

    }
};
