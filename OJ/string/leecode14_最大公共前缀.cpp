/*************************************************************************
	> File Name: leecode14_最大公共前缀.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  2/ 7 15:37:32 2021
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
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) {
            return "";
        }
        string ans = strs[0];
        for( int i = 1 ; i< strs.size() ; i++ ){  //取第二个字符串
            string t = ans;
            ans = "";
            for(int j = 0; j < strs[i].size() && j<t.size();j++){  //比对当前字符串 和t 是不是相同
                if(strs[i][j] == t[j]){
                    ans += t[j];
                } else {
                    break;
                }
            }
            if(ans == ""){
                break;
            }

        }
        return ans;
    }
};
