class Solution {
public:
    Node* connect(Node* root) {
        Node* curr=root;
        Node* dummy=new Node;
        while(curr) // 每次到这表示处理完一层
        {
            Node* tail = dummy;
            while (curr) // 遍历当前层的节点,处理下一层
            {
                if (curr->left) // 下一层
                {
                    tail->next=curr->left;
                    tail=tail->next;
                }
                if (curr->right) // 下一层
                {
                    tail->next=curr->right;
                    tail=tail->next;
                }
                curr=curr->next;
            }
            curr=dummy->next; // 指向下一层的开始,继续
            if (tail==dummy) break;
        }
        return root;
    }
};



/*
    dummy->next 指向的都是每一层的第一个元素。由于最开始tail是指向dummy 的，所以当第一次执行while中的某一个if[如果左子树不为空那就是第一个，否则就是第二个]
    时，tail 还是指向 dummy 的，从而tail 就可以改变dummy->next 的指向。 之后tail 就会改变，指向这一层的其他元素。 

    刚开始认为 "if (tail==dummy) break;" 没有什么用处，可以直接删除，但是从执行结果来看，有时候会超时。 
    测试用例: [1],不会超时
    测试用例: [1,2,3]，超时。主要的原因是，当root为1时，则将2的next指向3，但是由于2，3都没有左右子树，两个if不会执行
并且在root为1的时，dummy->next 就被设置为2，在第二层是，curr 每次执行的得到的都是 节点2，从而就陷入了死循环。
*/