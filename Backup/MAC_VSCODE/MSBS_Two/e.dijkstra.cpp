#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
using namespace std;

struct edge {
    int e, v, next;
};

struct node {
    int now,val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

edge edg[200005];
int head[100005];
int n, m, s, edg_cnt, ans[100005];

void add_edg(int t1,int t2,int t3) {
    edg[edg_cnt].e = t2;
    edg[edg_cnt].v = t3;
    edg[edg_cnt].next = head[t1];
    head[t1] = edg_cnt;
    edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(head));
    scanf("%d %d %d",&n, &m, &s);
    for (int i = 0; i < m; i++) {
        int t1,t2,t3;
        scanf("%d%d%d",&t1,&t2,&t3);
        add_edg(t1, t2, t3);
        add_edg(t2, t1, t3);
    }



    priority_queue<node> que;
    que.push((node){s,0});
    ans[s] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        // 如果这个状态 和 之前存的不一致，这个节点可以忽略
        // 进入循环的条件是 这个状态必须是最优状态
        if (temp.val != ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            int v = edg[i].v;
            //如果temp.val + v 更小 
            if (ans[e] > temp.val + v) {
                ans[e] = temp.val + v;
                que.push((node){e,ans[e]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] != 0x3f3f3f3f) {
            printf("%d\n",ans[i]);
        } else {
            printf("-1");
        }
    }

    return 0;
}