/*************************************************************************
	> File Name: offer52_链表公共节点.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  1/17 21:59:22 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while ( tempA != tempB) {
          tempA = tempA ? tempA->next : headB;
          tempB = tempB ? tempB->next : headA;
        }
        return tempA;
    }
};

