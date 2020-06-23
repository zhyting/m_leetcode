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
    bool SearchPath(TreeNode* root,int sum,int cursum)
    {
        if(NULL == root)
        {
            return false;
        }
        cursum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            return sum == cursum ? true : false;
        }
        bool hasPath = false;
        hasPath = SearchPath(root->left,sum,cursum);
        if(!hasPath && root->right!=NULL)
        {
            hasPath = SearchPath(root->right,sum,cursum);    
        }
        
        return hasPath;
    }

    bool hasPathSumCore(TreeNode* root,int sum)
    {
        if(NULL == root)
        {
            return false;
        }

        bool hasPath = false;
        int current = 0;
        hasPath = SearchPath(root,sum,current);
        
        return hasPath;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL == root)
        {
            return false;
        }
        if(root->val == sum && (root->left != NULL || root->right != NULL))
        {
            return false;
        }

        return hasPathSumCore(root,sum);
    }
};