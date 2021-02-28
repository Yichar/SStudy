/*************************************************************************
	> File Name: HZ565_位的交换.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/27 11:33:30 2021
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;


int n;
int main() {
	cin >> n;
    printf("%04x\n",n);
	int high = n & 0xff00;
	int low = n & 0x00ff;
    printf("%02x %02x\n",high,low);
	high = high >> 16;
	low = low << 16;
    printf("%02x %02x\n",high,low);
	n =  high | low;
    printf("%04x\n",n);
	cout << n;
	return 0;
}
