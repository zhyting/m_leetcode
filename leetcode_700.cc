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
    TreeNode* searchBSTCore(TreeNode* root,int val)
    {
        if(NULL == root)
        {
            return NULL;
        }
        TreeNode* has = NULL;
        if(root->val == val)
        {
            return root;
        }
        if(root->left)
        {
            has = searchBSTCore(root->left,val);
        }
        if(!has && root->right!=NULL)
        {
            has = searchBSTCore(root->right,val);
        }
        return has;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(NULL == root)
        {
            return NULL;
        }
        return searchBSTCore(root,val);
    }
};




/*
    由于是二叉搜索树，则可以使用二分查找
*/
//非递归方式
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(NULL == root)
        {
            return NULL;
        }
        TreeNode* pNext = root;
        while(pNext != NULL)
        {
            if(pNext->val == val)
            {
                return pNext;
            }
            else if(pNext->val > val)
            {
                pNext = pNext->left;
            }
            else
            {
                pNext = pNext->right;
            }
        }
        return NULL;
    }
};