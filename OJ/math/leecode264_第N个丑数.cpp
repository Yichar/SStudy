/*************************************************************************
	> File Name: leecode264_第N个丑数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/20 18:59:55 2021
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
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
       set<long long,less<long long>> Hm; //最小堆
       Hm.insert(1);
       while(n > 1) {
           long long temp = *(Hm.begin());
           Hm.insert(2 * temp);
           Hm.insert(3 * temp);
           Hm.insert(5 * temp);
           Hm.erase(Hm.begin());
           n--;
       }
       return *(Hm.begin());
    }
};
