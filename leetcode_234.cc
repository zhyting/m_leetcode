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
    bool isPalindrome(ListNode* head) {
        if(NULL == head)
        {
            return true;
        }
        deque<int> deq;
        ListNode* pNext = head;
        while(pNext != NULL)
        {
            deq.push_back(pNext->val);
            pNext = pNext->next;
        }
        while(!deq.empty())
        {
            int front = deq.front();
            int back = deq.back();
            deq.pop_back();
            if(!deq.empty())
            {
                deq.pop_front();
            }
            if(front != back)
            {
                return false;
            }
        }
        return true;
    }
};




class Solution {
public:
    //题解：快慢指针法，快指针走两步，慢指针走一步，找到链表的中点。然后，翻转后半部分。最后从头、中点开始判断是否相同。
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode *fast=head,*slow=head,*pre=nullptr;
        //1、找到链表的中点，链表长度奇偶不影响
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //2、将slow之后链表进行断开且反转，最后翻转完成之后pre指向反转链表的头节点
        while(slow){
            ListNode *p=slow->next;
            slow->next=pre;
            pre=slow;
            slow=p;
        }
        //3、前后链表进行比较，注意若为奇数链表，后半部分回比前部分多1一个节点，然而我们只比较相同长度的节点值，巧妙地避开这点判断
        while(head&&pre){
            if(head->val!=pre->val)return false;
            head=head->next;
            pre=pre->next;
        }
        return true;
    }
};







