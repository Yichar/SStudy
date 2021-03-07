/*************************************************************************
	> File Name: leecode54_螺旋矩阵.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  3/ 4 21:51:50 2021
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
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lx = 0, rx = matrix[0].size() - 1; //左右
        int uy = 0, dy = matrix.size() - 1;  //上下
        int num = (rx + 1) * (dy + 1);
        while (1) {
            for (int i = lx; i <= rx; i++) 
                ans.push_back(matrix[uy][i]);
            uy++;
             if (ans.size() == num) break;
            for (int i = uy; i <= dy; i++) 
                ans.push_back(matrix[i][rx]);
            rx--;
             if (ans.size() == num) break;
            for (int i = rx; i >= lx; i--)
                ans.push_back(matrix[dy][i]);
            dy--;
             if (ans.size() == num) break;
            for (int i = dy; i >= uy; i--)
                ans.push_back(matrix[i][lx]);
            lx++;
             if (ans.size() == num) break;
        }
        return ans;
    }
};
