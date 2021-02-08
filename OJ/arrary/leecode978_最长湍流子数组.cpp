/*************************************************************************
	> File Name: leecode978_最长湍流子数组.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  2/ 8 11:14:38 2021
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

//思路：转换成 0 1 -1 数组，计算个数，
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        if (len == 1) return 1;
        int count_0 = 0;
        vector<int> record(len,0);
        for (int i = 0; i < len - 1; i++) {
            if ( arr[i] - arr[i+1] > 0)
                record[i] = 1;
            else if (arr[i] - arr[i+1] < 0)
                record[i] = -1;
            else {
                    record[i] = 0;
                    count_0++;
            }
        }
        int ans;
        if (count_0 == len -1)
            return 1;
        else
            ans = 2;
        //1 1 -1 1 -1 0 1 -1 
        for (int i = 0; i < len - 1; i++) {
          int temp = record[i];
          int j = i;
            while (temp * record[j + 1] < 0 && j < len - 2) {
                temp = record[j+1];
                ans = max(ans,j + 1 -i+2);
                j++;
                //直接跳过这个区间
                if (temp * record[j + 1] >= 0 )
                    i = j;
           }   
        }
        return ans ;
    }
};
