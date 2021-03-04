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
    int s, e, v;
    bool operator < (const edge &b) const {
        return this->v < b.v;
    }
};

edge edg[400005];
int n, m, ans, my_union[5005];
int edg_cnt;
int cnt = 1; // 已经找到的点数量
void add_edg(int a, int b , int c) {
    edg[edg_cnt].s = a;
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg_cnt++;
}

int find_fa(int x) {
    if (my_union[x] == x)
        return x;
    return my_union[x] = find_fa(my_union[x]);
}
int main()
{
   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
       my_union[i] = i;
   }

   for (int i = 1; i <= m; i++) {
       int a, b, c;
       cin >> a >> b >> c;
       add_edg(a, b, c);
       add_edg(b, a, c);
   }

   sort(edg, edg + edg_cnt);

   for (int i = 0; i < edg_cnt; i++) {
       int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
       if (fa != fb) {
           ans += edg[i].v;
           my_union[fa] = fb;
           cnt++;
           if (cnt == n)
            break;
       }
   }
   if (cnt == n)
        cout << ans << endl;
    else
        cout << -1 << endl;

   return 0;
}
