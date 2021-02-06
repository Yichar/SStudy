/*************************************************************************
	> File Name: leecode172_阶乘后的0.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/ 5 13:44:42 2021
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
    int trailingZeroes(int n) {
        //考虑能得到多少个5
        int ans = 0;
       while(n) {
           ans += n / 5;
           n = n /  5;
       }
       return ans;
         
    }
};
