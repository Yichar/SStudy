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
//ind 拆分出ind件物品
int n, vall, ind = 1, v[20005], w[20005], ans[10005];
int bit2[25];
void init() {
    int t = 1;
    for (int i = 0; i < 21; i++) {
        bit2[i] = t;
        t *= 2;
    }
}
int main()
{
    init();
    cin >> vall >> n;
    for (int i = 1; i <= n; i++) {
        int a, b ,c, cnt = 0;
        cin >> a >> b >> c;
        while (c) {
            if (c > bit2[cnt]) {
                v[ind] = a * bit2[cnt];
                w[ind] = b * bit2[cnt];
                c -= bit2[cnt];
                cnt++;
            } else {
                v[ind] = a * c;
                w[ind] = b * c;
                c = 0;
            }
            ind++;
        }
    }
    for (int i = 1; i <= ind; i++) {
        for (int j = vall; j >= v[i]; j--) {
            ans[j] = max(ans[j],ans[j-v[i]] + w[i]);
        }
    }
   cout << ans[vall] << endl;
 
   return 0;
}
