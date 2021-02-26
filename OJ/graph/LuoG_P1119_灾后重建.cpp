/*************************************************************************
	> File Name: LuoG_P1119_灾后重建.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 四  2/25 20:13:07 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int n , m, arr[205][205], num[205], now, q;
//now 表示修复进度



int main() {
    memset( arr , 0x3f, sizeof(arr));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        arr[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b ,c;
        cin >> a >> b >> c;
        a++,b++;
        arr[a][b] = arr[b][a] = c;
    }
    cin >> q;
    while (q--) {
        int x, y , t;
        cin >> x >> y >> t;
        x++,y++;
        while (num[now] <= t && now <= n) {
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    arr[i][j] = min(arr[i][j],arr[i][now]+arr[now][j]);
                }
            }
            now++;
        }
    
        if (arr[x][y] == 0x3f3f3f3f || num[x] > t || num[y] > t) {
            cout << -1 << endl;
        } else  {
            cout << arr[x][y] << endl;
        }

    }
    return 0;
}

