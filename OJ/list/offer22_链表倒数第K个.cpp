/*************************************************************************
	> File Name: offer22_链表倒数第K个.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  1/17 19:44:46 2021
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = k - 1; i > 0; i--)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
