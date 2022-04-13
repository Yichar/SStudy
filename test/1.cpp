/**********************
 * @author: Yichar
 * @file：
 * @date: 2022-04-10 09:44:49
 * @Email：597297146@qq.com
 **********************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;


double r,a,b,c;
int A,B,C,D;
int main() {

    cin >> A >> B ;
    C = (B - 2 * A) / 2;
    D = (4 * A - B) / 2;
    cout << D << " " << C;
    system("Pause");
    return 0;
}