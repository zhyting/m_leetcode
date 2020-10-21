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
    TreeNode* inorderSuccessorCore(TreeNode* root,TreeNode* p,bool& flag)
    {
        if(NULL == root)
        {
            return NULL;
        }
        TreeNode* ret = NULL;
        
        if(ret == NULL && root->left)
        {
            ret = inorderSuccessorCore(root->left,p,flag);
        }

        if(flag == true && NULL == ret)
        {
            ret = root;
            return ret; 
        }

        if(flag == false && root->val == p->val)
        {
            flag = true;
        }

        if(ret == NULL && root->right)
        {
            ret = inorderSuccessorCore(root->right,p,flag);
        }
        return ret;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(NULL == root || NULL == p)
        {
            return NULL;
        }

        bool flag = false;
        return inorderSuccessorCore(root,p,flag);
    }
};