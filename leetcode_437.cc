//437 路径总和III

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
    int checkIfHasPath(TreeNode* root,int sum,int& current)
    {
        if(NULL == root)
        {
            return 0;
        }
        current += root->val;
        int left = 0,right = 0;
        int leftCurrent = current;
        int rightCurrent = current;
        int cursum = 0;

        left += checkIfHasPath(root->left,sum,leftCurrent);
        right += checkIfHasPath(root->right,sum,rightCurrent);

        current == sum ? cursum = 1 : cursum = 0;
        /*
        if(current == sum)
        {
            return 1;
        }
        */

        //left = checkIfHasPath(root->left,sum,leftCurrent);
        //right = checkIfHasPath(root->right,sum,rightCurrent);
                
        return left+right+cursum;
    }
    int pathSumCore(TreeNode* root,int sum)
    {
        if(NULL == root)
        {
            return 0;
        }
        int current = 0;
        int cur = checkIfHasPath(root,sum,current);
        int left = pathSumCore(root->left,sum);
        int right = pathSumCore(root->right,sum);
        return left + right + cur;
    }
    int pathSum(TreeNode* root, int sum) {
        if(NULL == root)
        {
            return 0;
        }
        return pathSumCore(root,sum); 
    }
};