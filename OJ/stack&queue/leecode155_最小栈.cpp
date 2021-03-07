/*************************************************************************
	> File Name: leecode155_最小栈.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 五  3/ 5 22:45:44 2021
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


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            s2.push(x);
        } else {
            s1.push(x);
            if (s2.top() >= x) {
                s2.push(x);
            } else  {
                s2.push(s2.top());
            }
        }
            
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
    stack<int> s1;
    stack<int> s2;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
