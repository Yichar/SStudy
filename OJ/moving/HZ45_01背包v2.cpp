/*************************************************************************
	> File Name: HZ45_01背包v2.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/18 20:09:23 2021
 ************************************************************************/

#include <iostream>


using namespace std;



int v,w;
int dp[10005] = {0};// 容量为j
int V,n; //最大重量，物品数量

int main() {

	cin >> V >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v >> w;
		for (int j = V; j >= v; j--) {
			dp[j] = max(dp[j],dp[j-v] + w);
		
		}
	
	
	}

	cout << dp[V] << endl;

}
