题目：给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。


解法：先遍历左子树然后右子树，当遍历到一个新的深度 level，而最终结果 res 中还没有创建 level 对应的列表时，应该在 res 中新建一个列表用来保存该 level 的所有节点。

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;
        if (level >= res.size())
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        dfs(res, root->left, level + 1);
        dfs(res, root->right, level + 1);
    }
};
