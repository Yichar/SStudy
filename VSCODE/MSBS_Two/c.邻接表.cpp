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

int n, m;
int main()
{   
    cin >> n >> m;
    vector<vector<pair<int,int> > > edg(n + 1,vector<pair<int,int> > {});
    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        edg[s].push_back(make_pair(e, v));
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        for (int j = 0; j < edg[i].size(); j++) {
            cout << "{" << edg[i][j].first << "," << edg[i][j].second << "} "; 
        }
        cout << endl;
    }
   return 0;
}
