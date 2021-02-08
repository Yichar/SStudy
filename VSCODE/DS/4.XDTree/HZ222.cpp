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

#define MAX_N 10000
struct {
    int max_num;
    int l,r;
} tree[MAX_N << 2]; // 开四倍

int arr[MAX_N + 5];


void update(int ind) {
    //左子树右子树的最大值选一个
    tree[ind].max_num = max(tree[ind << 1].max_num,tree[ind << 1 | 1].max_num);
    return;
}


void build_tree(int ind,int l,int r) {
    tree[ind].l = l;
    tree[ind].r = r;
    if (l == r) {
        tree[ind].max_num = arr[l];   
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(ind * 2, l, mid);
    build_tree(ind * 2 + 1,mid + 1, r);
    return;    
}


void modify(int ind, k , int val) {
    if (tree[ind].l == tree[ind].r) {
        tree[ind].max_num = val;
        return;
    }
    int mid = (tree[ind].l + tree[ind].r) >> 1;
    if (k <= mid) 
        modify(ind << 1, k, val);
    else
        modify(ind << 1 | 1, k ,val);
    update(ind);
    return;

}

//查询x y 区间和
int query(int ind, int x,int y) {
    if (tree[ind].l >= x && tree[ind].r <= y)
        return tree[ind].max_num;
    int ans = INI32_MIN;
    int mid = (tree[ind].l + tree[ind].r) >> 1;

 }
int main()
{
   int n,m,a,b,c;
   cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build_tree(1,1,n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        switch (a) {
            case 1:modify(1, b, c);break;
            case 2: {
                if (b > c) {
                    cout << "-2147483658" << endl;
                    break;
                }
                cout << query(1,b,c);
        }
    }
  
   return 0;
}
