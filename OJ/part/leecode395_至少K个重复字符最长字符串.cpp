/*************************************************************************
	> File Name: leecode395_至少K个重复字符最长字符串.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/27 10:18:54 2021
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
    int longestSubstring(string s, int k) {
        // 如果出现k不满足1返回s的长度
        if (k <= 1) return s.size();
        // 如果s的长度不足k或者s为空返回0
        if(s.size() < k || s.empty()) return 0;

        // 定义存储字符ASCII的数组，统计各个字符的数量
        vector<int> hash(128, 0);
        for (char c : s) ++hash[c];
        
        // 切割字符串中字符都满足大于等于k条件的字符串
        int index = 0;
        while (index < s.size() && hash[s[index]] >= k) ++index;
        if (index == s.size()) return s.size();

        // 左边满足
        int l = longestSubstring(s.substr(0, index), k);
        while (index < s.size() && hash[s[index]] < k) ++index;
        // 右边满足
        int r = longestSubstring(s.substr(index), k);
        
        return max(l, r);
    }
};


