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

int vall, n;
int v[105];
int w[105];
int ans[105];
int main()
{
   cin >> vall >> n;
  
   for (int i = 1; i <= n; i++) {
       for (int j = vall; j >= v[i]; j--) {
           ans[j] = max(ans[j],ans[j - v[i]] + w[i]);
       }
   }
   cout << ans[vall];
   return 0;
}
