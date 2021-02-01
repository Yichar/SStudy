/*************************************************************************
	> File Name: leecode778_水位上升的游泳池.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  1/30 11:56:46 2021
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
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    int bfs(vector<vector<int>>& mmap,int x,int y,vector<vector<int>>& check,int N, int k) {
        if (x == N - 1 && y == N - 1)
            return 1;
        for(int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0|| xx > N -1  || yy > N - 1|| check[xx][yy] == 1)
                continue;
            //必须小于等于K 才能走
            if(mmap[xx][yy] > k) {
                continue;
            }
            check[xx][yy] = 1;
            if(bfs(mmap,xx,yy,check,N,k) == 1)
                    return 1;
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int L = 0, R = 2500;
        while( L != R) {
            int mid = (L + R ) / 2;
            vector<vector<int>> check(55,vector<int>(55,0));
            check[0][0] = 1;
            int ans = bfs(grid,0,0,check,grid.size(),mid);
            if (ans == 1)
                R = mid;
            else
                L = mid + 1;
        }
        //结果不可能比出发点小
        if(L < grid[0][0])
            L = grid[0][0];
        return L;
    }
};
