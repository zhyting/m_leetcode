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
    //return carry
    int addTwoNumbersCore(ListNode* l1,ListNode* l2,int diff)
    {
        if(NULL == l1 && NULL == l2)
        {
            return 0;
        }
        int carry = 0;
        int val = 0;
        if(diff == 0)
        {
            carry = addTwoNumbersCore(l1->next,l2->next,diff);
            val = carry + l1->val + l2->val;
        }
        else{
            diff--;
            carry = addTwoNumbersCore(l1->next,l2,diff);
            val = carry + l1->val;
        }
        l1->val = val % 10;
        carry = val / 10;
        return carry;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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

        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int len1 = 0;
        int len2 = 0;
        ListNode *ptr = NULL;
        while(p1 != NULL)
        {
            p1 = p1->next;
            len1++;
        }
        while(p2 != NULL)
        {
            p2 = p2->next;
            len2++;
        }

        //p1 始终指向的是长一点的链表
        int diff = len1-len2;
        if(diff > 0)
        {
            p1 = l1;
            p2 = l2;
        }
        else
        {
            p1 = l2;
            p2 = l1;
            diff = (-diff);
        }
        int carry = addTwoNumbersCore(p1,p2,diff);
        ListNode* newHead = p1;
        if(carry == 1)
        {
            newHead = new ListNode;
            newHead->val = 1;
            newHead->next = p1;
        }

        return newHead;
    }
};