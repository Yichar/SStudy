#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

//样例
// 先： BGLRAID
// 中： RLGBADI
// 后：RLGDIAB

char q[105], z[105], h[105];
//前序 中序 求后序
void func1(int ql, int qr, int zl, int zr) {
    if (ql > qr) return;
    if (ql == qr) {   //长度为1
        cout << q[ql];
        return;
    }    
    char root = q[ql];
    int ind = zl;
    while (z[ind] != root) ind++; //在中序里找到root位置
    // ql + ind - zl => ql + 1 + (ind - zl - 1)
    func1(ql + 1, ql + ind - zl, zl, ind - 1);
    func1(ql + ind - zl + 1, qr, ind + 1, zr);
    cout << root;

}
//中序 后序 求先序
void func2(int zl,int zr,int hl,int hr) {
    if(zl >  zr) return;
    if (zl == zr) {
        cout << z[zl];
        return;
    } 
    char root = h[hr];
    int ind = zl;
    while(z[ind] != root) ind++;
    cout << root;
    func2(zl, ind - 1, hl , hl + ind - zl -1);
    func2(ind + 1, zr , hl + ind - zl, hr - 1);

}

int main()
{
    // cin >> q >> z;
    // func1(0, strlen(q) - 1,0,strlen(z) - 1);
    cin >> z >> h;
    func2(0, strlen(z) - 1,0,strlen(h) - 1);
    cout << endl;
   return 0;
}
