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
    bool operator< (const edge &b) const {
        return this->v < b.v;
    }
};

edge edg[400005];
int n, m , ans, my_union[5005];

int edg_cnt , cnt = 1;
//cnt 生成树中点的数量


void add_edg(int s, int e, int v) {
    edg[edg_cnt].s = s;
    edg[edg_cnt].e = e;
    edg[edg_cnt].v = v;
    edg_cnt++;
}
// 并查集找爸爸
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
  for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      add_edg(a, b, c);
    //  add_edg(b, a, c); 并查集搜索时会搜两端

  }
  sort(edg, edg + edg_cnt);

  for (int i = 0; i < edg_cnt; i++) {
      int fa = find_fa(edg[i].s);
      int fb = find_fa(edg[i].e);
      if (fa != fb) {
          ans += edg[i].v;
          my_union[fa] = fb;
          cnt++;
          if (cnt == n)
            break;
      }
  }
  if (cnt == n) {
      cout << ans << endl;
  } else {
      cout << "orz" << endl;
  }
   return 0;
}
