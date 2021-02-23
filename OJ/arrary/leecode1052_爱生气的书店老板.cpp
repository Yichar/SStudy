/*************************************************************************
	> File Name: leecode1052_爱生气的书店老板.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  2/23 12:32:38 2021
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0; 
        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 0)
                sum += customers[i];
        }
        int left = 0;
        int ans = sum;
        int temp = sum;
        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 1) 
                    temp += customers[i];
            if ( i - left + 1 > X) {
                if (grumpy[left] == 1)
                    temp -= customers[left];
                left++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};

