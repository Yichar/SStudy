/*************************************************************************
	> File Name: leecode424_替换后最大重复子串.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  2/ 2 10:11:11 2021
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
    //统计窗口内 各个字母出现的个数，出现最多的就是候选字符串
    int characterReplacement(string s, int k) {
        if (s.size() <= 1)
            return s.size();
        int count[26] = {0};
        int left = 0;
        int maxchar = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            //更新窗口出现的最多的字母数量
            maxchar = max(maxchar,count[s[right] - 'A']);
            //k 不够
            if (right - left + 1 - maxchar > k) {
                //注意顺序不能反
                count[s[left]-'A']--;
                left++;
              
            }
        }
        return s.size() - left;

    }
};

