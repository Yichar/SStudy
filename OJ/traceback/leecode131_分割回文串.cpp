/*************************************************************************
	> File Name: leecode131_分割回文串.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  2/ 9 13:35:38 2021
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
    bool isPaliandome(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }


    vector<vector<string>> ans;
    vector<string> path;




    void traceback(string &s, int start) {
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            //是回文串 才继续搜索
                if (isPaliandome(s,start,i)) 
                    path.push_back(s.substr(start,i-start+1));
                //如果不是回文就直接剪枝
                else
                    continue;
                traceback(s, i + 1);
                path.pop_back();
            }
    }
    
    vector<vector<string>> partition(string s) {
        
        traceback(s,0);
        return ans;


    }
};

