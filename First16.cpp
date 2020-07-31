题目：给定一个二叉树，原地将它展开为一个单链表。


//后序遍历
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        flatten(root->left);
        flatten(root->right);
        auto p=root->left;      //p指向root的左端
        if(p==NULL)return;      //为nullptr返回
        while(p->right)p=p->right;    //整理成一条右子树
        p->right=root->right;         //然后将root的右子树插入链条p的末端
        root->right=root->left;       //再将链条p插入root的右端
        root->left=NULL;              //root左端设为null
    }
};
