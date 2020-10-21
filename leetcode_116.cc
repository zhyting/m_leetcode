/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelTraverse(Node* root,vector<vector<Node*> >& vec)
    {
        if(NULL == root)
        {
            return;
        }
        int current = 1;
        int next = 0;
        queue<Node*> que;
        vector<Node*> temp;

        que.push(root);
        while(!que.empty())
        {
            Node* front = que.front();
            que.pop();
            temp.push_back(front);
            current--;

            if(front->left != NULL)
            {
                que.push(front->left);
                next++;
            }
            if(front->right != NULL)
            {
                que.push(front->right);
                next++;
            }
            if(0 == current)
            {
                current = next;
                next = 0;
                vec.push_back(temp);
                temp.clear();
            }
        }
    }
    Node* connect(Node* root) {
        if(NULL == root)
        {
            return NULL;
        }
        vector<vector<Node*> > vec;
        levelTraverse(root,vec);
        for(int i = 0;i < vec.size();++i)
        {
            for(int j = 0;j < vec[i].size();++j)
            {
                int next = j+1;
                if(next < vec[i].size())
                {
                    (vec[i][j])->next = vec[i][next];
                }
                else 
                {
                    (vec[i][j])->next = NULL;
                }
            }
        }
        return root;
    }
};






class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};






