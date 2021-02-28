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

using namespace std;

int n, m, s, arr[1005][1005];
int main()
{
    memset(arr, 0x3f, sizeof(arr));
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        arr[s][e] = min(arr[s][e],v);
        arr[e][s] = min(arr[e][s],v);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++)
             arr[j][k] = min(arr[j][k],arr[j][i] + arr[i][k]);
        }
    }
   
   for (int i = 1; i <= n; i++) {
       if (arr[s][i] != 0x3F3F3F3F)
        cout << arr[s][i] << endl;
       else 
        cout << -1 << endl;
   }
   system("pause");
   return 0;
}
