/*
    654 最大二叉树
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
    int findMax(vector<int>& nums,int start,int end)
    {
        int temp = start;
        for(int i = start+1;i <= end;++i)
        {
            if(nums[temp] < nums[i])
            {
                temp = i;
            }
        }
        return temp;
    }
    TreeNode* constructMaximumBinaryTreeCore(vector<int>& nums,int start,int end)
    {
        if(start > end)
        {
            return NULL;
        }
        int rootValIdx = findMax(nums,start,end);
        TreeNode* root = new TreeNode(nums[rootValIdx]);
        if(start < rootValIdx)
        {
            root->left = constructMaximumBinaryTreeCore(nums,start,rootValIdx-1);     
        }
        if(rootValIdx < end)
        {
            root->right = constructMaximumBinaryTreeCore(nums,rootValIdx+1,end);    
        }
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(0 == nums.size())
        {
            return NULL;
        }
        return constructMaximumBinaryTreeCore(nums,0,nums.size()-1);
    }
};