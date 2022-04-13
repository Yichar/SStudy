/*************************************************************************
	> File Name: HZ636.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  3/ 4 20:01:12 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct edge {
    int e, next;
};

int n, m, head[100005], in_degree[100005], ans[100005];
edge edg[200005];
int main() {
    memset(head, - 1, sizof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
    }

    return 0;
}

