/*************************************************************************
	> File Name: HZ47_01背包问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  1/10 22:16:03 2021
 ************************************************************************/

#include <iostream>
using namespace std;



int v, w;
int dp[10005] = {0};// i 件物品， 当前j重量 的价值
int V,n; //最大重量，物品数量
int main () {
	cin >> V >> n;
	for (int i = 1; i <= n; i++){
			cin >> v >> w;
			for (int j = V; j >= v; j--)
				dp[j] = max(dp[j], dp[j - v] + w);
	
    }	
	
	cout << dp[V];
	return 0;
	
	

