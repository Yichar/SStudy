/*************************************************************************
	> File Name: HZ50_扔鸡蛋版本1.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/18 09:17:11 2021
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


#include<iostream>

using namespace std;




int n,m;
int dp[32][1000000];
int main() {
	cin >> n >> m;
	//一个鸡蛋 测试必然为m次
	for (int i = 0; i <= m; i++) dp[1][i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <=m; j++) {
			dp[i][j] = j;
			for (int k = 1; k <= j; k++) {
				dp[i][j] = min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k]) + 1);
			}
		}
	}
	cout << dp[n][m];

}
