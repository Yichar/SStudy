/*************************************************************************
	> File Name: leecode3_无重复最大子串.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/ 5 20:18:45 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    unordered_set<char> S;
    int left = 0;
    int ans = 1;
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        for (int i = 0; i < s.size(); i++) {
            while (S.find(s[i]) != S.end()) {  //重复了，就左移
                S.erase(s[left]);
                left++;
            }
            ans = max(ans, i - left + 1);// 计算当前长度
            S.insert(s[i]); //插入
        }
    
    return ans;
    }
};
