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
    void deleteNode(ListNode* node) {
        ListNode* pNext = node->next;
        node->val = pNext->val;
        node->next = pNext->next;
        delete pNext;
        pNext = NULL;
        
    }
};