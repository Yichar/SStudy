#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int n, m, s;
int arr[1005][1005];

int main()
{
   memset(arr, 0x3f, sizeof(arr));
   cin >> n >> m >> s;
   for (int i = 1; i <= m; i++) {
       int a, b, c;
       cin >> a >> b >> c;
       arr[a][b] = min(arr[a][b],c);
       arr[b][a] = min(arr[b][a],c);
       arr[i][i] = 0; //必然是0
   }
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           for (int k = 1; k <= n; k++) {
               arr[j][k] = min(arr[j][k],arr[j][i] + arr[i][k]);
           }
       }
   }
   for (int i = 1; i <=  n; i++) {
       if (arr[s][i] != 0x3f3f3f3f)
            cout << arr[s][i] << endl;
        else
            cout << -1 << endl;
        
   }
   return 0;
}
