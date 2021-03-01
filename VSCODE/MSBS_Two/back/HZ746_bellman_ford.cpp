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
    int s,e,v;
};


int n,m,s,ans[100005];
edge edg[200005];
int edg_cnt;


void add_edg(int a,int b,int c) {
    edg[edg_cnt].s = a;
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg_cnt++;
}
int main()
{
   cin >> n >> m >> s;
   memset(ans, 0x3f,sizeof(ans));
   for (int i = 1; i <= m; i++) {
       int a, b, c;
       cin >> a >> b >> c;
       add_edg(a,b,c);
       add_edg(b,a,c);

   }
   ans[s] = 0;
   for (int i = 1; i <= n; i++) {
       for (int j = 0; j < edg_cnt; j++) {
           //第j条边的终点 是否可以被起点的路径值 和 权值更新
           ans[edg[j].e] = min(ans[edg[j].e], ans[edg[j].s] + edg[j].v);
       }
   }
// ans[s] = 0;
//   for (int i = 1;  i <= n; i++) {
//       int flag = 0;
//       for (int j = 0; j < edg_cnt; j++) {
//         //  优化前： ans[edg[j].e] = min (ans[edg[j].e], ans[edg[j].s] + edg[j].v);
//           if (ans[edg[j].e] > ans[edg[j].s] + edg[j].v)
//           ans[edg[j].e] = ans[edg[j].s] + edg[j].v; //提前结束
//           flag = 1;
//       }
//       if (flag == 0) break;
//   }
   for (int i = 1; i <= n; i++) {
       if (ans[i] != 0x3f3f3f3f)
            cout << ans[i] << endl;
        else
        {
            cout << -1 << endl;
        }
        
   }
   return 0;
}
