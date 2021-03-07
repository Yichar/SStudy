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

int n,vall,v[10005],w[10005],ans[10005][100005];
int main()
{
    cin >> n >> vall;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= vall; j++) {
            if (j < v[i])
                ans[i][j] = ans[i-1][j];
            else
            {
                ans[i][j] = max(ans[i-1][j],ans[i][j-v[i]] + w[i]);
            }
            
        }
    }
    cout << ans[n][vall] << endl;
   
   return 0;
}
