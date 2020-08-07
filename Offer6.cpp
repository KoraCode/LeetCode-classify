题目：输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

解法：入栈法、递归、反转、改变链式结构

        stack<int> s;
        //入栈
        while(head){
            s.push(head->val);
            head = head->next;
        }
        //出栈
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;

        //递归
        if(head == nullptr)
            return res;
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
        
        //改变链式结构
        ListNode *pre = nullptr;
        ListNode *next = head;
        ListNode *cur = head;
        while(cur){
            next = cur->next;//保存当前结点的下一个节点
            cur->next = pre;//当前结点指向前一个节点，反向改变指针
            pre = cur;//更新前一个节点
            cur = next;//更新当前结点
        }
        while(pre){//上一个while循环结束后，pre指向新的链表头
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
