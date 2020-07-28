题目：给定一个二叉树，检查它是否是镜像对称的。

解法：前序遍历，使用两个指针来走，你左我右，你右我左

class Solution {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
