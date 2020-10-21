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
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int len1 = 0;
        int len2 = 0;
        int diff = 0;

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
        diff = len1 - len2;
        if(diff > 0)
        {
            p1 = headA;
            p2 = headB;
        }
        else 
        {
            p1 = headB;
            p2 = headA;
            diff = (-diff);
        }

        while((diff--) > 0)
        {
            p1 = p1->next;
        }

        while(p1 != NULL && p2 != NULL && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL == p1 ? NULL : p1;
    }
};