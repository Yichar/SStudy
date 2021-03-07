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
    int e, next;

};


int n, m, in_degree[105];
int ans[105], cnt; // 求了多少个点
edge edg[1005];
int head[105];

int main()
{
   memset(head, -1, sizeof(head));
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
       int a, b;
       cin >> a >> b;
       edg[i].e = b;
       edg[i].next = head[a];
       head[a] = i;
       in_degree[b]++;
   }
   stack<int> sta;
   for (int i = 1; i <= n; i++) {
       if (in_degree[i] == 0)
        sta.push(i);
   }
   while (!sta.empty()) {
       int t = sta.top();
       sta.pop();
       ans[cnt++] = t; //存一下
       for (int i = head[t]; i != -1; i = edg[i].next) {
           in_degree[edg[i].e]--;
           if (in_degree[edg[i].e] == 0)
                sta.push(edg[i].e);
       }
   }
   if(cnt == n) {
       for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
       }
   } else {
       cout << "loop" << endl;
   }
   cout << endl;
   return 0;
}
