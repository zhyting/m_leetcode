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

        ListNode* prev = NULL;
        ListNode* pCur = head;
        ListNode* pNext = pCur->next;

        while(pNext != NULL)
        {
           while(pNext != NULL && pCur->val == pNext->val)
           {
               pNext = pNext->next;
           } 
           pCur->next = pNext;
           pCur = pNext;
           //此处需要对 pNext 进行判断，pNext 可能为NULL，这时就会出现段错误的问题。
           if(pNext != NULL)
           {
               pNext = pNext->next;
           }
        }
        return head;
    }
};














