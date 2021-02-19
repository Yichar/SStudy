/*************************************************************************
	> File Name: HZ45_01背包_版本1.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/18 18:34:57 2021
 ************************************************************************/

#include <iostream>


using namespace std;



int v[10005], w[10005];
int dp[100][10005] = {0};// 容量为j
int V,n; //最大重量，物品数量

int main() {

	cin >> V >> n;
	
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= V; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= v[i])
				dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]] + w[i]);
		
		}
	
	}


	cout << dp[n][V];


}
