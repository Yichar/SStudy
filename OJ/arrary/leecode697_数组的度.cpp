/*************************************************************************
	> File Name: leecode697_数组的度.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/20 18:33:49 2021
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
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int count[50000][3] ; //记录次数，第一次出现，最后一次出现
        int maxcount = 1; //初始化为1
        int maxlong = nums.size();
        memset(count,-1,sizeof(count));
        for (int i = 0 ; i < nums.size(); i++) {
            int val = nums[i];
            //第一次出现，初始化
            if (count[val][0] == -1) {
                count[val][0] = 1;
                count[val][1] = i;
                count[val][2] = i;
            } else {
                count[val][0]++;
                count[val][2] = i;
                maxcount = max (maxcount, count[val][0]);
            }
        }
            for (int i = 0; i < 50000; i++) {
                if (count[i][0] > 0) {
                    if(count[i][0] == maxcount)
                        maxlong = min(maxlong,count[i][2] - count[i][1] + 1);
                }
            }
    
    return maxlong;
    }
};
