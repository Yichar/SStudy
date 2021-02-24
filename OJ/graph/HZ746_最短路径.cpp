/*************************************************************************
	> File Name: HZ746_最短路径.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  2/23 18:47:14 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;



struct node {
    int now,val;
    bool operator< (const node &p) const {
        return this->val > p.val;
    }
};

struct edge {
    int e,v,next;
};




int n, m, s;
edge edg[200005];
int head[100005];
int ans[100005];
int edge_cnt;

//起点 终点 权值
void add_edge(int s,int e,int v) {
    edg[edge_cnt].e = e;
    edg[edge_cnt].v = v;
    edg[edge_cnt].next = head[s];
    head[s] = edge_cnt;
    edge_cnt++;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(head));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        add_edge(t1, t2, t3);
        add_edge(t2, t1, t3);
    }
    
    priority_queue<node> que;
    que.push((node){s,0}); // 起点
    ans[s] = 0; 
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.val != ans[temp.now]) continue;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            int v = edg[i].v;
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

