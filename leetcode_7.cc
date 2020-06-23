/*
	根据前序 中序 来重建二叉树
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
    TreeNode* buildTreeCore(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd)
    {
	    int rootKey =pre[preStart];
	    int left = 0;

	    TreeNode* root = new TreeNode;
	    root->val = rootKey;
	    root->left = NULL;
	    root->right = NULL;

	    if(preStart == preEnd)
	    {
		    if(inStart == inEnd && pre[preStart] == in[inStart])
		    {
			    return root;
		    }
	    }


	    for(int i = inStart;i <= inEnd;++i)
	    {
		    if(in[i] == rootKey)
		    {
			    break;
		    }
		    left++;
	    }

	    if(left > 0)
	    {
		    root->left = buildTreeCore(pre,preStart+1,preStart+left,in,inStart,inStart+left-1);
	    }
	
	    if(preStart+left < preEnd)
	    {
		    root->right = buildTreeCore(pre,preStart+1+left,preEnd,in,inStart+left+1,inEnd);
	    }

	    return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(0 == preorder.size() || 0 == inorder.size() || preorder.size() != inorder.size())
	    {
		    return NULL;
	    }
        return buildTreeCore(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};