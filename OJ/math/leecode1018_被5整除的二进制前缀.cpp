/*************************************************************************
	> File Name: leecode1018_被5整除的二进制前缀.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  1/14 13:48:25 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    vector<bool> ans;
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int temp = 0;
        for (int i = 0; i < A.size(); i++) {
            temp = temp << 1;
           // cout << temp;
            temp += A[i];
            if (temp % 5 == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
            temp = temp % 5; //关键步骤
        }
        return ans;
    }
};
