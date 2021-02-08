/*************************************************************************
	> File Name: leecode括号生成.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  2/ 8 12:34:15 2021
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

    vector<string> ans;
    string path;
    void dfs(int left,int right,int num) {
        if(path.size() == 2*num )
             ans.push_back(path);
            if (left < num ) {
                path.push_back('(');
                dfs(left+1,right,num);
                path.pop_back();
            } 
            if (right < num && left > right) {
                path.push_back(')');
                dfs(left,right+1,num);
                path.pop_back();
            }
        }

    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return ans;
    }
};
