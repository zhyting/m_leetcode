/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
示例一
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。

示例二
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
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
    void searchHasComm(TreeNode* root,TreeNode* p,TreeNode* q,bool& hasP,bool& hasQ)
    {
        if(NULL == root)
        {
            return ;
        }
        if(root->val == p->val)
        {
            hasP = true;
        }
        if(root->val == q->val)
        {
            hasQ = true;
        }

        if(true == hasP && true == hasQ)
        {
            return;
        }
        searchHasComm(root->left,p,q,hasP,hasQ);
        searchHasComm(root->right,p,q,hasP,hasQ);
    }
    TreeNode* lowestCommonAncestorCore(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(NULL == root)
        {
            return NULL;
        }
        TreeNode* hasComm = NULL;
        if(root->left)
        {
            hasComm = lowestCommonAncestorCore(root->left,p,q);
        }
        if(!hasComm && root->right)
        {
            hasComm = lowestCommonAncestorCore(root->right,p,q);
        }
        bool hasP = false,hasQ = false;
        if(!hasComm)
        {
            searchHasComm(root,p,q,hasP,hasQ);
            if(true == hasP && true == hasQ)
            {
                return root;
            }    
        }

        return hasComm;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(NULL == root || NULL == p || NULL == q)
        {
            return NULL;
        }
        return lowestCommonAncestorCore(root,p,q);
    }
};