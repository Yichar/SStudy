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

struct node {
    int now,val;
    bool operator <(const node &b) const {
        return this->val > b.val;
    }
};

edge edg[200005];
int n , m , s, ans[100005], head[100005],edg_cnt;

void add_edg(int s,int e,int v) {
    edg[edg_cnt].e = e;
    edg[edg_cnt].v = v;
    edg[edg_cnt].next = head[s];
    head[s] = edg_cnt++;
}
int main()
{
    memset(head, -1, sizeof(head));
    memset(ans, 0x3f, sizeof(head));
   cin >> n >> m >> s;
   for (int i = 1; i <= m; i++) {
       int a, b , c;
       cin >> a >> b >> c;
       add_edg(a,b,c);
       add_edg(b,a,c);
   }


   priority_queue<node> que;
   que.push((node){s,0});
   ans[s] = 0;
   while (!que.empty()) {
       node temp = que.top();
       que.pop();
       if (temp.val != ans[temp.now]) continue;
       for (int i = head[temp.now]; i != -1; i = edg[i].next) {
           int e = edg[i].e, v = edg[i].v;
           if (ans[e] > temp.val + v) {
               ans[e] = temp.val + v;
               que.push((node){e,ans[e]});
           }

       }
     
       
   }
   for (int i = 1; i <= n; i++) {
       if (ans[i] != 0x3f3f3f3f) 
            cout << ans[i] << endl; 
        else
            cout << -1 << endl;
   }
   return 0;
}
