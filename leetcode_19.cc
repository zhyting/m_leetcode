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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head || n <=0)
        {
            return head;
        }

        ListNode sentry;
        sentry.val = 0;
        sentry.next = head;
        ListNode* slow = head,*fast = head;
        ListNode* prev = &sentry;

        while(n-- > 0)
        {
            fast = fast->next;
        }

        if(n > 0 && NULL == false)
        {
            return head;
        }

        while(slow != NULL && fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;   
        }

        prev->next = slow->next;
        delete slow;
        return sentry.next;
    }
};