/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//递归版本
class Solution {
public:

    ListNode* mergeList(ListNode* head1,ListNode* head2)
	{
		if(NULL == head1 && NULL == head2)
		{
			return NULL;
		}
		if(NULL == head1)
		{
			return head2;
		}
		if(NULL == head2)
		{
			return head1;
		}

		ListNode* pCur = NULL;
		ListNode* p1 = head1;
		ListNode* p2 = head2;
		ListNode sentry;
		sentry.next = (head1->val < head2->val ? head1 : head2);

		while(p1 != NULL && p2 != NULL)
		{
			if(p1->val < p2->val)
			{
				pCur = p1;
				p1 = p1->next;
				if(p1 != NULL && p1->val < p2->val)
				{
					pCur->next = p1;
				}
				else 
				{
					pCur->next = p2;
				}
			}
			else
			{
				pCur = p2;
				p2 = p2->next;
				if(p2 != NULL && p2->val <= p1->val)
				{
					pCur->next = p2;
				}
				else 
				{
					pCur->next = p1;
				}
			}
		}
		return sentry.next;
	}

    ListNode* sortList(ListNode* head) {
        /*
    		查找中间节点
    		左右递归
    		合并
    	*/

    	if(NULL == head || NULL == head->next)
    	{
    		return head;
    	}
    	ListNode* slow = head,*fast = head->next->next;

    	while(fast != NULL && fast->next != NULL)
    	{
    		slow = slow->next;
    		fast = fast->next;
    	} 
    	ListNode* right = sortList(slow->next);
    	slow->next = NULL;
    	ListNode* left= sortList(head);
    	ListNode* newHead= mergeList(left,right);
    	return newHead;
    }
};



//非递归版本
