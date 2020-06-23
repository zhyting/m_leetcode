/*
    590 N叉树的后序遍历 
    给定一个 N 叉树，返回其节点值的后序遍历。
    例如，给定一个 3叉树 :

            1 
        3   2   4
      5   6
*/



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorderCore(Node* root,vector<int>& ret)
    {
        if(NULL == root)
        {
            return;
        }
        for(int i = 0;i < root->children.size();++i)
        {
            postorderCore(root->children[i],ret);
        }

        ret.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if(NULL == root)
        {
            return ret;
        }
        
        postorderCore(root,ret);
        return ret;
    }
};