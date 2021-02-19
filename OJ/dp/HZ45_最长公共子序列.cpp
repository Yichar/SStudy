/*************************************************************************
	> File Name: HZ45_最长公共子序列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  2/ 8 23:48:24 2021
 ************************************************************************/

#include <iostream>
#include <string>


using namespace std;
#define MAX_N 1000
string s1,s2;

int dp[MAX_N + 5][MAX_N + 5] = {0};

// dp[i][j] s1取i位 s2取j位 的最长串

int main() {

	cin >> s1 >> s2;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
            //状态转移方程
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            //如果此时两个字符相等，有可能是从i-1 j - 1 变化过来的。
			if(s1[i-1] == s2[j-1]) 
				dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
			
		}
	}
	cout << dp[s1.size()][s2.size()] ;
	return 0;
}
