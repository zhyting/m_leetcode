/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1 && NULL == l2)
	    {
		    return NULL;
	    }
	    if(NULL == l1)
	    {
		    return l2;
	    }
	    if(NULL == l2)
	    {
		    return l1;
	    }

	    ListNode* pCur = NULL;
	    if(l1->val < l2->val)
	    {
		    pCur = l1;
		    pCur->next = mergeTwoLists(l1->next,l2);
	    }
	    //head1->m_nVal > head2->m_nVal & head1->m_nVal == head2->m_nVal 
	    else 
	    {
		    pCur = l2;
		    pCur->next = mergeTwoLists(l1,l2->next);
	    }
	    return pCur;
    }
};





ListNode* mergeList(ListNode* head1,ListNode* head2)
{
	ListNode* pCur = NULL;
	ListNode* p1 = head1;
	ListNode* p2 = head2;
	ListNode sentry;
	sentry.m_pNext = (head1->m_nVal < head2->m_nVal ? head1 : head2);


	while(p1 != NULL && p2 != NULL)
	{
		if(p1->m_nVal < p2->m_nVal)
		{
			pCur = p1;
			p1 = p1->m_pNext;
			if(p1!=NULL && p1->m_nVal < p2->m_nVal)
			{
				pCur->m_pNext = p1;
			}
			else 
			{
				pCur->m_pNext = p2;
			}
		}
		else 
		{
			pCur = p2;
			p2 = p2->m_pNext;
			/*
				注意，此处的条件应该设置为 p2->m_nVal <= p1->m_nVal,注意这里的等于号，
				这主要是针对两条链表有相同节点值，在比较时候如果没有等号，会漏掉节点，比如
				l1 : 1->1->NULL
				l2 : 1->1->NULL
				如果没有等号，则输出的结果变成 1->1->1->NULL 
			*/
			if(p2 != NULL && p2->m_nVal <= p1->m_nVal)
			{
				pCur->m_pNext = p2;
			}
			else 
			{
				pCur->m_pNext = p1;
			}
		}
	}
	return sentry.m_pNext;
}
