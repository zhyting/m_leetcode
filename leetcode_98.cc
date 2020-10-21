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
    void inOrder(TreeNode* root,vector<int>& vec)
    {
        if(NULL == root)
        {
            return;
        }

        if(root->left != NULL)
        {
            inOrder(root->left,vec);
        }
        vec.push_back(root->val);
        if(root->right != NULL)
        {
            inOrder(root->right,vec);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(NULL == root || (NULL == root->left && NULL == root->right))
        {
            return true;
        }

        vector<int> vec;
        inOrder(root,vec);
        for(int i = 0;i < vec.size()-1;++i)
        {
            if(vec[i] >= vec[i+1])
            {
                return false;
            }
        }
        return true;
    }
};