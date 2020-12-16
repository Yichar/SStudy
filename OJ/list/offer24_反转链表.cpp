class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* Next = NULL;
		while(head){
			Next = head->next;
			head->next = pre;
			pre = head;
			head = Next;
		}
		return pre;
		
	}
};