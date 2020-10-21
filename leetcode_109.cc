/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBSTCore(vector<int>& vec,int start,int end)
    {
        if(start > end )
        {
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = sortedListToBSTCore(vec,start,mid-1);
        root->right = sortedListToBSTCore(vec,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(NULL == head)
        {
            return NULL;
        }
        vector<int> vec;
        ListNode* pNext = head;
        while(pNext != NULL)
        {
            vec.push_back(pNext->val);
            pNext = pNext->next;
        }
        return sortedListToBSTCore(vec,0,vec.size()-1);
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(NULL == head)
        {
            return NULL;
        }
        else if(head->next == NULL)
        {
            /*
                当链表中只有一个节点时，需要作特殊处理，否则就会一直递归
            */
            TreeNode* node = new TreeNode(head->val);
            return node;
        }

        ListNode* fast=head,*slow = head;
        ListNode* prev = NULL;
        while(fast!= NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};




