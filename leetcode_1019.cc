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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        if(NULL == head)
        {
            return ret;
        }

        stack<int> temp;
        ListNode* pNext = head;
        int i = 0;
        while(pNext != NULL)
        {
            while(!temp.empty() && pNext->val > ret[temp.top()])
            {
                ret[temp.top()] = pNext->val;
                temp.pop();
            }
            temp.push(i++);
            ret.push_back(pNext->val);
            pNext = pNext->next;
        }

        while(!temp.empty())
        {
            ret[temp.top()] = 0;
            temp.pop();
        }
        return ret;
    }
};