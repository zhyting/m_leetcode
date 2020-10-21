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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(NULL == root)
        {
            return ret;
        }
        TreeNode* cur = root;
        TreeNode* r = NULL;
        stack<TreeNode*> stk;
        while(cur != NULL || !stk.empty())
        {
            if(cur != NULL)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                if(cur->right == NULL || cur->right == r)
                {
                    ret.push_back(cur->val);
                    stk.pop();
                    r = cur;
                    cur = NULL;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
        return ret;
    }
};