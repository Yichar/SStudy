#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


struct  node {
    int x, y ,step;
};

int n, m , cnt;
int sx,sy,ex,ey;
char mmap[2005][2005];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0,1 , 1, 1, -1, -1, 1, -1, -1};

void p() {
    cout << "-----------------------" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
            if (mmap[i][j] == 'x')
                mmap[i][j] = 'X';
        }
    }
}
int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S')
                 sx = i , sy = j;
            if (mmap[i][j] == 'T')
                ex = i , ey = j;
        }
    }

    queue<node> que;
    que.push((node){sx,sy,0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (mmap[xx][yy] == 'T') {
                
            }
        }
    }
  // system("pause");
   return 0;
}
