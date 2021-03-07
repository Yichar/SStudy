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



int n, m;
int num[205];
int arr[205][205];
int q;
int now; // 第几天
int main()
{
    memset(arr, 0x3f, sizeof(arr));
   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
       cin >> num[i];
       arr[i][i] = 0;
   }
   for (int i = 1; i <= m; i++) {
       int a, b , c;
       cin >> a >> b >> c;
       a++, b++;
        arr[a][b] = c;
        arr[b][a] = c; 
        
   }
   cin >> q;
   while (q--) {
       int x,y,t;
       cin >> x >> y >> t;
       x++, y++;
       while (num[now] <= t && now <= n) {
           for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= n; j++) {
                    arr[i][j] = min(arr[i][j],arr[i][now] + arr[now][j]);
               }
           }
           now++;
       }
       // 2个点都修复了
        if (arr[x][y] == 0x3f3f3f3f || num[x] > t || num[y] > t)
            cout << -1 << endl;
        else
            cout << arr[x][y] << endl;
        
   }
   return 0;
}
