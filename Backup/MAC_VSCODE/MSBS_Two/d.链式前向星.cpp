#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
using namespace std;

struct edge {
    int e, v, next;
};


edge edg[100005];
int n,m,head[10005];


int main() {
    memset(head, - 1, sizeof(head));
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        edg[i].e = e;
        edg[i].v = v;
        edg[i].next = head[s];
        head[s] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " : " ;
        for (int j = head[i]; j != -1; j = edg[j].next) {
            cout << "{" << edg[j].e << "," << edg[j].v << "}";
        }
        cout << endl;
    }

    return 0;
}