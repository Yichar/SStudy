/*************************************************************************
	> File Name: offer45_数组排成最小的数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  3/ 5 18:54:33 2021
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
    string ans;
 
    string minNumber(vector<int>& nums) {
        vector<string> Sn;
        for (int i:nums) Sn.push_back(to_string(i));
        sort(Sn.begin(),Sn.end(),[](string a, string b){
            return a + b < b + a;
        });
        for (auto i:Sn) {
            ans += i;
        }
        return ans;
    }
};

