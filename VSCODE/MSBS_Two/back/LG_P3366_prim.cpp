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


struct edge {
    int e, v, next;
};

struct node {
    int now, v;
    bool operator < (const node &b) const {
        return this->v > b.v;
    }
};

edge edg[400005];
int n, m
int main()
{
   
   system("pause");
   return 0;
}
