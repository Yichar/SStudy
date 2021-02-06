/*************************************************************************
	> File Name: leecode1208_尽可能使字符串相等.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/ 5 11:24:51 2021
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
    int equalSubstring(string s, string t, int maxCost) {
            int slen = s.size();
            int tlen = t.size();
            int vlen = slen > tlen ? tlen : slen;
            vector<int> record(vlen + 1,0);
            record[0] = 0; //计算前缀和
            for (int i = 1; i <= vlen; i++) {
                record[i] = abs(s[i-1] - t[i-1]) + record[i-1];
            }
            int left = 0;
            int ans = 0;
            for (int i = 1; i <= vlen; i++) {
               if(record[i] - record[left] > maxCost) {
                   ans = max(ans,i-left-1);
                   left++;
               } 
               //单独判断最后一步
               if (i == vlen && record[i] - record[left] <= maxCost)
                    ans = max(ans,i-left);
            }
            return ans;
    }
};
