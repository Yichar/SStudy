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



int n,m, arr[105][105], in_degree[105], out_degree[105];
int ans;
int main()
{
   memset(arr,0x3f,sizeof(arr));
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
       int a, b;
       cin >> a >> b;
       arr[a][b] = 1;
   }
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           for (int k = 1; k <= n; k++) {
               arr[j][k] = min(arr[j][k],arr[j][i] + arr[i][k]);
           }
       }
   }
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           if (arr[i][j] != 0x3f3f3f3f) {
               out_degree[i]++;
               in_degree[j]++;
           }
       }
   }
   for (int i = 1; i <= n; i++) {
       if (in_degree[i] + out_degree[i] == n -1)
        ans++;
   }
   cout << ans << endl;
   return 0;
}
