/*************************************************************************
	> File Name: leecode80_重复子串的位置.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/ 5 10:57:35 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size() ;
        int num = 1;
        for (int i = 0; i < n; i++) {
          if( i == n - 1 || s[i] != s[i + 1] ) { //如果是最后一个元素，直接判断num,否则判断是否相等
              if(num >=3)
                    ans.push_back({i-num + 1,i});
            num = 1;
          } else 
              num++;
          
        }
        return ans;
    }
};
