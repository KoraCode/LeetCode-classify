题目：给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

解法：层序遍历可以每次输出每层的back()元素；先序遍历，先右子树再左子树，输出树深度的第一个节点

//层序遍历
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root, 0);
        vector<int> ans;
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i].back());
        }
        return ans;
    }
    void dfs(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;
        if (level >= res.size())
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        dfs(res, root->left, level + 1);
        dfs(res, root->right, level + 1);
    }
}

//先序遍历
class Solution {
public:
    vector<int> ans;

    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }

    void dfs(TreeNode* root,int level)
    {
        if(!root) return;

        if(level==ans.size())
        {
            ans.push_back(root->val);
        }

        dfs(root->right,level+1);
        dfs(root->left,level+1);
    }
};
