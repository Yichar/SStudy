#include <iostream>

using namespace std;




int n, m;
int dp[55] = {1, 2};

int main() {

	
	cin >> n >> m;
	// < m dp[i-1]*2
	// =m dp[i-1]*1 -2
	// >m dp[i-1] * 2- dp[i-1 - m]
	
	for (int i = 2; i < m; i++) {
		dp[i] = dp[i-1] * 2;
	}
	dp[m] = dp[m-1] * 2 - 1; 
	
	for (int i = m + 1; i <= n; i++) {
		dp[i] = dp[i-1] * 2 - dp[i - 1 - m];
	}
	
	cout << dp[n];
	return 0;


}
