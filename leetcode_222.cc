/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//可以立即成一种暴力解法
class Solution {
public:
    int countNodesCore(TreeNode* root)
    {
        if(NULL == root)
        {
            return 0;
        }
        int left = 0;
        int right = 0;
        if(root->left != NULL)
        {
            left = countNodesCore(root->left);
        }
        if(root->right != NULL)
        {
            right = countNodesCore(root->right);
        }
        return left+right+1;
    }
    int countNodes(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }
        return countNodesCore(root);
    }
};





//其他人所给出的第一种做法
class Solution {
    public int countNodes(TreeNode root) {
        /**
        完全二叉树的高度可以直接通过不断地访问左子树就可以获取
        判断左右子树的高度: 
        如果相等说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)
        如果不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中)
        **/
        if (root==null) return 0;
        int ld = getDepth(root.left);
        int rd = getDepth(root.right);
        if(ld == rd) 
            return (1 << ld) + countNodes(root.right); // 1(根节点) + (1 << ld)-1(左完全左子树节点数) + 右子树节点数量
        else 
            return (1 << rd) + countNodes(root.left);  // 1(根节点) + (1 << rd)-1(右完全右子树节点数) + 左子树节点数量
        
    }

    private int getDepth(TreeNode r) {
        int depth = 0;
        while(r != null) {
            depth++;
            r = r.left;
        }
        return depth;
    }
}