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
int n,vall,v[10005],w[10005],ans[10005];
int main()
{
   cin >> n >> vall;
   for (int i = 1; i <= n; i++) {
       cin >> v[i] >> w[i];
   }
    for (int i = 1; i <= n; i++){
        //从前往后
        for (int j = v[i]; j <= vall; j++) {
            ans[j] = max(ans[j],ans[j-v[i]] + w[i]);
        }
    }
    cout << ans[vall] << endl;
   return 0;
}
