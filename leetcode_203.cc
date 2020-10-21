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
    ListNode* removeElements(ListNode* head, int val) {
        if(NULL == head)
        {
            return NULL;
        }
        ListNode* newHead = head;
        ListNode* prev = NULL,*cur = head;
        while(cur != NULL)
        {
            if(cur->val == val)
            {
                ListNode* temp = cur;
                if(cur == newHead)
                {
                    
                    newHead = cur->next;
                    delete cur;
                    cur = newHead;
                    continue;
                }
                else
                {
                    prev->next = cur->next;
                    delete cur;
                    //cur = prev->next;
                    cur = prev;
                }
            }
            prev = cur;
            if(cur != NULL)
            {
                cur = cur->next;
            }
        }
        return newHead;
    }
};




/*
参考其他人提交的代码:使用哨兵节点
*/
class Solution {
  public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    while (curr != nullptr) {
      if (curr->val == val) {
        prev->next = curr->next;
        toDelete = curr;
      } else prev = curr;

      curr = curr->next;

      if (toDelete != nullptr) {
        delete toDelete;
        toDelete = nullptr;
      }
    }

    ListNode *ret = sentinel->next;
    delete sentinel;
    return ret;
  }
};

