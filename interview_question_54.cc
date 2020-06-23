/*
    面试题54 二叉搜索树的第k大节点

    给定一棵二叉搜索树，请找出其中第k大的节点。
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
    void inOrder(TreeNode* root,vector<int>& vec)
    {
        if(NULL == root)
        {
            return ;
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
    int kthLargest(TreeNode* root, int k) {
        if(NULL == root && k < 0)
        {
            return 0;
        }

        vector<int> inorder;
        inOrder(root,inorder);
        if(k > inorder.size())
        {
            return 0;
        }
        return inorder[inorder.size()-k];
    }
};


/*
    解法二: 主要是对中序遍历的修改，由左中右 ---> 右中左的方式
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
    int kthLargestCore(TreeNode* root,int& k)
    {
        if(NULL == root)
        {
            return 0;
        }
        int ret = -1;
        if(k > 0 && root->right != NULL)
        {
            ret = kthLargestCore(root->right,k);
        }
        
        if(k > 0)
        {
            if(1 == k)
            {
                k--;
                return root->val;
            }
            k--;
        }

        if(k > 0 && root->left != NULL)
        {
            ret = kthLargestCore(root->left,k);
        }
        return ret;
    }
    int kthLargest(TreeNode* root, int k) {
        if(NULL == k || k < 0)
        {
            return 0;
        }
        return kthLargestCore(root,k);
    }
};




