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
    ListNode* oddEvenList(ListNode* head) {
        if(NULL == head)
        {
            return NULL;
        }
        ListNode* head1 = head,*p1=head;
        ListNode* head2 = head->next,*p2 = head->next;
        //链表中只有1个节点或者两个节点，则不需要调整
        if(NULL == p1->next|| p2->next == NULL)
        {
            return head; 
        }

        /*
            可以尝试将此处的条件修改为 p1->next != NULL && p2->next != NULL ，那么break应该就不需要了
        */
        while(p1!=NULL && p2!=NULL)
        {
            p1->next = p2->next;
            if(NULL == p1->next)
            {
                break;
            }
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }
        p1->next = head2;
        return head1;
    }
};