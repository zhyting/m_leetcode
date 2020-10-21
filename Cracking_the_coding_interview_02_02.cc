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
    int kthToLast(ListNode* head, int k) {
        ListNode* slow = head,*fast = head;
        ListNode* prev = NULL;
        int ret=0;
        
        while(fast != NULL && (k--) > 0)
        {
            fast = fast->next;
        }
        if(NULL == fast && k > 0)
        {
            return 0;
        }
        while(fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(prev != NULL)
        {
            prev->next = slow->next;
        }
        ret = slow->val;
        delete slow;
        slow = NULL;
        return ret;
    }
};