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


struct node {
    int x, y, step;
    double h; //终点距离
    bool operator< (const node &b) const {
        return this->step + this->h > b.step + b.h;
    }
};


// F = G + H
// F = 步数 + 预估到终点的距离
// F值作为优先队列排序

int n,m,sx,sy,ex,ey,cnt;
char mmap[2005][2005];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1 , 1, 1, -1, -1, 1, -1, -1};

int prex[2005][2005],prey[2005][2005];


double func(int x, int y) {
    int a = ex - x, b = ey - y;
    return sqrt(a * a + b * b);
}
void p() {
    cout << "*************____________***********" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
            if (mmap[i][j] == 'x')
                mmap[i][j] = 'X';
        }
        cout << endl;
    }

}


void fin(int x, int y) {
    if (mmap[x][y] == 'S') //起点的上一个坐标是0
        return;
    mmap[x][y] = 'o';
    fin(prex[x][y],prey[x][y]);
   
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S')
                 sx = i , sy = j;
            if (mmap[i][j] == 'T')
                 ex = i , ey = j;
    }
    }
   
   priority_queue<node> que;
   que.push((node){sx, sy, 0, func(sx, sy)});
   while ( !que.empty()) {
       node temp = que.top();
       que.pop();
       for( int i = 0; i < 8; i++) {
           int x = temp.x + dir[i][0];
           int y = temp.y + dir[i][1];
           if (mmap[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                fin(temp.x,temp.y); //到达终点了，从上一个点开始找恢复路径
               
                p();
                return 0;
           }
           if (mmap[x][y] == '.') {
               mmap[x][y] = 'x';
               que.push((node) {x , y, temp.step + 1, func(x,y)});
               prex[x][y] = temp.x;
               prey[x][y] = temp.y;
               cnt++;
               if (cnt % 10 == 0) {
                   p();
               }
    
           }
       }
   }
   cout << -1 << endl;
   return 0;
}
