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
int vall, mall;
int n;
int v[55],m[55],w[55];
//前i种物品，总体积为j，总质量为k
int ans[55][405][405];
int main()
{
   cin >> vall >> mall >> n;
   for (int i = 1; i <= n; i++) {
       cin >> v[i] >> m[i] >> w[i];
   } 
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= vall; j++) {
           for (int k = 1; k <= mall; k++) {
               if (j < v[i] || k < m[i]) {
                   ans[i][j][k] = ans[i-1][j][k];
               } else {
                   ans[i][j][k] = max(ans[i-1][j][k],ans[i-1][j-v[i]][k-m[i]] + w[i]);
               }
           }
       }
   }
   cout << ans[n][vall][mall] << endl;
   return 0;
}
