class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode* p1 = head,*p2 = head->next;
        ListNode* prev = NULL;
        ListNode* newHead = p2;
        while(p2 != NULL)
        {
            p1->next = p2->next;
            p2->next = p1;

            if(prev != NULL)
            {
                prev->next = p2;
            }
            prev = p1;
            p1 = p1->next;
            if(NULL == p1)
            {
                break;
            }
            p2 = p1->next;
        }
        return newHead;
    }
};















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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(NULL == head)
        {
            return head;
        }

        ListNode* p1 = head,*p2 = head;
        ListNode* prev = NULL;
        ListNode* newHead = p2;
        while()
        {
            int num = k;
            while((--num) > 0)
            {
                p2 = p2->next;
            }
            p1->next = p2->next;
            
            ListNode* inprev = p1->next;
            ListNode* pNext = p1;
            while(pNext != p2)
            {
                ListNode* temp = pNext->next;
                pNext->next = inprev;
                inprev = pNext;
                pNext = temp;
            }
            p2->next = pNext;

            if(prev != NULL)
            {
                prev->next = p2;
            }
            prev = p1;
            p1 = p1->next;
            if(NULL == p1)
            {
                break;
            }
            p2 = p1;
        }
        
    }
};








