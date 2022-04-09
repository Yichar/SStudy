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
    int e,v,next;
};

int n, m, s, head[10005],ans[100005];
int edg_cnt;

edge edg[200005];

int mark[100005];

void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
    }
int main()
{
    memset(ans, 0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));

    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a,b,c);
        add_edg(b,a,c);
    }
    
    ans[s] = 0;
    queue<int> que;
    que.push(s);
    mark[s] = 1;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e]  > ans[temp] + v) {
                ans[e] = ans[temp] + v;
                mark[e] = 1;
                que.push(e);
            }
                
        }

    }
       for (int i = 1; i <= n; i++) {
        if (ans[i] != 0x3f3f3f3f) {
            printf("%d\n",ans[i]);
        } else {
            printf("-1\n");
        }
    }
   
   return 0;
}
