/*************************************************************************
	> File Name: leecode547_省份数量.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  1/ 7 13:23:43 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int ans = 0;
    queue<int> Q;
    int findCircleNum(vector<vector<int>>& isConnected) {
            for (int i = 0; i < isConnected.size(); i++) {
                for (int j = 0; j < isConnected[0].size(); j++) {
                    if(isConnected[i][j] == 1) { //从1开始搜
                        isConnected[i][j] = 0;  
                        isConnected[j][i] = 0;
                        Q.push(i);
                        while(!Q.empty()) {
                            int temp = Q.front();
                            Q.pop();
                            for (int k = 0; k < isConnected.size(); k++) {
                                if ( isConnected[temp][k] == 1 ) {
                                    isConnected[temp][k] = 0;
                                    isConnected[k][temp] = 0;
                                    Q.push(k);
                                }
                            }
                            }
                        ans++;
                    }
                }
            }
            return ans;
    }
};
