题目：给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。


//前序遍历，拉链法
class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root -> left)   return root;
        root -> left -> next = root -> right;
        Node* now = new Node;
        now = root -> left;
        while(now -> left){
            now -> right -> next = now -> next -> left;
            now = now -> right;
        }
        root -> left = connect(root -> left);
        root -> right = connect(root -> right);
        return root;
    }
};


//队列法
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q({root});
        while(!empty(q)){
            Node* tmp = new Node(-1);
            int len = q.size();
            for(int i = 0; i < len; i++) {
                tmp = tmp->next = q.front(); q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return root;
    }
};
