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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(NULL == headA || NULL == headB)
        {
            return NULL;
        }
        int lenA = 0;
        int lenB = 0;
        ListNode* pNext1 = headA;
        ListNode* pNext2 = headB;
        while(pNext1 != NULL)
        {
            pNext1 = pNext1->next;
            lenA++;
        }
        while(pNext2 != NULL)
        {
            pNext2 = pNext2->next;
            lenB++;
        }

        int diff = 0;
        if(lenA > lenB)
        {
            pNext1 = headA;
            pNext2 = headB;
            diff = lenA - lenB;
        }
        else
        {
            pNext1 = headB;
            pNext2 = headA;
            diff = lenB - lenA;
        }

        while((diff--)>0)
        {
            pNext1 = pNext1->next;
        }
        
        while(pNext1 != NULL && pNext2!=NULL && pNext1 != pNext2)
        {
            pNext1 = pNext1->next;
            pNext2 = pNext2->next;
        }
        return pNext1;
    }
};