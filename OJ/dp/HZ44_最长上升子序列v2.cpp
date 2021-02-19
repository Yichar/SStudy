/*************************************************************************
	> File Name: HZ44_最长上升子序列.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/19 13:28:11 2021
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
//len数组表示长度为i的子序列的末尾值
int num[MAX_N + 5];
int dp; 
int len[MAX_N+5] = {0x3f}; //初始化为无穷大
//len单调，找第一个大于res的值,000111问题
int binary_search(int arr[],int lens,int res) {
	int L = 0;
	int R = lens;
	while(L != R) {
		int mid = (L + R) >> 1;
		if (arr[mid] < res)
			L = mid + 1;
		else
			R = mid;	   
	}
	return L;
}
int main() {
	int n;
	cin >> n;
	int ans = 0;
	dp = 0; // 每次只使用dp[i]
	len[0] = 0; 
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		//dp为找到的len中第一个大于num[i]的元素，实际上num[i] 会接到dp-1 的位置，然后替代dp的值。
		dp = binary_search(len,ans + 1,num[i]); //ans为最大长度，此处为有效查找范围
		len[dp] = num[i]; //把
		ans = max(dp,ans);
	}
	cout << ans;
}
