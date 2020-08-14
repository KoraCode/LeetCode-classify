题目：给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。

//递归
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return head;
        if(head->val == val) return head->next;
        //递归删除
        head->next = deleteNode(head->next,val);
        return head;
    }
};

//循序遍历
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return head;
        if(head->val == val) return head->next;
        ListNode* p=head;
        while(p->next && p->next->val != val){
            p=p->next;
        }
        if(p->next && p->next->val == val)  p->next = p->next->next;
        return head;
    }
};
