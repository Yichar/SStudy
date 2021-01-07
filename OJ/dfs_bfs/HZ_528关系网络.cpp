/*************************************************************************
	> File Name: HZ_528关系网络.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  1/ 7 12:08:46 2021
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
int n, x, y, num[105][105], check[105];

struct node {
	int num;
	int step;
};

int main() {

	cin >> n >> x >> y;
	for (int i = 1; i < n + 1; i++) 
		for (int j = 1; j < n + 1; j++) 
			cin >> num[x][y];
		
		
	queue<node> Q;
	Q.push(node{x,0});
	while( !Q.empty()) {
		node temp = Q.front();
		Q.pop();
		for (int i = 1; i < n; i++) {
			if (check[temp.num] == 0 && num[temp.num][i] == 1) {
				if ( i == y) {
					cout << temp.step;
					return 0;
				}		
				check[temp.num] = 1;
				Q.push(node{i,temp.step + 1});
			}
		}
		

    }

	cout << 0;
	return 0;
}
