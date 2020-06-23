/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string findDuplicateSubtreesCore(TreeNode* root,vector<TreeNode*>& ret,unordered_map<string,int>& mp)
    {
        if(NULL == root)
        {
            return "#";
        }
        string str = to_string(root->val) + " " + findDuplicateSubtreesCore(root->left,ret,mp) + " " + findDuplicateSubtreesCore(root->right,ret,mp);
        //这里的条件限定就是: 对于同一类的重复子树，只需要返回其中任意一棵的根节点即可。
        //比如说这里的子树 单个节点的子树 也就是有3个节点4，返回一个即可，另外的节点4是和节点2构成子树。
        if(mp[str] == 1)
        {
            ret.push_back(root);
        }
        mp[str]++;

        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ret;
        if(NULL == root)
        {
            return ret;
        }
        unordered_map<string,int> mp; 
        findDuplicateSubtreesCore(root,ret,mp);
        return ret;
    }
};