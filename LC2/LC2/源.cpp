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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int remain = 0;
		ListNode * result = new ListNode((l1->val + l2->val) % 10);
		remain = (l1->val + l2->val) / 10;
		ListNode * cur = result;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL && l2 != NULL)
		{
			cur->next = new ListNode(0);
			cur = cur->next;

			cur->val = (remain + l1->val + l2->val) % 10;
			remain = (remain + l1->val + l2->val) / 10;

			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == NULL)
		{
			while (l2 != NULL)
			{
				cur->next = new ListNode(0);
				cur = cur->next;

				cur->val = (remain + l2->val) % 10;
				remain = (remain + l2->val) / 10;

				l2 = l2->next;

			}
		}
		else if (l2 == NULL)
		{
			while (l1 != NULL)
			{
				cur->next = new ListNode(0);
				cur = cur->next;

				cur->val = (remain + l1->val) % 10;
				remain = (remain + l1->val) / 10;

				l1 = l1->next;
			}
		}
		if (remain != 0)
		{
			cur->next = new ListNode(remain);
		}
		return result;
	}
};