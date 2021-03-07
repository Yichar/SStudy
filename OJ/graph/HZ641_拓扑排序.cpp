/*************************************************************************
	> File Name: HZ641_拓扑排序.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  3/ 4 18:39:10 2021
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

//小顶对
priority_queue <int,vector<int>,greater<int> > que;
edge edg[400005];
int head[2005];
int n , m, in_degree[2005],ans[2005], cnt;
int main() {
    memset(head, - 1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].e = b;
        edg[i].next = head[a];
        in_degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int temp = que.top();
        que.pop();
        ans[cnt++] = temp;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            in_degree[edg[i].e]--;
            if (in_degree[edg[i].e] == 0)
                que.push(edg[i].e);
        }
    }
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            i && cout << " ";
            cout << ans[i];
        }
    }
    else {
            cout << "loop" << endl;
        }
    

    return 0;
}

