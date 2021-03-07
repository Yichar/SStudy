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
    int e, v, next;
};

int n, m, head1[1005], head2[1005];
int edg_cnt;
edge edg1[2005], edg2[2005];
int ans1[1005], ans2[1005];
int main()
{
   cin >> n >> m;
   memset(ans1,0x3f,sizeof(ans1));
   memset(ans2,0x3f,sizeof(ans2));
   memset(head1,-1,sizeof(head1));
   memset(head2,-1,sizeof(head2));
   for (int i = 1; i <= m; i++) {
       int a, b, c;
       cin >> a >> b >> c;
       5t
   }
   return 0;
}
