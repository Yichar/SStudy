/*************************************************************************
	> File Name: HZ261_对顶栈.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  2/19 17:01:33 2021
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
using namespace std;

class NewStruct {

public:
    NewStruct() {
        sum.push_back(0);
        ans.push_back(INT64_MIN);
    }
    void insert(long long x) {
        s1.push(x);   
        long long val = s1.top() + sum[sum.size() - 1];
        sum.push_back(val);
        ans.push_back(max(ans[ans.size()-1],val));
        return;
    }
    void del(){
        if (s1.empty()) return;
        s1.pop();
        sum.pop_back();
        ans.pop_back();
        return;
    }
    void move_left(){
        if (s1.empty()) return;
        s2.push(s1.top());
        s1.pop();
        sum.pop_back();
        ans.pop_back();
        return;
    }
    void move_right(){
        if (s2.empty()) return;
        insert(s2.top());
        s2.pop();
        return;
    }
    long long query(long long k) {
        if (ans.size() == 1) return 0;
        return ans[k];
    }

private:
    stack<long long> s1,s2;
    vector<long long> sum; //s1前缀和
    vector<long long> ans; //sum前i位最大值
};

int main() {

    long long n;
    cin >> n;
    string op;
    int val;
    NewStruct s;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op[0]) {
            case 'I': cin >> val; s.insert(val); break;
            case 'D': s.del(); break;
            case 'L': s.move_left();break;
            case 'R':s.move_right();break;
            case 'Q': {
                cin >> val; cout << s.query(val) << endl;break;
            
            }
        }  
    }

  return 0; 
}
