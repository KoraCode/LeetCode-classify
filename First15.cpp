题目：给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。


class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        dfs(root,sum,tmp);
        return ans;
    }

    void dfs(TreeNode* root, int sum,vector<int>& tmp)
    {
        if(!root) return;

        tmp.push_back(root->val);
        if(root->val == sum && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(tmp);
        }

        dfs(root->left,sum-root->val,tmp);
        dfs(root->right,sum-root->val,tmp);

        tmp.pop_back();
    }
};
