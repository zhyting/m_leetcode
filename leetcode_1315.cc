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
    int searchGrandson(TreeNode* root)
    {
        if(NULL == root)
        {
            return 0;
        }
        int sum = 0;
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;
        if(left_node != NULL)
        {
            if(left_node->left != NULL)
            {
                sum += left_node->left->val;
            }
            if(left_node->right != NULL)
            {
                sum += left_node->right->val;
            }
        }

        if(right_node != NULL)
        {
            if(right_node->left != NULL)
            {
                sum += right_node->left->val;
            }
            if(right_node->right != NULL)
            {
                sum += right_node->right->val;
            }
        }
        return sum;
    }
    int sumEvenGrandparentCore(TreeNode* root)
    {
        if(NULL == root)
        {
            return 0;
        }
        int sum = 0;
        int count = 0;
        if(((root->val) % 2) == 0)
        {
            sum = searchGrandson(root);
        }
        int leftSum = 0;
        int rightSum = 0;
        if(root->left != NULL)
        {
            leftSum = sumEvenGrandparentCore(root->left);
        }
        if(root->right != NULL)
        {
            rightSum = sumEvenGrandparentCore(root->right);
        }
        return sum+leftSum+rightSum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }
        return sumEvenGrandparentCore(root);
    }
};