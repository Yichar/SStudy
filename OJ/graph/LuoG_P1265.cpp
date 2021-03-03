/*************************************************************************
	> File Name: LuoG_P1265.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  3/ 2 19:58:33 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
    int now;
    double v;
    bool operator < (const node &b) const {
        return this->v > b.v;
    }
};




int n, xy[5005][2],mark[5005];
double ans,num[5005];
int cnt;

double func(int a, int b) {
    double t1 = xy[a][0] - xy[b][0];
    double t2 = xy[a][1] - xy[b][1];
    return sqrt(t1 * t1 + t2 * t2);
}


int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        num[i] = 9999999;
    }
    priority_queue <node> que;
    que.push((node){1,0});
    num[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.top();
        if (mark[temp.now] == 1) continue;
        mark[temp.now] = 1;
        ans += temp.v;
        cnt++;
        if (cnt == n) break;
        for (int i = 1;  i <= n; i++) {
            if (i != temp.now && mark[i] == 0)  {
                double v = func(temp.now, i);
                if (v < num[i]) {
                    num[i] = v;
                    que.push((node){i,v});
                }
            }
        }
    }
    printf("%.2f\n",ans);
    return 0;
}

