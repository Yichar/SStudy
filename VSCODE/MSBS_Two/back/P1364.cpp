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


int n;
int arr[105][105];
int people[105];
int main()
{
    memset(arr,0x3f, sizeof(arr));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int w, l , r;
        cin >> w >> l >> r;
        people[i] = w;
        if ( l != 0) {
            arr[i][l] = 1;
            arr[l][i] = 1;
        }
        if ( r != 0) {
            arr[i][r] = 1;
            arr[r][i] = 1;
        }
        arr[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k],arr[j][i] + arr[i][k]);
            }
        }
    }

    int ans = 9999999;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            temp += arr[i][j] * people[j];
        }
        ans = min(ans,temp);
    }
    cout << ans << endl;
   return 0;
}
