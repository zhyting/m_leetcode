/*
	我自己提交的代码，写的不是很简洁
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head || NULL == head->next)
        {
            return head;
        }

        ListNode* p1 = head,*p2 = head->next;
        ListNode* prev = NULL;
        ListNode* newHead = p2;
        while(p2 != NULL)
        {
            p1->next = p2->next;
            p2->next = p1;

            if(prev != NULL)
            {
                prev->next = p2;
            }
            prev = p1;
            p1 = p1->next;
            if(NULL == p1)
            {
                break;
            }
            p2 = p1->next;
        }
        return newHead;
    }
};







/*
	以下两个是他人所提交的代码。
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* first=new ListNode(0); //加一个哨兵节点
        first->next=head;
        ListNode*  =first; //p1为需交换的节点前面一个节点
        ListNode* p2; //将节点p2与p2->next交换。这样不需要额外记录交换节点之前的节点。
        while(p1->next!=NULL&&p1->next->next!=NULL)
        {
            p2=p1->next;
            p1->next=p2->next;
            p2->next=p2->next->next;
            p1->next->next=p2;
            p1=p2; //更新p1
        }
        return first->next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        //新建一个空结点，用来指向头节点
        ListNode* p = new ListNode(0);
        p->next = head;
        //新建和p相同一个curr节点，两个相同的节点一个是当前做改变的节点，一个是保持不动用来返回的节点
        ListNode* curr = p;
        //循环条件为当前节点为NULL或当前的下一个节点为NULL，分别对应偶数和奇数个节点的终止标志
        while(head != NULL && head->next != NULL)
        {
            //为了清晰明了，我们新建两个节点，一节点和二节点
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;

            ///把一和二进行交换，并连接前后
            //当前curr节点指向二节点
            curr->next = secondNode;
            //一节点指向二节点此时的下一节点
            firstNode->next = secondNode->next;
            //二节点指向一节点，即交换位置成功
            secondNode->next = firstNode;

            //由于每次循环curr节点都指向每次循环的一节点，所以要再次把curr节点指向一节点
            curr = firstNode;
            //每次移动都是由head节点来赋值操作，所以head应向右移动两格，即新循环的一节点
            head = firstNode->next;
        }
        //返回p的下一个节点即对应整个操作后的链表
        return p->next;

    }
};

