/*************************************************************************
	> File Name: leecode1128_等价整数对.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  1/26 11:31:16 2021
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
    map <pair<int ,int>,int> MM;
    int ans = 0;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0; i < dominoes.size(); i++) {
            int tempx = dominoes[i][0];
            int tempy = dominoes[i][1];
            if( MM.find((pair<int,int>){tempx,tempy}) != MM.end() || MM.find((pair<int,int>){tempy,tempx}) != MM.end()  ) {
                if (tempx != tempy) //如果2个值不同，需要加2个地方
                     ans +=   MM[pair<int,int>{tempx,tempy}] +  MM[pair<int,int>{tempy,tempx}];
                 else
                    ans += MM[pair<int,int>{tempx,tempy}];
            }
           MM[pair<int,int>{tempx,tempy}]++;
            
        }
        return ans;
    }
    
};
