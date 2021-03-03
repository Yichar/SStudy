/*************************************************************************
	> File Name: LuoG_P1991.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  3/ 2 20:38:17 2021
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
#include <cmath>
using namespace std;


struct edge {
    int s, e, v;
    bool operator< (const edge &b) const {
        return this->v > b.v;
    }
};

int p,n, xy[505][2], my_union[505];
edge edg[250005];
int edg_cnt;
double ans;
int cnt;

int find_fa(int a) {
    if (a == my_union[a])
        return a;
    return my_union[a] = find_fa(my_union[a]);
}
int main() {
    cin >> p >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t1 = xy[i][0] - xy[j][0], t2 = xy[i][1] - xy[j][1];
            double t = sqrt(t1 * t1 + t2 * t2);
            edg[edg_cnt].s = i;
            edg[edg_cnt].e = j;
            edg[edg_cnt++].v = t;
        }
        sort(edg, edg + edg_cnt);
        for (int i = 0; i < edg_cnt; i++) {
            int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
         if(fa != fb){
             ans = edg[i].v;
             my_union[fa] = fb;
             cnt++;
             if (n - cnt == p) {
                 break;
             }
        
        }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
