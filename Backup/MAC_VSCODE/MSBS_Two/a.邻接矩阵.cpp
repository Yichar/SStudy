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
#include <cstring>

using namespace std;

int n, m, arr[105][105];

int main()
{   
    //实际上是0x3f3f3f3f 10亿多
    memset(arr, 0x3f, sizeof(arr));
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
       int s, e, v;
       cin >> s >> e >> v;
       arr[s][e] = min(v, arr[s][e]);
   }
   for (int i = 1; i <=n ; i++) {
       for (int j = 1; j <= n; j++) {
           if (arr[i][j] != 0x3F3F3F3F)
                cout << arr[i][j] << " ";
            else{
                cout << 0 << " ";
            }
            
       }
        cout << endl;
   }
   return 0;
}
