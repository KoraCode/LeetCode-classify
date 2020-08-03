题目：给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。


class Solution {
public:
    int sum=0;

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root,0);
        return sum;
    }

    void dfs(TreeNode* root,int temp)
    {
        if(!(root->left) && !(root->right))     //判断是否是叶子节点
        {
            temp=temp*10+root->val;
            sum+=temp;
            return;
        }

        if(root->left) dfs(root->left,temp*10+root->val);
        if(root->right) dfs(root->right,temp*10+root->val);
    }
};
