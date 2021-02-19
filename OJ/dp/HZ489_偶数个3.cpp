#include <iostream>


using namespace std;



long long dp[2][1000] = {{0,8},{0,1}};
int n;



int main() {

	cin >> n;
	for (int i = 2; i <= n; i++) {
		
	
		dp[0][i] = 9 * dp[0][i-1] + dp[1][i-1]; //i位数 偶数个3 = 末尾非3 + 末尾3
		dp[1][i] = dp[0][i-1] + 9 * dp[1][i-1];  //奇数个3 = 末尾3 + 末尾非3
		dp[0][i] %= 12345;
		dp[1][i] %= 12345;
	
	}
	
	
	cout << dp[0][n];


	return 0;

}
