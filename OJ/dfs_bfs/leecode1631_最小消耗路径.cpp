/*************************************************************************
	> File Name: leecode1631_最小消耗路径.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  1/29 11:49:03 2021
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
    int dir[4][2] = {0,1,1,0,0,-1,-1,0};
    int bfs(vector<vector<int>>& mmap,  vector<vector<int>>& check, int x,int y,int k,int lenx,int leny) {
        if ( x == lenx && y == leny)
            return 1;
        for(int i =0; i <4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx > lenx || yy > leny || check[xx][yy] == 1)
                continue;
            else if (abs(mmap[xx][yy] - mmap[x][y]) > k )
                continue;
            else {
                    check[xx][yy] = 1;
                    if (bfs(mmap,check,xx,yy,k,lenx,leny) == 1)
                        return 1;
            }
        }
        return 0;
    } 
    int minimumEffortPath(vector<vector<int>>& heights) {
        
            int L = 0, R = 1000000;
            while( L != R) {
                int mid = (L + R) / 2;
                vector<vector<int>> check(105,vector<int>(105,0));
                check[0][0] = 1;
                int ans = bfs(heights,check, 0, 0, mid, heights.size()-1, heights[0].size()-1);
                if(ans == 1)
                    R = mid;
                else 
                    L =  mid + 1;
            }
            return L;   
    }
};
