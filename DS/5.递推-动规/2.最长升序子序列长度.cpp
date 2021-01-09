/*************************************************************************
	> File Name: 2.最长升序子序列长度.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  1/ 9 20:38:42 2021
 ************************************************************************/

#include <iostream>
#include <algorithm>


using namespace std;
#define MAX_N 1000000




//f(i) = maxf(j) + 1 | num[j] < num[i];
int num[MAX_N + 5];
int dp[MAX_N + 5];
int main() {
	//dp[1] = 1;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&num[i]);
	}

	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (num[i] > num[j])
				dp[i] = max(dp[i],dp[j] + 1);
			ans = max(ans, dp[i]);
		
		}
	}

 	cout << ans;
	
	return 0;




}
