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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        vector<int> temp;
        bool flag = false;
        if(NULL == root)
        {
            return ret;
        }
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;

        stk1.push(root);
        while(!stk1.empty() || !stk2.empty())
        {
            if(!flag)
            {
                //stk1 出栈        
                while(!stk1.empty())
                {
                    TreeNode* top = stk1.top();
                    stk1.pop();
                    temp.push_back(top->val);
                    if(top->left)
                        stk2.push(top->left);
                    if(top->right)
                        stk2.push(top->right);
                }   
                flag = true;   
            }
            else
            {
                //stk2 出栈
                while(!stk2.empty())
                {
                    TreeNode* top = stk2.top();
                    stk2.pop();
                    temp.push_back(top->val);
                    if(top->right)
                        stk1.push(top->right);
                    if(top->left)
                        stk1.push(top->left);
                }
                flag = false;
            }
            ret.push_back(temp);
            temp.clear();
        }
        
        return ret;
    }
};