/*************************************************************************
	> File Name: leecode86_分隔链表.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 日  1/ 3 09:20:12 2021
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *new_head = new ListNode(-999);
        new_head->next = head;  //头结点
        ListNode *insert_pre = new_head;
        ListNode *delete_pre = NULL;
        //找第一个大于x节点的前节点
        while( insert_pre->next != NULL && insert_pre->next->val < x) {
            insert_pre = insert_pre->next;
        }
        ListNode *now = insert_pre;
        //遍历链表
        while (now != NULL && now->next != NULL) {
            //遇到下一个值小于x
            if(now->next->val < x) {
                
                ListNode *temp = now->next;
                //跳过当前节点
                now->next = now->next->next;
                //插入temp到insert_pre后面，更新insert_pre
                ListNode *next = insert_pre->next;
                insert_pre->next = temp;
                temp->next = next;
                insert_pre = temp;
            } else 
                now = now->next;
        }
        return new_head->next;
    }
};
