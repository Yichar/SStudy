/*************************************************************************
	> File Name: leecode1423_可获得的最大点数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/ 6 14:09:06 2021
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
    int maxScore(vector<int>& cardPoints, int k) {
            int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
            if (k >= cardPoints.size())
                    return sum;
            int left = 0;
            int temp = 0, ans = 0;
            //取k个得最大，看成是留下n-k个最小，且必定连续。
            for (int right = 0; right < cardPoints.size(); right++) {
                if (right < cardPoints.size() - k - 1) {
                    temp += cardPoints[right];
                } else {
                    temp += cardPoints[right];
                    ans = max(ans, sum - temp);
                    temp -= cardPoints[left++];

                }
            }
            return ans;
    }
};
