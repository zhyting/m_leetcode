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
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }
        
        ListNode sentry;
        sentry.val = 0;
        sentry.next = head;
        ListNode* prev = &sentry;
        ListNode* pCur = head;
        ListNode* pNext = pCur->next;

        while(pNext != NULL)
        {
            while(pNext != NULL && pCur->val == pNext->val)
            {
                pNext = pNext->next;
            }

            //有重复
            if(pCur->next != pNext)
            {
                prev->next = pNext;
            }
            //无重复
            else
            {
                prev = pCur;
            }
            pCur = pNext;
            if(pNext != NULL)
            {
                pNext = pNext->next;
            }
        }
        
        return sentry.next;
    }
};