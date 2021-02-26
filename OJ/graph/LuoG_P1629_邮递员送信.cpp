/*************************************************************************
	> File Name: LuoG_P1629_邮递员送信.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/25 20:46:31 2021
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
    int e,v ,next;
};


int n, m, head1[1005],head2[1005];
int ans1[1005], ans2[1005];
int mark[1005];
int edg_cnt1, edg_cnt2;
//遍历2次

edge edg1[10005],edg2[10005];

int ansfin;

void func(edge *edg, int *head, int *ans) {
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = temp; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) {
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
        }
    }
}

void add_edg(edge *edg, int *head,int cnt, int s, int e, int v) {
    edg[cnt].e = e;
    edg[cnt].v = v;
    edg[cnt].next = head[s];
    head[s] = cnt;
}
int main() {
    cin >> n >> m;
    memset(ans1, 0x3f, sizeof(ans1));
    memset(ans2, 0x3f, sizeof(ans2));
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(edg1,head1,i,a,b,c);
        add_edg(edg2,head2,i,b,a,c);
    }
    ans1[1] = ans2[1] = 0;
    func(edg1,head1,ans1);
    func(edg2,head2,ans2);

    for (int i = 1; i <= n; i++){
        cout << ans1[i] << " ";
        ansfin += ans1[i] + ans2[i];
    }
    cout << ansfin << endl;
    return 0;
}

