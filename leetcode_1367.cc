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
    bool searchPath(ListNode* head,TreeNode* root)
    {
        if(NULL == head)
        {
            return true;
        }

        if(head != NULL && root == NULL)
        {
            return false;
        }

        if(head->val != root->val)
        {
            return false;
        }
        return searchPath(head->next,root->left) || searchPath(head->next,root->right);
    }
    bool isSubPathCore(ListNode* head,TreeNode* root)
    {
        
        bool haspath = false;
        haspath = searchPath(head,root);
        if(!haspath && root->left)
        {
            haspath = isSubPathCore(head,root->left);
        }
        if(!haspath && root->right)
        {
            haspath = isSubPathCore(head,root->right);
        }
        return haspath;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(NULL == head || NULL == root)
        {
            return false;
        }
        return isSubPathCore(head,root);
    }
};