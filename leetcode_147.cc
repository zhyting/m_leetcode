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
    ListNode* insertionSortList(ListNode* head) {
        if(NULL ==head || NULL == head->next)
        {
            return head;
        }
        ListNode sentry;
        sentry.val = 0;
        sentry.next = head;
        ListNode* cur = head;

        while(cur->next != NULL)
        {
            ListNode* pNext = cur->next;
            if(pNext != NULL && pNext->val > cur->val)
            {
                cur = pNext;
            }
            else
            {
                cur->next = pNext->next;
                ListNode* prev = &sentry;
                ListNode* ptr = sentry.next;
                while(ptr->val < pNext->val)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                pNext->next = ptr;
                prev->next = pNext;
            }
        }
        return sentry.next;
    }
};