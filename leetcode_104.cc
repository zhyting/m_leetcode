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
    int maxDepthCore(TreeNode* root)
    {
        if(NULL == root)
        {
            return 0;
        }
        int left = 0;
        int right = 0;
        if(root->left != NULL)
        {
            left = maxDepthCore(root->left);
        }
        if(root->right != NULL)
        {
            right = maxDepthCore(root->right);
        }
        return left > right ? left+1 : right+1;
    }
    int maxDepth(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }
        return maxDepthCore(root);
    }
};