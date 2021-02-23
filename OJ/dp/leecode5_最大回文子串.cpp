/*************************************************************************
	> File Name: leecode5_最大回文子串.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  2/23 16:14:44 2021
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
    int dp[1005][1005] = {1};
    string longestPalindrome(string s) {
      
        dp[0][0] = 1;
        int maxlen = 0;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size() ;j++) {
                if ( j == i)
                    dp[i][j] = 1; //单个字符
                else if ( j - i == 1)
                    dp[i][j] = s[i] == s[j] ? 1 : 0; // 2个字符
                else { //多个字符
                    if (s[i] == s[j]) 
                        dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = 0;
                }
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    ans = s.substr(i,maxlen); 
                }
            }
        }
            
        return ans;
    }
};
