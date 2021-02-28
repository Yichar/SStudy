/*************************************************************************
	> File Name: LuoG_P2865_严格次短路.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 六  2/27 20:25:33 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct edge {
    int e, v, next;
};

edge edg[200005];
int n, m, edg_cnt, ans[100005], ans2[100005], head[100005],mark[10005];


void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}
int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(ans,0x3f,sizeof(ans2));
    memset(head,-1,sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1 || b == 1) {
            //起点次短路，最短边的2倍
            ans2[1] = min(ans2[1],2 * c);
        }
        add_edg(a, b , c);
        add_edg(b, a, c);
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        //根据最短路，更新最短路
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) {
                ans2[e] = ans[e];
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
            //根据最短，更新次短
            if (ans2[e] > ans[temp] + v && ans[temp] + v != ans[e]) {
                    ans2[e] = ans[temp] + v;
                    if (mark[e] == 0) {
                        mark[e] = 1;
                        que.push(e);
                    }
            }
            //根据次短，更新次短
            if (ans2[e] > ans2[temp] + v )  {
                    ans2[e] = ans2[temp] + v;
                    if (mark[e] == 0) {
                        mark[e] = 1;
                        que.push(e);
                    }
                }
            }
        }
    }
    return 0;
}

