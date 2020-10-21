//中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
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
                stk.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};



//前序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur != NULL || !stk.empty())
        {
            if(cur != NULL)
            {
                ret.push_back(cur->val);
                stk.push(cur);                
                cur = cur->left;
            }
            else 
            {
                cur = stk.top();
                stk.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};




//后序遍历
