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
    bool isSymmetricCore(TreeNode* root1,TreeNode* root2)
    {
        if(NULL == root1 && NULL == root2)
        {
            return true;
        }
        /*
        if(root1 != NULL || root2 != NULL)
        {
            return false;
        }
        */
        if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        {
            return false;
        }
        if(root1->val != root2->val)
        {
            return false;
        }
        return isSymmetricCore(root1->left,root2->right) && isSymmetricCore(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(NULL == root)
        {
            return true;
        }

        return isSymmetricCore(root,root);
    }
};