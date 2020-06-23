#include <vector>
#include <iostream>

using namespace std;



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

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<TreeNode*> generateTreesCore(int start,int end)
    {
        vector<TreeNode*> ret;
        if(start > end)
        {
            //必须添加
            /*
            原因说明: 
                假设n = 2,也就是这里的end 设置为2 时，当下面的循环i = 1时，此时只有一种情况，就是2作为1的右子树。但是假设此处不将NULL 加入到ret ,
                那么在调用第一个 generateTreeCore时，start= 1,end = i -1(也就是0) ,则返回的ret 的大小为空
                接着计算右子树，start=2,end=end (也就是2),此时right_tree 的大小不为空。
                由于left_tree 的size=0,后续的for 就不执行了。
                即使左子树为空，也是可以构建二叉树的。
            */
            ret.push_back(NULL);
            return ret;
        }
        if(start == end)
        {
            TreeNode* node = new TreeNode(start);
            ret.push_back(node);
            return ret;
        }

        for(int i = start;i <= end;++i)
        {
            vector<TreeNode*> left_tree = generateTreesCore(start,i - 1);
            vector<TreeNode*> right_tree = generateTreesCore(i + 1,end);

            for(int m = 0;m < left_tree.size();++m)
            {
                for(int n = 0;n < right_tree.size();++n)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_tree[m];
                    root->right = right_tree[n];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(0 == n)
        {
            return ret;
        }
        ret = generateTreesCore(1,n);
        return ret;
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> ret;
    ret = s.generateTrees(3);


    std::cout << ret.size() << std::endl;
    for(int i = 0;i < ret.size();++i)
    {
        std::cout << ret[i]->val << " ";
    }
    std::cout << std::endl;

    return 0;
}
