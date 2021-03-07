#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


struct edge {
    int e, v, next;
};

edge edg[100005];
int n, m, head[100005], ans[100005];
int in_degree[100005];
int main()
{
    memset(head, -1, sizeof(head));
    
    cin >> n >> m >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ans[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b ,c;
        cin >> a>> b >> c;
        edg[i].e = b;
        edg[i].v = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            que.push(i);
    }

    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            ans[e] = max (ans[e],ans[temp] + v);
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
   //system("pause");
   return 0;
}
