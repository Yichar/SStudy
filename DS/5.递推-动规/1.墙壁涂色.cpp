/*************************************************************************
	> File Name: 1.墙壁涂色.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  1/ 9 13:11:29 2021
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//f(n)= （k-2）f(n-2) + (k-1)k(n-1);

int main() {
	int f[3];
	int n,k;
	cin >> n >> k;
	f[1] = k;
	f[2] = k * (k - 1);
	f[0] = k * (k - 1) * (k - 2);
	for (int i = 4; i <= n; i++) {
		f[i % 3] = f[(i - 1)% 3] * (k - 2) + f[(i-2) % 2] * (k - 1);
	}
	cout << f[n%3] << endl;
	return 0;
}
